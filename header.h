#ifndef HEADER_H
#define HEADER_H
#define _CRT_SECURE_NO_WARNINGS

#define N_MEM 100
#define N_COM 38

#define OVERFLOW 1 
#define WRONGCOMMAND 2
#define ZEROFLAG 3
#define IGNOREFLAG 4
#define ISRUN 5
#define LIMIT 6  

#define ENCODE 127
//#define clear() printf('\nE033ff')

#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

int memoryPointer, operand, command, accumValue, opCounter; 
int flag_key, flag_ign;
int arrMemory[N_MEM];
int reg;
int arrCommand[N_COM];

int sc_memoryInit();
int sc_memorySet(int, int);
int sc_memoryGet(int, int*);

int sc_memorySave(char*);
int sc_memoryLoad(char*);

int sc_regInit();
int sc_regSet(int, int);
int sc_regGet(int, int*);

int sc_commandEncode(int, int, int*);
int sc_commandDecode(int, int*, int*);
int sc_findAdress(int);

#endif
