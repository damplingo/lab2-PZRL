#include <stdio.h>
#include <string.h>

#include "funcs16.h"

int hex_10 (char* ch) {
    int sum = 0;
    int pow = 1;
    int c;
    memmove(&ch[0], &ch[2], (strlen(ch) - 2));
    ch[strlen(ch) - 2] = '\0';
    for (int i = strlen(ch) - 1; i > -1; i--) {
        if (ch[i] >= '0' && ch[i] <= '9') {
            c = (int)ch[i] - '0';
        }
        else if (ch[i] >= 'a' && ch[i] <= 'f') {
            c = (int)ch[i] - 'a' + 10;
        }
        else if (ch[i] >= 'A' && ch[i] <= 'F') {
            c = (int)ch[i] - 'A' + 10;
        }
        sum += pow * c;
        pow *= 16;
    }
    return sum;
}

char symb(int ch) {
    switch(ch) {
        case 0: return '0';
        case 1: return '1';
        case 2: return '2';
        case 3: return '3';
        case 4: return '4';
        case 5: return '5';
        case 6: return '6';
        case 7: return '7';
        case 8: return '8';
        case 9: return '9';
        case 10: return 'a';
        case 11: return 'b';
        case 12: return 'c';
        case 13: return 'd';
        case 14: return 'e';
        case 15: return 'f';
    }
}

int _10_hex (int ch, char *sch) {
    int pres = ch;
    int ost = pres % 16;
    pres /= 16;
    if (pres == 0) {
        sch[0] = symb(ost);
        return 1;
    }
    int k = _10_hex(pres, sch);
    sch[k++] = symb(ost);
    return k;
}

