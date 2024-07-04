#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DListNode {
    char data;
    struct DListNode* rlink;
    struct DListNode* llink;
} DListNode;

void init(DListNode* head) {
    head->llink = head;
    head->rlink = head;
}

void insert(DListNode* before, char item) {
    DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
    newnode->data = item;
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink = newnode;
    newnode->rlink->llink = newnode;
}

void deleteNode(DListNode* head, DListNode* removed) {
    if (head == removed) return;

    removed->rlink->llink = removed->llink;
    removed->llink->rlink = removed->rlink;
    free(removed);
}

int main() {
    int test_cases;
    scanf("%d", &test_cases);

    for (int t = 0; t < test_cases; ++t) {
        char string[1000001];
        scanf("%s", string);

        DListNode head; // Dummy head node for the doubly linked list
        init(&head);
        DListNode* p = &head; // Cursor position

        int len = strlen(string);
        for (int j = 0; j < len; ++j) {
            char ch = string[j];

            if (ch == '<') {
                if (p != &head) {
                    p = p->llink;
                }
            }
            else if (ch == '>') {
                if (p->rlink != &head) {
                    p = p->rlink;
                }
            }
            else if (ch == '-') {
                if (p != &head) {
                    DListNode* temp = p;
                    p = p->llink;
                    deleteNode(&head, temp);
                }
            }
            else {
                insert(p, ch);
                p = p->rlink;
            }
        }

        // Output the password
        DListNode* point = head.rlink;
        while (point != &head) {
            printf("%c", point->data);
            point = point->rlink;
        }
        printf("\n");
    }

    return 0;
}