#include "header.h"
#include "myTerm.h"

void showMenu(int x, int y) {
	mt_gotoXY(x, y);
	printf("[1]LAB 3");
	mt_gotoXY(x + 1, y);
	printf("[2]LAB 2");
	mt_gotoXY(x + 2, y);
	printf("[3]EXITE");
	mt_gotoXY(x + 3, y);
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
					printf("0x%x ", arrMemory[i]);
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
				command = 77; operand = 3;
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
					printf("0x%x ", arrMemory[i]);
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
				return EXIT_SUCCESS;
			break;


		}
	}


	return 0;
}
