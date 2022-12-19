#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcs.h"
#include "funcs2.h"
#include "funcs8.h"
#include "funcs16.h"

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
    int i = 0;
    while (a[i] == ' ' || a[i] == '-' || a[i] == '(') { //обработка "оболочки" числа: знаки -, (, ); сдвиг для корректного поведения дальнейшей функции
        i += 1;
    }
    int k = 0;
    for (int j = 0; j < strlen(a); ++j) {
        if (a[j] == '-' || a[j] == ' ' || a[j] == '\n' || a[j] == ')' || a[j] == '(') {
            k += 1;
        }
    }
    memmove(&a[0], &a[i], strlen(a) - i);
    a[strlen(a) - k] = '\0';//***
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

void plus(int sch, int ich1, int ich2) {
    if (sch == 2) {
        int res = ich1 + ich2;
        int ressch = _10_bin(abs(res));
        if (res < 0) {
            ressch *= -1;
        }
        printf("%d (%d)\n", ressch, res);
    }
    if (sch == 8) {
        int res = ich1 + ich2;
        char zn = ' ';
        if (res < 0) {
            zn = '-';
            printf("%c0%d (%d)\n",zn, _10_oct(abs(res)), res);
        }
        else {
            printf("0%d (%d)\n", _10_oct(abs(res)), res);
        }
    }
    if (sch == 16) {
        int res = ich1 + ich2;
        char zn = ' ';
        char s[30];
        int k =_10_hex(abs(res), s);
        char str[k+1];
        str[k] = '\0';
        _10_hex(abs(res), str);
        if (res < 0) {
            zn = '-';
            printf("%c0x%s  (%d)\n", zn, str, res);
        }
        else {
            printf("0x%s  (%d)\n", str, res);
       }
   }
}

void minus(int sch, int ich1, int ich2) {
    int res = ich1 - ich2;
    char zn = '-';
    if (sch == 2) {
        int ressch = _10_bin(abs(res));
        if (res < 0) {
            ressch *= -1;
        }
        printf("%d (%d)\n", ressch, res);
    }

    if (sch == 8) {
        if (res < 0) {
            printf("%c0%d (%d)\n",zn, _10_oct(abs(res)), res);
        }
        else {
            printf("0%d (%d)\n", _10_oct(abs(res)), res);
        }
    }

    if (sch == 16) {
        char s[30];
        int k =_10_hex(abs(res), s);
        char str[k+1];
        str[k] = '\0';
        _10_hex(abs(res), str);
        if (res < 0) {
            printf("%c0x%s  (%d)\n", zn, str, res);
        }
        else {
            printf("0x%s  (%d)\n", str, res);
       }
   }
}


    
void prois(int sch, int ich1, int ich2) {
    int res = ich1 * ich2;
    char zn = '-';
    if (sch == 2) {
        int ressch = _10_bin(abs(res));
        if (res < 0) {
            ressch *= -1;
        }
        printf("%d (%d)\n", ressch, res);
    }

    if (sch == 8) {
        if (res < 0) {
            printf("%c0%d (%d)\n",zn, _10_oct(abs(res)), res);
        }
        else {
            printf("0%d (%d)\n", _10_oct(abs(res)), res);
        }
    }

    if (sch == 16) {
        char s[30];
        int k =_10_hex(abs(res), s);
        char str[k+1];
        str[k] = '\0';
        _10_hex(abs(res), str);
        if (res < 0) {
            printf("%c0x%s  (%d)\n", zn, str, res);
        }
        else {
            printf("0x%s  (%d)\n", str, res);
       }
   }
}

void ostat(int sch, int ich1, int ich2) {
    int res = 0;
    if (ich1 < 0 && ich2 > 0) {
        int cel = -1 *(abs(ich1) / abs(ich2));
        cel -= 1;
        res = ich1 - ich2 * cel;
    }
    else if (ich1 < 0 && ich2 < 0) {
        int cel = abs(ich1) / abs(ich2);
        cel += 1;
        res = ich1 - ich2 * cel;
    }
    else {
        res = abs(ich1) % abs(ich2);
    }

    if (sch == 2) {
        int ressch = _10_bin(abs(res));
        printf("%d (%d)\n", ressch, res);
    }

    if (sch == 8) {
        printf("0%d (%d)\n", _10_oct(abs(res)), res);
    }

    if (sch == 16) {
        char s[30];
        int k =_10_hex(abs(res), s);
        char str[k+1];
        str[k] = '\0';
        _10_hex(abs(res), str);
        printf("0x%s  (%d)\n", str, res);
   }
}

void funcsor(int sch, int ich1, int ich2) {
    if (ich1 < 0 || ich2 < 0) {
        printf("введено отрицательное значение\n");
        exit (1);
    }
    int res = ich1 | ich2;
    if (sch == 2) {
        printf("%d (%d)\n", _10_bin(res), res);
    }

    if (sch == 8) {
        printf("0%d (%d)\n", _10_oct(abs(res)), res);
    }

    if (sch == 16) {
        char s[30];
        int k =_10_hex(abs(res), s);
        char str[k+1];
        str[k] = '\0';
        _10_hex(abs(res), str);

        printf("0x%s  (%d)\n", str, res);
    }
}

void funcsand(int sch, int ich1,int ich2) {
    if (ich1 < 0 || ich2 < 0) {
        printf("введено отрицательное значение\n");
        exit (1);
    }
    int res = ich1 & ich2;
    if (sch == 2) {
        printf("%d (%d)\n", _10_bin(res), res);
    }

    if (sch == 8) {
        printf("0%d (%d)\n", _10_oct(abs(res)), res);
    }

    if (sch == 16) {
        char s[30];
        int k =_10_hex(abs(res), s);
        char str[k+1];
        str[k] = '\0';
        _10_hex(abs(res), str);

        printf("0x%s  (%d)\n", str, res);
    }
}

void funcsxor(int sch, int ich1,int  ich2) {
    if (ich1 < 0 || ich2 < 0) {
        printf("введено отрицательное значение\n");
        exit (1);
    }
    int res = ich1 ^ ich2;
    if (sch == 2) {
        printf("%d (%d)\n", _10_bin(res), res);
    }

    if (sch == 8) {
        printf("0%d (%d)\n", _10_oct(abs(res)), res);
    }

    if (sch == 16) {
        char s[30];
        int k =_10_hex(abs(res), s);
        char str[k+1];
        str[k] = '\0';
        _10_hex(abs(res), str);

        printf("0x%s  (%d)\n", str, res);
    }
}

void funcsinv(int sch, int ich1) {
    if (ich1 < 0) {
        printf("введено отрицательное значение\n");
        exit (1);
    }
    int res = ~ich1;
    char zn = '-';
    if (sch == 2) {
        if (res < 0) {
            printf("%c%d (%d)\n", zn, _10_bin(abs(res)), res);
        }
        else {
          printf("%d (%d)\n", _10_bin(abs(res)), res);
        }     
    }

    if (sch == 8) {
        if (res < 0) {
            printf("%c0%d (%d)\n", zn, _10_oct(abs(res)), res);
        }
        else {
            printf("0%d (%d)\n", _10_oct(abs(res)), res);
        }
    }

    if (sch == 16) {
        char s[30];
        int k =_10_hex(abs(res), s);
        char str[k+1];
        str[k] = '\0';
        _10_hex(abs(res), str);

        if (res < 0) {
            printf("%c0x%s  (%d)\n", zn, str, res);
        }
        else {
            printf("0x%s  (%d)\n", str, res);
        }
    }
}

