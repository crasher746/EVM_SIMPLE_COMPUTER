#include "header.h"
#include "myTerm.h"
#include "myBigChars.h"
#include "myDisplay.h"

int main() {
	int value = 0, i = 0, count = 1, memoryFlag = 0, commandFlag = 0;
	int command = 0, operand = 0, result = 0, helpme;
	char* name = "out.dat";
	int choice = 0;
	while (1) {
		mt_clrscr();
		mt_gotoXY(1, 1);		
		showMenu(8, 37);
		mt_setbgColor(DEFAULT);
		mt_setfgColor(DEFAULT);
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				mt_clrscr();
				mt_gotoXY(1, 1);				
				sc_regInit();
				sc_memoryInit();
				arrMemory[0] = 0x3D07;
								
				
				displayMemory();
				displayAccumulator();
				displayCounter();
				displayOperation();
				displayFlags();
				displayBigChar();
				displayMenu();
				
				/*int i, k = 2, y =2;
				bc_box(1, 1, 12, 62);
				mt_gotoXY(1, 29);
				printf("MEMORY");
				mt_gotoXY(2,2);
				for (i = 1; i <= N_MEM; i++) {
					if (arrMemory[i - 1] != 0) {mt_setbgColor(PURPLE); printf("+%04X", arrMemory[i - 1]); mt_setbgColor(DEFAULT); printf(" ");}
					else {
						printf("+%04X ", arrMemory[i - 1]);
					}
					if (i % 10 == 0 && i != 0) {k++; mt_gotoXY(k, 2);}				
				}

				bc_box(13, 1, 18, 46);
				mt_gotoXY(13, 22);
				printf("CHAR");
				BIG[0] = 0;
				BIG[1] = 0;
				char buffer[20];
				sprintf(buffer, "+%04X", result);
				for (i = 0; i < 5; i++) {
					chooseBig(BIG, buffer[i]);
					bc_printBigChar(BIG, 15, y, DEFAULT, PURPLE);
					y += 9;
					
				}
				mt_setbgColor(DEFAULT);
				mt_setfgColor(DEFAULT);

				bc_box(1, 63, 3, 18);
				mt_gotoXY(1, 67);
				printf("ACCUMULATOR");
				mt_gotoXY(2, 69);
				printf("+%04X", result);

				bc_box (4, 63, 3, 18);
				mt_gotoXY(4, 69);
				printf("COUNTER");
				mt_gotoXY(5, 69);
				printf("+0000");

				bc_box (7, 63, 3, 18);
				mt_gotoXY(7, 68);
				printf("OPERATION");
				mt_gotoXY(8, 71);
				printf("%d", command);

				bc_box (10, 63, 3, 18);
				mt_gotoXY(10, 70);
				printf("FLAGS");
				mt_gotoXY(14, 47);
				sc_regGet(OVERFLOW, &memoryFlag);
				mt_gotoXY(15, 47);
				sc_regGet(WRONGCOMMAND, &commandFlag);
				mt_gotoXY(11, 64);
				if ((memoryFlag == 1) || (commandFlag == 1)) {
					mt_setfgColor(DARK_BLUE);					
					printf("OVFLW: %d CMND: %d", memoryFlag, commandFlag);
					mt_setfgColor(PURPLE);
				}
				else {mt_gotoXY(11, 71); printf("0");}
				bc_box (13, 47, 18, 34);
				mt_gotoXY(13, 62);
				printf("KEYS");
				mt_gotoXY(16, 48);*/
				scanf("%d", &helpme);

			break;
			case 2:
				mt_setbgColor(DEFAULT);
				mt_setfgColor(DEFAULT);
				mt_clrscr();
				return EXIT_SUCCESS;
			break;


		}
	}


	return 0;
}
