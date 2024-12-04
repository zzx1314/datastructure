#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Status.h"

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LNode;

typedef LNode* LinkList;

void ListTraverse(LinkList L, void(Visit)(ElemType));

Status CreateList_Head(LinkList* L, int n, char* path);

Status CreateList_Tail(LinkList* L, int n, char* path);

#endif
