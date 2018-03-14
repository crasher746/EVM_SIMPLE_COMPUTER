#include <stdio.h>
#include <stdlib.h>

#include "header.h"
#include "myTerm.h"
#include "myBigChars.h"

int bc_printA (char *str) {
	printf(ENTER_ALT_MODE);
	printf(str);
	printf(EXIT_ALT_MODE);
	return 0;
}

int bc_box (int x1, int y1, int x2, int y2) {
	mt_gotoXY(x1, y1);
	bc_printA("l");

	int i;
	for (i = 1; i <= y2 - 2; i++) bc_printA("q");
	bc_printA("k");
	for (i = 1; i <= x2 - 2; i++) {
		mt_gotoXY(x1 + i, y1);
		bc_printA("x");
		mt_gotoXY(x1 + i, y1 + y2 - 1);
		bc_printA("x");
	}
	mt_gotoXY(x1 + x2 -1, y1);
	bc_printA("m");
	for (i = 0; i < y2 - 2; i++) bc_printA("q");
	bc_printA("j");
	return 0;
}

int bc_printBigChar (int big[2], int x, int y, enum COLOR fgColor, enum COLOR bgColor) {
	int i, j, k;	
	int buffer;
	int bitBuffer;
	int BigBuffer;
	char str[8] = {0};

	mt_setfgColor(fgColor);
	mt_setbgColor(bgColor);

	for (i = 0; i < 2; i++) {
		BigBuffer = big[i];
		
		for (j = 0; j < 4; j++) {
			BigBuffer = big[i] >> (j * 8);
			buffer = BigBuffer & 255;
			
			for (k = 0; k < 8; k++) {
				bitBuffer = (buffer & (1 << k)) >> k;
				if (bitBuffer != 0) {
					str[k] = 'a';
				}
				else {
					str[k] = ' ';
				}
			}
			mt_gotoXY(x + (i * 4) + j, y);
			bc_printA(str);
		}
	}
	return 0;
}

int bc_setBigCharPos (int *big, int x, int y, int value) {
	if (x < 0 || x > 7 || y < 0 || y > 7 || value > 1 || value < 0) return -1;
	int index = 0;
	if (x > 3) index = 1;
	if (value == 1) big[index] |= 1 << (x * 8 + y);
	else if (value == 0) big[index] &= ~(1 << (x * 8 + y));
	return 0;
}

int bc_getBigCharPos (int *big, int x, int y, int *value) {
	if (x < 0 || x > 7 || y < 0 || y > 7) return -1;
	int index = 0;
	if (x > 3) index = 1;
	*value = ((big[index] >> (x * 8)) >> y) & 1;
	return 0;
}

int bc_bigCharWrite (int fd, int *big, int count) {
	int result;
	while (count > 0) {
		if ((result = write(fd, big, sizeof(int) * 2)) == -1) return -1;
		count--;
	}
	return 0;
}

int bc_bigCharRead (int fd, int *big, int need_count, int *count) {
	while (need_count > 0) {
		int result;
		if ((result = read(fd, big, sizeof(int) * 2)) == -1) return -1;
		need_count--;
		*count = *count + 1;
	}
	return 0;
}

void chooseBig(int *BIG, int value) {
	switch (value) {
	case '+':
		BIG[0] = -15198184;
            	BIG[1] = 404232447;
            	break;
        case '0':
        	BIG[0] = 1111638654;
            	BIG[1] = 2118271554;
            	break;
        case '1':
            	BIG[0] = 404430364;
            	BIG[1] = 404232216;
            	break;
        case '2':
            	BIG[0] = 1077953150;
            	BIG[1] = 2114060926;
            break;
        case '3':
            	BIG[0] = 2084586110;
            	BIG[1] = 2118271100;
            break;
        case '4':
            	BIG[0] = 2120640102;
            	BIG[1] = 1616928864;
            	break;
        case '5':
            	BIG[0] = 2114324094;
            	BIG[1] = 2120245344;
            	break;
        case '6':
            	BIG[0] = 101058174;
            	BIG[1] = 2118534782;
            	break;
        case '7':
           	BIG[0] = 2016423998;
            	BIG[1] = 808464504;
            	break;
        case '8':
            	BIG[0] = 2118271614;
            	BIG[1] = 2118271614;
            	break;
        case '9':
            	BIG[0] = 1111638654; 
            	BIG[1] = 2120245374;
            	break;
        case 'A':
            	BIG[0] = 2118271614; 
            	BIG[1] = 1111638594;
            	break;
        case 'B':
            	BIG[0] = 2116166206; 
            	BIG[1] = 2118271554;
            	break;
        case 'C':
            	BIG[0] = 33686142;
            	BIG[1] = 2114060802;
            	break;
        case 'D':
            	BIG[0] = 1145325182; 
            	BIG[1] = 2118534212;
            	break;
        case 'E':
            	BIG[0] = 2114060926;
            	BIG[1] = 2114060926;
            	break;
        case 'F':
            	BIG[0] = 2114060926; 
            	BIG[1] = 131586;
            	break;
        default:
            	BIG[0] = 0;
            	BIG[1] = 0;
		break;
	}
}
