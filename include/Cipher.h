#ifndef __INCLUDED_CIPHER__
#define __INCLUDED_CIPHER__

void encrypt(unsigned char *res, const unsigned char *msg, int length);
void decrypt(unsigned char *res, const unsigned char *msg, int length);

void setVector(unsigned char val);

#endif
