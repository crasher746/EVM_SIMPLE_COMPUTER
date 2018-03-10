#include "myTerm.h"

int mt_clrscr () {
	printf(CLR_SCR);
	return 0;
}

int mt_gotoXY (int x, int y) {
	printf(GOTO_XY, x, y);	
	return 0;
}

int mt_setbgColor (enum COLOR color) {
	if ((int)color >= 1 || (int)color <= 7) {
		printf(BG_COLOR, color);
		return 0;
	}
	else return -1;	
}

int mt_setfgColor (enum COLOR color) {
	if ((int)color >= 1 || (int)color <= 7) {
		printf(FG_COLOR, color);
		return 0;
	}
	else return -1;
}

int mt_getScreenSize (int *x, int *y) {
	struct winsize ws;

	if (!ioctl (1, TIOCGWINSZ, &ws)) {
		*x = ws.ws_row;
		*y = ws.ws_col;
		return 0;	
	}
	return -1;
}
