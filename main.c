#include "header.h"
#include "myTerm.h"
#include "myBigChars.h"
void showMenu(int x, int y) {
	mt_gotoXY(x, y);
	printf("[1]LAB 3");
	mt_gotoXY(x + 1, y);
	printf("[2]LAB 2");
	mt_gotoXY(x + 2, y);
	printf("[3]LAB 4");
	mt_gotoXY(x + 3, y);
	printf("[4]EXITE");
	mt_gotoXY(x + 4, y);
	printf(">>>");
}

int main() {
	int value = 0, i = 0, count = 1, memoryFlag = 0, commandFlag = 0;
	int command = 0, operand = 0, result = 0, helpme;
	char* name = "out.dat";
	int choice = 0;
	while (1) {
		mt_clrscr();
		mt_gotoXY(1, 1);		
		showMenu(7, 33);
		mt_setbgColor(WHITE);
		mt_setfgColor(PURPLE);
		scanf("%d", &choice);
		switch (choice) {
			case 1:
			{
				mt_clrscr();
				mt_gotoXY(5, 10);
				mt_setbgColor(RED);
				mt_setfgColor(GREEN);
				printf("GRIGORIY");
				mt_gotoXY(6, 8);
				mt_setbgColor(WHITE);
				mt_setfgColor(DARK_BLUE);
				printf("IP - 614\n");
				scanf("%d", &helpme);
			}			
			break;
			case 2:
			{
				mt_clrscr();
				mt_gotoXY(1, 1);
				mt_setbgColor(PURPLE);
				mt_setfgColor(WHITE);
				printf("MEMORY ARRAY:\n");
				for (i = 0; i < N_MEM; i++) {
					mt_setbgColor(WHITE);
					mt_setfgColor(PURPLE);
					printf("+%04X ", arrMemory[i]);
					if (count % 10 == 0) printf("\n");
					count++;
				}
				printf("\n");
				sc_regGet (OVERFLOW, &memoryFlag);
				sc_regGet (WRONGCOMMAND, &commandFlag);
				mt_setbgColor(PURPLE);
				mt_setfgColor(WHITE);
				printf("\nFLAGS: OVERFLOW: %d OUTOFMEMORY: %d\n", memoryFlag, commandFlag);
				printf(">BEFORE ENCODE / DECODE< COMMAND: %d OPERAND: %d VALUE: %d\n", command, operand, result);
				command = 61; operand = 3;/////!!!!!//////
				printf(">DATA INPUT< COMMAND: %d OPERAND: %d\n", command, operand);
				mt_setbgColor(WHITE);
				mt_setfgColor(PURPLE);
				printf("\n");
				sc_commandEncode(command, operand, &result);
				sc_regGet(OVERFLOW, &memoryFlag);
				sc_regGet(WRONGCOMMAND, &commandFlag);
				mt_setbgColor(PURPLE);
				mt_setfgColor(WHITE);
				printf("\nFLAGS: OVERFLOW %d WRONGCOMMAND %d\n", memoryFlag, commandFlag);
				printf(">AFTER ENCODE< VALUE: %X", result);
				mt_setbgColor(WHITE);
				mt_setfgColor(PURPLE);
				printf("\n\n");
				sc_memorySet(sc_findAdress(command), result);
				sc_commandDecode(result, &command, &operand);
				sc_regGet(OVERFLOW, &memoryFlag);
				sc_regGet(WRONGCOMMAND, &commandFlag);
				mt_setbgColor(PURPLE);
				mt_setfgColor(WHITE);
				printf("\nFLAGS: OVERFLOW %d WRONGCOMMAND %d\n", memoryFlag, commandFlag);
				printf(">AFTER DECODE< COMMAND: %d OPERAND: %d", command, operand);
				mt_setbgColor(WHITE);
				mt_setfgColor(PURPLE);
				printf("\n\n");
				//sc_memorySet(sc_findAdress(command), command);
				printf("\n");
				mt_setbgColor(PURPLE);
				mt_setfgColor(WHITE);
				printf("MEMORY ARRAY:");
				mt_setbgColor(WHITE);
				printf("\n\n");
				for (i = 0; i < N_MEM; i++) {
					mt_setfgColor(PURPLE);
					printf("+%04X ", arrMemory[i]);
					if (count % 10 == 0) printf("\n");
					count++;
				}
				printf("\n");
				sc_memorySave("out.dat");
				sc_memoryLoad("out.dat");
				scanf("%d", &helpme);			
			}
			break;
			case 3:
				mt_clrscr();
				int i, k = 2, y =2;
				bc_box(1, 1, 12, 62);
				mt_gotoXY(1, 29);
				printf("MEMORY");
				mt_gotoXY(2,2);
				for (i = 1; i <= N_MEM; i++) {
					if (arrMemory[i - 1] != 0) {mt_setbgColor(DARK_BLUE); printf("+%04X", arrMemory[i - 1]); mt_setbgColor(WHITE); printf(" ");}
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
				
				/*bc_setBigCharPos(BIG, 0, 1, 1);
				bc_setBigCharPos(BIG, 0, 2, 1);
				bc_setBigCharPos(BIG, 0, 3, 1);
				bc_setBigCharPos(BIG, 0, 4, 1);
				bc_setBigCharPos(BIG, 0, 5, 1);
				bc_setBigCharPos(BIG, 0, 6, 1);
				bc_setBigCharPos(BIG, 1, 1, 1);
				bc_setBigCharPos(BIG, 1, 6, 1);
				bc_setBigCharPos(BIG, 2, 1, 1);
				bc_setBigCharPos(BIG, 2, 6, 1);
				bc_setBigCharPos(BIG, 3, 1, 1);
				bc_setBigCharPos(BIG, 3, 6, 1);
				bc_setBigCharPos(BIG, 4, 1, 1);
				bc_setBigCharPos(BIG, 4, 6, 1);
				bc_setBigCharPos(BIG, 5, 1, 1);
				bc_setBigCharPos(BIG, 5, 6, 1);
				bc_setBigCharPos(BIG, 6, 1, 1);
				bc_setBigCharPos(BIG, 6, 6, 1);
				bc_setBigCharPos(BIG, 7, 1, 1);
				bc_setBigCharPos(BIG, 7, 2, 1);
				bc_setBigCharPos(BIG, 7, 3, 1);
				bc_setBigCharPos(BIG, 7, 4, 1);
				bc_setBigCharPos(BIG, 7, 5, 1);
				bc_setBigCharPos(BIG, 7, 6, 1);			
				mt_gotoXY(16, 48);
				printf(" %d %d", BIG[0], BIG[1]);			
				bc_printBigChar(BIG, 15, y, PURPLE, WHITE);*/

				//chooseBig(BIG, 'F');
				//bc_printBigChar(BIG, 15, y, PURPLE, WHITE);
				sprintf(buffer, "+%04X", result);
				for (i = 0; i < 5; i++) {
					chooseBig(BIG, buffer[i]);
					bc_printBigChar(BIG, 15, y, PURPLE, WHITE);
					y += 9;
					
				}
								
				//mt_gotoXY();

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
				scanf("%d", &helpme);

			break;
			case 4:
				mt_setbgColor(DEFAULT);
				mt_setfgColor(DEFAULT);
				mt_clrscr();
				return EXIT_SUCCESS;
			break;


		}
	}


	return 0;
}
