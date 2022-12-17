#include <stdio.h>
#include <string.h>

#include "funcs2.h"
#include "funcs8.h"

int oct_10 (char* ch) {
    int sum = 0;
    int pow = 1;
    for (int i = strlen(ch) - 1; i > -1; i--) {
        int c = (int)ch[i] - '0';
        sum += pow * c;
        pow *= 8;
    }
    return sum;
}

int _10_oct (int ch) {
    int pres = 0;
    int k0 = 0;
    while (ch > 0) {
        pres += ch % 8;
        if (pres == 0 && ch % 8 == 0) {
            k0 += 1;
        }
        pres *= 10;
        ch /= 8;
        if (ch <= 0) {
            pres /= 10;
        }
    }
    int res = 0;
    while (pres > 0) {
        res += pres % 10;
        pres /= 10;
        if (pres > 0) {
            res *= 10;
        }
    }
    return res * my_pow(10, k0);
}

