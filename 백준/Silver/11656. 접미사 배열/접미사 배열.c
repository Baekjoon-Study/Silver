#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    char string[1001];
    char string_array[1001][1001];
    char temp[1001];

    scanf("%s", string);
    int len = strlen(string);

    // 각 잘린 문자열 배열에 저장
    for (int i = 0; i < len; i++) {
        for (int j = 0; i + j < len; j++) {
            string_array[i][j] = string[i + j];
        }
        // Null로 문자열의 끝을 알림
        string_array[i][len - i] = '\0';
    }
    // 버블정렬, 사전 순으로 정렬
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (strcmp(string_array[j], string_array[j + 1]) > 0) {
                strcpy(temp, string_array[j]);
                strcpy(string_array[j], string_array[j + 1]);
                strcpy(string_array[j + 1], temp);
            }
        }
    }
    for (int i = 0; i < len; i++) {
        printf("%s\n", string_array[i]);
    }
    return 0;
}
