#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    int count;
    char string[51][51];
    char res_string[51];

    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        scanf("%s", string[i]);
    }

    int len = strlen(string[0]);
    for (int i = 0; i < len; i++) {
        char ch = string[0][i];
        for (int j = 1; j < count; j++) {
            if (string[j][i] != ch) {
                ch = '?';
                break;
            }
        }
        res_string[i] = ch;
    }
    res_string[len] = '\0'; 

    printf("%s\n", res_string);

    return 0;
}