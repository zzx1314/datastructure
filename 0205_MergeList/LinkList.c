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
        printf("input %d number des elem:", n);
        for(i = 1; i<= n; i++){
            p = (LinkList) malloc(sizeof(LNode));
            scanf("%d", &(p->data));

            p->next = (*L)->next;
            (*L)->next = p;
        }
    } else {
        fp = fopen(path, "r");
        if (fp == NULL) {
            return ERROR;
        }
        (*L) = (LinkList) malloc(sizeof(LNode));
        (*L)->next = NULL;
        for(i = 1; i<= n; i++) {
            p = (LinkList) malloc(sizeof(LNode));
            ReadData(fp, "%d", &(p->data));

            p->next = (*L)->next;
            (*L)->next = p;
        }
        fclose(fp);
    }
    return OK;
}

Status CreateList_Tail(LinkList* L, int n, char* path){
    int i;
    LinkList p, q;
    FILE* fp;
    int readFromConsole;
    readFromConsole = path == NULL || strcmp(path, "") == 0;

    if(readFromConsole) {
        *L = (LinkList) malloc(sizeof(LNode));
        (*L)->next = NULL;
        printf("input %d number aes elem:", n);
        for (i = 1, q = *L; i<=n; i++) {
            p = (LinkList) malloc(sizeof(LNode));
            scanf("%d", &(p->data));

            q->next = p;
            q = q->next;
        }
        p->next = NULL;
    } else {
        fp = fopen(path, "r");
        if (fp == NULL) {
            return ERROR;
        }
        (*L) = (LinkList) malloc(sizeof(LNode));
        (*L) ->next = NULL;
        for (i = 1, q = *L; i <= n; i++) {
            p = (LinkList) malloc(sizeof(LNode));
            ReadData(fp, "%d", &(p->data));
            q ->next = p;
            q = q->next;
        }
        p->next = NULL;
        fclose(fp);
    }
    return OK;
}
