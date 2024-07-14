#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* nodes[26]; 

TreeNode* createNode(char data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* findNode(char data) {
    if (data == '.') return NULL;
    if (!nodes[data - 'A']) {
        nodes[data - 'A'] = createNode(data);
    }
    return nodes[data - 'A'];
}

// 전위순회
void preorder(TreeNode* root) {
    if (root) {
        printf("%c", root->data); 
        preorder(root->left);     
        preorder(root->right);   
    }
}

// 중위순회
void inorder(TreeNode* root) {
    if (root) {
        inorder(root->left);      
        printf("%c", root->data); 
        inorder(root->right);     
    }
}

// 후위순회
void postorder(TreeNode* root) {
    if (root) {
        postorder(root->left);  
        postorder(root->right);  
        printf("%c", root->data);
    }
}

int main(void) {
    int count;
    char node, left_node, right_node;

    scanf("%d", &count);
    getchar();

    // 노드를 가리키는 포인터 배열 초기화
    for (int i = 0; i < 26; i++) {
        nodes[i] = NULL;
    }

    // 각 노드 가리키는 포인터 배열을 이용해 트리 생성
    for (int i = 0; i < count; i++) {
        scanf("%c %c %c", &node, &left_node, &right_node);
        getchar();
        TreeNode* current = findNode(node);
        current->left = findNode(left_node);
        current->right = findNode(right_node);
    }

    TreeNode* root = nodes[0];

    preorder(root);
    printf("\n");

    inorder(root);
    printf("\n");

    postorder(root);
    printf("\n");

    return 0;
}