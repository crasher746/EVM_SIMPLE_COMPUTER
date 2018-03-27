#include "header.h"
arrCommand[N_COM] = {10, 11, 20, 21, 30, 31, 32, 33, 40, 41, 42, 43, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76};
int sc_memoryInit() {
	int i;
	for (i = 0; i < N_MEM; i++)
		arrMemory[i] = 0;
	//printf(">>>Success MEMORY INIT\n");
	return 0;
}
int sc_memorySet(int address, int value) {
	if (address < N_MEM) {
		arrMemory[address] = value;
		sc_regSet(OVERFLOW, 0);
		//printf(">>>Success MEMORY SET\n");
		return 0;
	}
	else {
		sc_regSet(OVERFLOW, 1);
		return -1;
	}
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
	if (address < N_MEM) {
		*value = arrMemory[address];
		sc_regSet(OVERFLOW, 0);
		//printf(">>>Success MEMORY GET\n");
		return 0;
	}
	else {
		sc_regSet(OVERFLOW, 1);	
		return -1;
	}
}
int sc_memorySave(char *filename) {
	FILE *output;
	output = fopen(filename, "wb");
	fwrite(arrMemory, N_MEM, sizeof(int), output);
	//printf(">>>Success SAVE\n");
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
		//printf("Couldn't open file: %s\n", filename);
		return -1;
	}
	//printf(">>>Success LOAD\n");
	fclose(input);
	return 0;
}
int sc_regInit() {
	reg = 0;//VAR storiable flags
	//printf(">>>Success REG INIT\n");
	return 0;
}
int sc_regSet(int digNum, int value) {
	if ((value > 1) || (value < 0) || (digNum < 1) || (digNum > 2)) 
		return -1;
	if (value == 1) { 
		reg = reg | (1 << (digNum - 1)); //FLAG -> 1
		//printf("OVERFLOW %d", value);
	}
	else {
		reg = reg & (~(1 << (digNum - 1)));//FLAG -> 0
	}
	return 0;
}
int sc_regGet(int digNum, int *value) {
	if ((digNum < 1) || (digNum > 2)) return -1;
	else {
		*value = (reg >> (digNum - 1)) & 0x1; //to catch value of FLAG
		//printf(">>>Success REG GET\n");
		return 0;
	}
}

int sc_commandEncode (int command, int operand, int *value) {
	int i;	
/*	if ((command < 10) || (command > 75) || (operand < 0) || (operand > 127)) {
		sc_regSet(WRONGCOMMAND, 1)*/
	for (i = 0; i < N_COM; i++) {
		if (command == arrCommand[i]) {
				*value = (command << 8) | (operand & ENCODE);
				sc_regSet(WRONGCOMMAND, 0);				
				//printf(">>>Success ENCODE\n");
				return 0;
			}		
	}
	sc_regSet(WRONGCOMMAND, 1);
	return -1; 		
}


int sc_commandDecode (int value, int *command, int *operand) {
	if ((value == NULL) || (command == NULL) || (operand == NULL)) {
		sc_regSet(WRONGCOMMAND, 1);
		//printf(">>>NOT DECODE\n");
		return -1;	
	}
	*operand = value & ENCODE;
	*command = value >> 8;
	//printf(">>>Success DECODE\n");
	return 0;
	
}

