#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcs.h"

void input(char* str, char* ch1, char* ch2, char* znak) {
    char sep[10] = " ";
    char *istr;
    if (str[0] == '~') {
        strcpy(znak, "~");
        int i = 1;
        for (int i = 1; i < strlen(str); ++i) {
            ch1[i - 1] = str[i];
        }
    }
    else {
    istr = strtok(str, sep);
    strcpy(ch1, istr);
    istr = strtok(NULL, sep);
    strcpy(znak, istr);
    istr = strtok(NULL, sep);
    strcpy(ch2, istr);
    }
}
        
int systsch (char* a) {
    if (a == NULL) {
        printf("значение не введено");
        exit(1);
    }
    if (a[0] == '0' && (a[1] == 'x' || a[1] == 'X')) {
        for (int i = 2; i < strlen(a); ++i) {
            if (a[i] > 'f') {
                return 0;
            }
        }
        return 16;
    }

    else if ( a[0] == '0') {
        for (int i = 1; i < strlen(a); ++i) {
            if (a[i] > '7' || a[i] < '0') {
                return 0;
            }
        }
        return 8;
    }

    else if (a[0] == '1') {
        for (int i = 0; i < strlen(a); ++i) {
            if (a[i] != '0' && a[i] != '1') {
                return 0;
            }
        }
        return 2;
    }
}


