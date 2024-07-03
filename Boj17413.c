#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100001

int main() {
    int top = -1;
    char data[MAX_STACK_SIZE];
    char string[MAX_STACK_SIZE];

    // fgets ����Ͽ� ���ڿ� �Է� �ޱ�
    fgets(string, MAX_STACK_SIZE, stdin);

    // ���ڿ� ���� ���� ���ڰ� ���� ��� ����
    if (string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }

    for (int i = 0; i < strlen(string); i++) {
        // �±� ������ ���ÿ� ����ִ� ���ڿ� ���� pop(reverse ���) �� �±״� �״�� ���
        if (string[i] == '<') {
            while (top != -1) {
                printf("%c", data[top]);
                top--;
            }
            while (string[i] != '>') {
                printf("%c", string[i]);
                i++;
            }
            // �ݴ� �±� '>'�� ����ϰ� ���� ���ڷ� �Ѿ��
            printf("%c", string[i]);
        }
        // ���� ������ ���ÿ� ����ִ� ���ڿ� ���� pop(reverse ���)
        else if (string[i] == ' ') {
            while (top != -1) {
                printf("%c", data[top]);
                top--;
            }
            printf(" "); // ���� ���
        }
        // ���ÿ� push
        else {
            data[++top] = string[i];
        }
    }

    // �����ִ� ���ڿ� ���
    while (top != -1) {
        printf("%c", data[top]);
        top--;
    }

    return 0;
}