#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "funcs2.h"

int bin_10 (char* ch) {
    int sum = 0;
    int pow2 = 1;
    for (int i = strlen(ch) - 1; i > -1; i--) {
        if (ch[i] == '1') {
            sum += pow2;
        }
        pow2 *= 2;
    }
    return sum;
}

int my_pow(int a, int b) {
    int res = 1;
    while( b > 0) {
        res *= a;
        b -= 1;
    }
    return res;
}

int _10_bin(int ch) {
    int pres = 0;
    int k0 = 0;
    while (ch > 0) {
        pres += ch % 2;
        if (pres == 0 && ch % 2 == 0) {
            k0 += 1;
        }
        pres *= 10;
        ch /= 2;
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

