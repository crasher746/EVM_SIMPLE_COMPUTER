#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include "header.h"
#include "myTerm.h"
#include "myBigChars.h"
#include "myDisplay.h"

int command, operand, value;

void displayMemory() {
	int i, k = 2;
	bc_box(1, 1, 12, 62);
	mt_gotoXY(1, 29);
	mt_setfgColor(PURPLE);
	printf("MEMORY");
	mt_setfgColor(DEFAULT);
	mt_gotoXY(2,2);
	for (i = 1; i <= N_MEM; i++) {
		sc_memoryGet(i - 1, &value);
		sc_commandDecode(value, &command, &operand);
		if (memoryPointer == i) {mt_setbgColor(PURPLE); printf("+%04X", arrMemory[i]); mt_setbgColor(DEFAULT); printf(" ");}
		else printf("+%04X ", arrMemory[i]);
		
		if (i % 10 == 0 && i != 0) {k++; mt_gotoXY(k, 2);}				
	}
	mt_gotoXY(23, 51);
}

void displayAccumulator() {
	bc_box(1, 63, 3, 18);
	mt_gotoXY(1, 67);
	mt_setfgColor(PURPLE);
	printf("ACCUMULATOR");
	mt_setfgColor(DEFAULT);
	mt_gotoXY(2, 69);

	if (accumValue >= 0) {printf("+%04X", accumValue); mt_gotoXY(2, 69);}
	else {printf("-%04X", (-1) * accumValue); mt_gotoXY(2, 69);}

	mt_gotoXY(23, 51);
}

void displayCounter() {
	bc_box (4, 63, 3, 18);
	mt_gotoXY(4, 69);
	mt_setfgColor(PURPLE);
	printf("COUNTER");
	mt_setfgColor(DEFAULT);
	opCounter = memoryPointer;
	mt_gotoXY(5, 69);
	printf("+%04X", opCounter);
	mt_gotoXY(23, 51);
}

void displayOperation() {
	//int com = 0, oper = 0, val = 0;
	bc_box (7, 63, 3, 18);
	mt_gotoXY(7, 68);
	mt_setfgColor(PURPLE);
	printf("OPERATION");
	mt_setfgColor(DEFAULT);
	mt_gotoXY(8, 69);
	sc_memoryGet(memoryPointer, &value);
	sc_commandDecode(value, &command, &operand);
			
	printf("+%02d : %02X", command, operand);
	mt_gotoXY(23, 51);
}

void displayFlags() {
	bc_box (10, 63, 3, 18);
	mt_gotoXY(10, 70);
	mt_setfgColor(PURPLE);
	printf("FLAGS");
	mt_setfgColor(DEFAULT);
	mt_gotoXY(11, 69);
	int flagValue = 0;

	sc_regGet(WRONGCOMMAND, &flagValue); if (flagValue == 1) printf("WRNGCOM"); else printf("");
	mt_gotoXY(11, 69);
	sc_regGet(ISRUN, &flagValue); if (flagValue == 1) printf("ISRUN"); else printf("");
	mt_gotoXY(11, 67);
	sc_regGet(OVERFLOW, &flagValue); if (flagValue == 1) printf("OVRKW"); else printf("");
	mt_gotoXY(11, 67);
	sc_regGet(ZEROFLAG, &flagValue); if (flagValue == 1) printf("ZERO"); else printf("");
    
	mt_gotoXY(23, 51);
}

void displayBigChar() {
	mt_setbgColor(DEFAULT);
	mt_setfgColor(DEFAULT);
	int y = 2;
	bc_box(13, 1, 13, 46);
	mt_gotoXY(13, 22);
	mt_setfgColor(PURPLE);
	printf("CHAR");
	mt_setfgColor(DEFAULT);
	BIG[0] = 0;
	BIG[1] = 0;
	char buffer[20];
	sc_memoryGet(memoryPointer, &value);
	sprintf(buffer, "+%04X", value);
	int i;
	for (i = 0; i < 5; i++) {
		chooseBig(BIG, buffer[i]);
		bc_printBigChar(BIG, 15, y, PURPLE, DEFAULT);
		y += 9;
	}
	mt_setbgColor(DEFAULT);
	mt_setfgColor(DEFAULT);
	mt_gotoXY(23, 51);	
}

void displayMenu() {
	mt_setbgColor(DEFAULT);
	mt_setfgColor(DEFAULT);
	mt_gotoXY(22, 47);
	bc_box (22, 47, 1, 34);
	bc_box (13, 47, 13, 34);
	mt_gotoXY(13, 62);
	mt_setfgColor(PURPLE);
	printf("MENU");
	mt_setfgColor(DEFAULT);
	mt_gotoXY(15, 50);
	mt_setfgColor(PURPLE);
	printf("E");
	mt_setfgColor(DEFAULT);
	printf(" - EDIT");
	mt_gotoXY(16, 50);
	mt_setfgColor(PURPLE);
	printf("L");
	mt_setfgColor(DEFAULT);
	printf(" - LOAD");
 	mt_gotoXY(17, 50);
	mt_setfgColor(PURPLE);
 	printf("S");
	mt_setfgColor(DEFAULT);
	printf(" - SAVE");
 	mt_gotoXY(18, 50);
	mt_setfgColor(PURPLE);
 	printf("R");
	mt_setfgColor(DEFAULT);
	printf(" - RUN");
 	mt_gotoXY(19, 50);
	mt_setfgColor(PURPLE);
 	printf("I");
	mt_setfgColor(DEFAULT);
	printf(" - RESET");
 	mt_gotoXY(20, 50);
	mt_setfgColor(PURPLE);
 	printf("F5");
	mt_setfgColor(DEFAULT);
	printf(" - ACCUMULATOR");
 	mt_gotoXY(21, 50);
	mt_setfgColor(PURPLE);
 	printf("F6");
	mt_setfgColor(DEFAULT);
	printf(" - COUNTER");
	mt_gotoXY(23, 49);
	mt_setfgColor(PURPLE);
	printf(":");
	mt_setfgColor(DEFAULT);
	mt_gotoXY(23, 51);
}

void showMenu(int x, int y) {
	mt_setbgColor(PURPLE);
	mt_setfgColor(WHITE);
	bc_box(7, 25, 10, 33);
	mt_setbgColor(DEFAULT);
	mt_gotoXY(x, y);
	printf("[1] START");
	mt_gotoXY(x + 2, y);
	printf("[2] QUIT");
	mt_gotoXY(x + 6, y + 2);
	printf(">>>");
}

void showFull() {
	mt_clrscr();
	displayMemory();
	displayAccumulator();
	displayCounter();
	displayOperation();
	displayFlags();
	displayMenu();
	displayBigChar();
	mt_gotoXY(23, 51);
}

void reset() {
	sc_memoryInit();
	sc_regInit();
	showFull();
}
