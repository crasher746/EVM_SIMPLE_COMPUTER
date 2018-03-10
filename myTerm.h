#ifndef MYTERM_H
#define MYTERM_H

#include <sys/ioctl.h>

#define CLR_SCR "\E[H\E[J"
#define GOTO_XY "\E[%d;%dH"
#define BG_COLOR "\E[4%dm"
#define FG_COLOR "\E[1;3%dm"

enum COLOR {RED = 1, GREEN = 2, YELLOW = 3, DARK_BLUE = 4, PURPLE = 5, BLUE = 6, WHITE = 7};

int mt_clrscr ();
int mt_gotoXY (int , int );
int mt_setbgColor (enum COLOR );
int mt_setfgColor (enum COLOR );
int mt_getScreenSize (int *, int *); 

#endif

