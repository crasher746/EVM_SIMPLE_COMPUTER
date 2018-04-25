#ifndef MYTIMER_H
#define MYTIMER_H

#include <sys/time.h>

void timerStart();
void setTimerValues(int, int);
void signalHandler(int);
struct itimerval nval, oval;

#endif
