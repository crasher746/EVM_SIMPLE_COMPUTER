#ifndef MYREADKEY_H
#define MYREADKEY_H

enum KEY {KEY_QUIT, KEY_LOAD, KEY_SAVE, KEY_RUN, KEY_STEP, KEY_RESET, KEY_EDIT, KEY_UP, KEY_DOWN,
KEY_RIGHT, KEY_LEFT, KEY_BLANK, KEY_F5, KEY_F6, KEY_ESC, KEY_ENTER};

int rk_myTermRegime(struct termios const *, int, int, int, int, int);
int rk_readKey(enum KEY *key);
void termInit();
void getDefaultTermSettings(struct termios *);
int rk_myTermSave(struct termios *);
int rk_myTermRestore(struct termios *);

#endif
