#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cipher.h"
#include "IO.h"

int main(const int argc, const char **argv)
{
    if (argc != 6)
    {
        printf("Error: invalid invokation!\n"
            "Usage: Coder <-e | -d> -v <hexdecimal initial vector> -m <hexdecimal message>\n");

        return -1;
    }

    if (!(strcmp(argv[1], "-e") == 0 || strcmp(argv[1], "-d") == 0))
    {
        printf("Error: invalid invokation!\n"
            "Usage: Coder -v <hexdecimal initial vector> -m <hexdecimal message>\n");

        return -1;
    }

    if (strcmp(argv[2], "-v") != 0)
    {
        printf("Error: invalid invokation!\n"
            "Usage: Coder -v <hexdecimal initial vector> -m <hexdecimal message>\n");

        return -1;
    }

    if (strlen(argv[3]) != 2)
    {
        printf("Error: invalid invokation!\n"
            "Usage: Coder -v <hexdecimal initial vector> -m <hexdecimal message>\n");

        return -1;
    }

    if (!(isHex(argv[3][0]) && isHex(argv[3][1])))
    {
        printf("Error: invalid invokation!\n"
            "Usage: Coder -v <hexdecimal initial vector> -m <hexdecimal message>\n");

        return -1;
    }

    setVector(hex2dec(argv[3][0], argv[3][1]));

    if (strcmp(argv[4], "-m") != 0)
    {
        printf("Error: invalid invokation!\n"
            "Usage: Coder -v <hexdecimal initial vector> -m <hexdecimal message>\n");

        return -1;
    }

    const int inputLength = strlen(argv[5]);
    if (inputLength % 2 != 0)
    {
        printf("Error: invalid invokation!\n"
            "Usage: Coder -v <hexdecimal initial vector> -m <hexdecimal message>\n");

        return -1;
    }

    for (int i = 0; i < inputLength; i += 1)
    {
        if (!isHex(argv[5][i]))
        {
            printf("Error: invalid invokation!\n"
                "Usage: Coder -v <hexdecimal initial vector> -m <hexdecimal message>\n");

            return -1;
        }
    }

    unsigned char *msg = calloc(256, sizeof(unsigned char));
    unsigned char *res = calloc(256, sizeof(unsigned char));

    input(msg, argv[5], inputLength / 2);
    if (strcmp(argv[1], "-e") == 0)
        encrypt(res, msg, inputLength / 2);
    else
        decrypt(res, msg, inputLength / 2);
    output(res, inputLength / 2);

    free(res);
    free(msg);

    return 0;
}
