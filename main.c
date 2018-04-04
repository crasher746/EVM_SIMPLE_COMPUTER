#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>

#include "header.h"
#include "myTerm.h"
#include "myBigChars.h"
#include "myDisplay.h"
#include "myReadkey.h"
#include "input.h"

int main() {
	int value = 0, i = 0, count = 1, memoryFlag = 0, commandFlag = 0;
	int command = 0, operand = 0, result = 0, helpme;
	char* name = "out.dat";
	int choice = 0;

	enum KEY key = KEY_BLANK;
	flag_key = 0;
	flag_ign = 0;
	accumValue = 0;
	opCounter = 0;

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
				sc_memoryInit();
				sc_regInit();
				termInit();
				
				showFull();

				while (key != KEY_QUIT) {
					rk_readKey(&key);
					

					if (key == KEY_STEP) {
						sc_regSet(ISRUN, 0);
						flag_key = 0;
					}
					if (!flag_key) {
						if (key == KEY_RUN) {
							sc_regSet(ISRUN, 1);
							sc_regSet(IGNOREFLAG, 0);						
						}
						sc_regGet(ISRUN, &flag_key);
						
						if (key == KEY_RIGHT) if (memoryPointer < 99) ++memoryPointer;
						if (key == KEY_LEFT) if (memoryPointer >  0) --memoryPointer;
						if (key == KEY_UP) if (memoryPointer - 10 >=  0) memoryPointer -= 10;
						if (key == KEY_DOWN) if (memoryPointer + 10 < 100) memoryPointer += 10;

						if (key == KEY_F5) inputAccum();
						if (key == KEY_F6) inputCounter();
						if (key == KEY_EDIT) inputMemory();

						if (key == KEY_LOAD) sc_memoryLoad("out.dat");
						if (key == KEY_SAVE) sc_memorySave("out.dat");

						if (key == KEY_RESET) {
							sc_memoryInit();
							sc_regInit();
							showFull();
						}

						showFull();
					}
				}
				
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
				mt_gotoXY(16, 48);
				scanf("%d", &helpme);*/

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
