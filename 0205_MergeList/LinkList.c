#include "LinkList.h"

void ListTraverse(LinkList L, void(Visit)(ElemType)) {
    LinkList p;
    if(L == NULL || L->next == NULL) {
        return;
    }
    p = L ->next;
    while(p != NULL) {
        Visit(p->data);
        p = p->next;
    }
    printf("\n");
}

Status CreateList_Head(LinkList* L,int n, char* path) {
    int i;
    LinkList = p;
    FILE* = fp;
    int readFromConsole;

    readFromConsole = path == NULL || strcmp(path, "") == 0;

    if(readFromConsole) {
        *L = (LinkList) malloc(sizeof(LNode));
        (*L)->next = NULL;
    }
}
