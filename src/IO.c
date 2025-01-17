#include <stdio.h>
#include <stdbool.h>

#include "IO.h"

void input(unsigned char *msg, const char *in, const int length)
{
    for (int i = 0; i < length; i += 1)
        msg[i] = hex2dec(in[i * 2], in[i * 2 + 1]);
}

void output(const unsigned char *msg, const int length)
{
    for (int i = 0; i < length; i += 1)
        printf("%02x", msg[i]);
}

unsigned char hex2dec(const char h, const char l)
{
    unsigned char res = 0;

    if (h >= 'a' && h <= 'f')
        res += (h - 'a' + 10) * 16;
    else
        res += (h - '0') * 16;

    if (l >= 'a' && l <= 'f')
        res += l - 'a' + 10;
    else
        res += l - '0';

    return res;
}

bool isHex(const char val)
{
    return (val >= 'a' && val <= 'f') || (val >= '0' && val <= '9');
}
