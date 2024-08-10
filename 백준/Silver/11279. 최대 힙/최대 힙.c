#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100001

typedef int element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
}HeapType;

HeapType* create() {
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) {
    h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) {
    int i = ++(h->heap_size);

    // 트리를 거슬러 올라가면서 부모 노드와 비교, 교체
    while ((i != 1) && (item > h->heap[i / 2])) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
}

element delete_max_heap(HeapType* h) {
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;

    while (child <= h->heap_size) {
        // 현재 노드의 자식 중 더 작은 자식 노드 탐색 
        if ((child < h->heap_size) && (h->heap[child] < h->heap[child + 1])) child++;
        if (temp >= h->heap[child]) break;

        // 한 단계 아래로 이동
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

int main() {
    int N, item;
    scanf("%d", &N);
    HeapType* heap = create();
    init(heap);
    for (int i = 0; i < N; i++) {
        scanf("%d", &item);

        // 입력받은 값이 0일 때 heap이 공백이면 0 출력, 공백이 아니면 삭제한 요소를 출력
        if (item == 0) {
            if (heap->heap_size == 0) {
                printf("0\n");
            }
            else {
                printf("%d\n", delete_max_heap(heap));
            }
        }
        // 입력받은 값이 0이 아닐 때 heap에 삽입
        else {
            insert_max_heap(heap, item);
        }
    }
    return 0;
}