#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcs.h"

int main() {
    char str[30] = "1101 | 1011";
    char ch1[15];
    char ch2[15];
    char znak[10];
    input(str, ch1, ch2, znak);
    printf("%s\n", znak);
    printf("%s\n", ch1);
    printf("%s\n", ch2);
    printf("%d", systsch(ch1));
    return 0;
}
