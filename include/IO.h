#ifndef IO_H
#define IO_H

#include <stdbool.h>

void input(unsigned char *msg, const char *in, int length);
void output(const unsigned char *msg, int length);

unsigned char hex2dec(char h, char l);

bool isHex(char val);

#endif //IO_H
