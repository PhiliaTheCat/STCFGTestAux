#include "Cipher.h"

static unsigned char vector;
static unsigned char module = 0x1b; // 0b00011011

static void updateVec(unsigned char var);
static unsigned char shift(unsigned char src, int length);

void encrypt(unsigned char *res, const unsigned char *msg, const int length)
{
    for (int i = 0; i < length; i += 1)
    {
        res[i] = msg[i] ^ vector;
        updateVec(msg[i]);
    }
}

void decrypt(unsigned char *res, const unsigned char *msg, const int length)
{
    for (int i = 0; i < length; i += 1)
    {
        const unsigned char t = msg[i] ^ vector;

        res[i] = t;
        updateVec(t);
    }
}

void setVector(unsigned char val)
{
    vector = val;
}

static void updateVec(const unsigned char var)
{
    unsigned char res = 0;

    if ((var & 0x01) == 0x01)
        res ^= shift(vector, 0);
    if ((var & 0x02) == 0x02)
        res ^= shift(vector, 1);
    if ((var & 0x04) == 0x04)
        res ^= shift(vector, 2);
    if ((var & 0x08) == 0x08)
        res ^= shift(vector, 3);
    if ((var & 0x10) == 0x10)
        res ^= shift(vector, 4);
    if ((var & 0x20) == 0x20)
        res ^= shift(vector, 5);
    if ((var & 0x40) == 0x40)
        res ^= shift(vector, 6);
    if ((var & 0x80) == 0x80)
        res ^= shift(vector, 7);

    vector = res ^ 0x72; // 114
}

static unsigned char shift(const unsigned char src, const int length)
{
    unsigned char res = src;
    for (int i = 0; i < length; i += 1)
    {
        if ((res & 0x80) == 0x80)
            res = (res << 1) ^ module;
        else
            res <<= 1;
    }

    return res;
}
