#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int ss = 0;

int bit(char ar[], int k) {
    if (!strcmp(ar, "add")) {
        if ((ss & (1 << k)) == 0) {
            ss = ss + (1 << k);
        }
    }
    else if (!strcmp(ar, "remove")) {
        if ((ss & (1 << k)) > 0) {
            ss = ss - (1 << k);
        }
    }
    else if (!strcmp(ar, "check")) {
        if ((ss & (1 << k)) > 0) {
            printf("1\n");
        }
        else {
            printf("0\n");
        }
    }
    else if (!strcmp(ar, "toggle")) {
        if ((ss & (1 << k)) == 0) {
            ss = ss + (1 << k);
        }
        else {
            ss = ss - (1 << k);
        }
    }
    else if (!strcmp(ar, "all")) {
        ss = (1 << 21) - 1;
    }
    else {
        ss = 0;
    }
    return 0;
}

int main() {
    int n;
    char ar[10];
    int tmp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", ar);
        scanf("%d", &tmp);
        bit(ar, tmp);
    }
}
