#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "funcs.h"
#include "funcs2.h"
#include "funcs8.h"
#include "funcs16.h"

int main() {
    char *str = NULL;
    size_t len = 0;
    char ch1[15];
    char ch2[15];
    int ich1, ich2;
    char znak[10];
    int znak_ch1 = 1;
    int znak_ch2 = 1;
    printf("введите выражение\n");
    getline(&str, &len, stdin);
    input(str, ch1, ch2, znak);
    if (ch1[0] == '-') { //проверка на отрицательной число
        znak_ch1 = -1;
    }
    if (ch2[0] == '-' || ch2[1] == '-') {
        znak_ch2 = -1;
    }
    int sch1 = systsch(ch1);
    int sch2 = systsch(ch2);
    if (sch1 == 0) {
        printf("первое число не принадлежит доступным системам счисления");
        return 0;
    }
    if (str[0] != '~') {
        if (sch2 == 0) {
            printf("второе число не принадлежит доступным системам счисления");
            return 0;
        }
        if (sch1 != sch2) {
            printf("ошибка: системы счисления не совпадают");
            return 0;
        }
    }
    if (sch1 == 2) {
        ich1 = bin_10(ch1) * znak_ch1;
        ich2 = bin_10(ch2) * znak_ch2;
    } 
    if (sch1 == 8) {
        ich1 = oct_10(ch1) * znak_ch1;
        ich2 = oct_10(ch2) * znak_ch2;
    }
    if (sch1 == 16) {
        ich1 = hex_10(ch1) * znak_ch1;
        ich2 = hex_10(ch2) * znak_ch2;
    }
    int iznak = (int)znak[0];
    switch (iznak) {
        case '+':
            plus(sch1, ich1, ich2);
            break;
        case '-':
            minus(sch1, ich1, ich2);
            break;
        case '*':
            prois(sch1, ich1, ich2);
            break;
        case '%':
            if (ich2 == 0) {
                    printf("а возможно ли деление на 0?)");
                    return 0;
            }
            ostat(sch1, ich1, ich2);
            break;
        case '|':
            funcsor(sch1, ich1, ich2);
            break;
        case '&':
            funcsand(sch1, ich1, ich2);
            break;
        case '^':
            funcsxor(sch1, ich1, ich2);
            break;
        case '~':
            funcsinv(sch1, ich1);
            break;

    }
    free(str);
    return 0;
}
