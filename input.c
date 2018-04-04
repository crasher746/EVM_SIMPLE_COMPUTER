#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
 
#include "header.h"
#include "myReadkey.h"
#include "input.h"
#include "myDisplay.h"
#include "myTerm.h"


void inputAccum() {
	printf("ENTER ACCUM VALUE: ");
	scanf("%d", &accumValue);
}

void inputCounter() {
	printf("ENTER COUNTER VALUE: ");
	scanf("%d", &opCounter);
	if (opCounter >= 0 && opCounter < N_MEM) memoryPointer = opCounter;
	else sc_regSet(OVERFLOW, 1);
}

void inputMemory() {
	int com = 0, oper = 0, val;
	sc_memoryGet(memoryPointer, &val);
	sc_commandDecode(val, &com, &oper);
	printf("ENCODE: ");
	scanf("%d %d", &com, &oper);
	sc_commandEncode(com, oper, &val);
	sc_memorySet(memoryPointer, val);
}

void clearInput() {
	int term = open(TERM, O_RDWR);
	int i;
	mt_gotoXY (25, 1);
	for (i = 0; i < 80; ++i)
	write (term, " ", 1);
	mt_gotoXY (25, 1);
	close (term);
}
