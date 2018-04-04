#include "header.h"
int sc_memoryInit() {
	int i;
	for (i = 0; i < N_MEM; i++)
		arrMemory[i] = 0;
	
	int tempArr[] = {10, 11, 20, 21, 30, 31, 32, 33, 40, 41, 42, 43, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76};
	memcpy(arrCommand, tempArr, (sizeof(tempArr)));

	accumValue = 0;
	opCounter = 0;
	command = 0;
	operand = 0;
	memoryPointer = 0;

	return 0;
}
int sc_memorySet(int address, int value) {
	if (address < 0 || address > N_MEM) {
		sc_regSet(OVERFLOW, 1);
		return -1;
	}
	arrMemory[address] = value;
	return 0;
}
int sc_findAdress(int command) {
	int i = 0;
	if (command < 10 || command > 76) return -1;
	while ((i < N_MEM) && (arrMemory[i] != 0)){
		i++;
	}
	return ((i == N_MEM) ? -1 : i); 
}
int sc_memoryGet(int address, int *value) {
	if (address < 0 || address > N_MEM) {
		
		sc_regSet(OVERFLOW, 1);

		return -1;
	}
	*value = arrMemory[address];
	return 0;
}
int sc_memorySave(char *filename) {
	FILE *output;
	output = fopen(filename, "wb");
	fwrite(arrMemory, N_MEM, sizeof(int), output);
	fclose(output);
	return 0;
}
int sc_memoryLoad(char *filename) {
	FILE *input;
	input = fopen(filename, "rb");
	if (input != NULL) {
		fread(arrMemory, N_MEM, sizeof(int), input);
	}
	else {
		return -1;
	}
	fclose(input);
	return 0;
}
int sc_regInit() {
	reg = 0;//VAR storiable flags
	return 0;
}
int sc_regSet(int digNum, int value) {
	if ((value > 1) || (value < 0) || (digNum < 1) || (digNum > 6)) 
		return -1;
	if (value == 1) { 
		reg = reg | (1 << (digNum - 1)); //FLAG -> 1
	}
	else {
		reg = reg & (~(1 << (digNum - 1)));//FLAG -> 0
	}
	return 0;
}
int sc_regGet(int digNum, int *value) {
	if ((digNum < 1) || (digNum > 6)) return -1;
	else {
		*value = (reg >> (digNum - 1)) & 0x1; //to catch value of FLAG
		return 0;
	}
}

int sc_commandEncode (int command, int operand, int *value) {
	int i;	
	for (i = 0; i < N_COM; i++) {
		if (command == arrCommand[i]) {
				*value = (command << 8) | (operand & ENCODE);
				sc_regSet(WRONGCOMMAND, 0);				
				return 0;
			}		
	}
	sc_regSet(WRONGCOMMAND, 1);
	return -1; 		
}


int sc_commandDecode (int value, int *command, int *operand) {
	if (!value  || value >> 16 || !command || !operand) {
		sc_regSet(WRONGCOMMAND, 1);

		return -1;	
	}
	*operand = value & ENCODE;
	*command = value >> 8;
	return 0;
	
}

