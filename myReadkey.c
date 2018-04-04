#include <stdio.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include "myTerm.h"
#include "myReadkey.h"

struct termios const term_state;
struct termios termState;

int rk_myTermRegime(struct termios const *currentState, int regime, int vtime, int vmin, int echo, int sigint) {

	if (regime < 0 || regime > 1 || echo < 0 || echo > 1 || sigint < 0 || sigint > 1) 
	return -1;

	struct termios newTermState = *currentState;
	
	if (regime == 1)
		newTermState.c_lflag |= ICANON;
	else
		newTermState.c_lflag &= ~ICANON;

	if (echo == 1) 
		newTermState.c_lflag |= ECHO;
	else
		newTermState.c_lflag &= ~ECHO;

	if (sigint == 1) 
		newTermState.c_lflag |= ISIG;
	else
		newTermState.c_lflag &= ~ISIG;	

	newTermState.c_cc [VMIN] = vmin;
	newTermState.c_cc [VTIME] = vtime;
	tcsetattr(0, TCSANOW, &newTermState);
	
	return 0;
}

int rk_readKey(enum KEY *key) {
	int term;
	char buffer;
	
	struct termios termState = term_state;
	rk_myTermRegime(&termState, 0, 0, 1, 0, 1);
	read(term, &buffer, 1);

	switch(buffer) {
	case 'q':
		*key = KEY_QUIT;
		break;
	case 'l':
		*key = KEY_LOAD;
		break;
	case 's':
		*key = KEY_SAVE;
		break;
	case 'r':
		*key = KEY_RUN;
		break;
	case 't':
		*key = KEY_STEP;
		break;
	case 'i':
		*key = KEY_RESET;
		break;
	case 'e':
		*key = KEY_EDIT;
		break;
	case '\E':
		read(term, &buffer, 1);
		read(term, &buffer, 1);
		switch(buffer) {
		case 65:
			*key = KEY_UP;
			break;
		case 66:
			*key = KEY_DOWN;
			break;
		case 67:
			*key = KEY_RIGHT;
			break;
		case 68:
			*key = KEY_LEFT;
			break;		
		case '1':
			read(term, &buffer, 1);
			if (buffer == '5') {
				read(term, &buffer, 1);
				if (buffer == '~') *key = KEY_F5;
			}
			if (buffer == '7') {
				read(term, &buffer, 1);
				if (buffer == '~') *key = KEY_F6;
			}
			break;
		default:
			*key = KEY_BLANK;
	
		}
		break;
	default:
		*key = KEY_BLANK;
		break;
	}
	rk_myTermRegime(&termState, 1, 1, 1, 1, 1);
	close(term);
	
	return 0;
}

void termInit() {
	rk_myTermSave(&term_state);
}

void getDefaultTermSettings(struct termios *termState) {
	*termState = term_state;
}

int rk_myTermSave(struct termios *termState) {
	return tcgetattr(1, termState);
}

int rk_myTermRestore(struct termios *currentState) {
	return tcsetattr(1, TCSADRAIN, &termState);
}
