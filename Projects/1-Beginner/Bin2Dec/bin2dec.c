#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define BUFF_SIZE (8)

void prompt_error()
{
    printf("> Only '0' and '1' can be entered!\n");
    printf("> ");
}

void prompt()
{
    printf(">>> Welcome to Bin2Dec! Enter Binary number or 'q' to exit.\n");
    printf("> ");
}

bool bin_check(char *binary)
{
    for (int i = 0; i < strlen(binary); ++i) {
        if (binary[i] != '0' && binary[i] != '1')
            return false;
    }

    return true;
}

int bin2dec(char *binary)
{
    int dec = 0;

    int size = strlen(binary);
    for (int i = size - 1, base = 1; i >= 0; --i) {
        dec += base * (binary[i] == '1');
        base = base << 1;
    }

    return dec;
}


int main(int argc, char **argv)
{
    prompt();

    char binary[BUFF_SIZE] = {0};
    while (scanf("%s", binary) == 1) {

        if (strcmp(binary, "q") == 0) {
            break;
        }

        if(bin_check(binary) == false) {
            prompt_error();
            continue;
        }
        
        printf("> %s -> %d\n", binary, bin2dec(binary));
        printf("> ");

        memset(binary, '\0', BUFF_SIZE);
    }

    return 0;
}