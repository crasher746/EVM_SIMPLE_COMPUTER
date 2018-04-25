#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "header.h"
#include "myTerm.h"
#include "myBigChars.h"
#include "myDisplay.h"
#include "myReadkey.h"
#include "myTimer.h"

void timerStart() {
	setitimer(ITIMER_REAL, &nval, &oval);
}

void setTimerValues(int upperValue, int lowerValue) {
	nval.it_interval.tv_sec = upperValue;
	nval.it_interval.tv_usec = lowerValue;
	nval.it_value.tv_sec = upperValue;
	nval.it_value.tv_usec = lowerValue;
}

void signalHandler(int signo) {
	sc_regGet(ISRUN, &flag_key);
	sc_regGet(IGNOREFLAG, &flag_ign);
	int value = 0, command = 0, operand = 0;

	if (opCounter < 99 && flag_key && !flag_ign) {
		if ((sc_memoryGet(memoryPointer, &value) == 0) && (sc_commandDecode(value, &command, &operand) == 0)) {
			memoryPointer++;
		}
		showFull();
	}
	else {
		sc_regSet(ISRUN, 0);
		alarm(0);
	}
	flag_key = 0;
}
