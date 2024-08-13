#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int count = 0;

int recursion(const char* s, int l, int r) {
    count++;

    if (l >= r) 
        return 1;
    else if (s[l] != s[r])
        return 0;
    else 
        return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
    return recursion(s, 0, strlen(s) - 1);
}

int main() {
    int N;
    char string[1001];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", string);
        printf("%d ", isPalindrome(string));
        printf("%d\n", count);
        count = 0;
    }
    return 0;
}