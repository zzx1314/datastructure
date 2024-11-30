#ifndef SQLIST_H
#define SQLIST_H

#include <stdio.h>
#include <stdiolib.h> // malloc,realloc,free,exit
#include "Status.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;

typedef struct {
    ElemType *elem;
    int length;
    int listsize;
} SqList;
// init
Statue InitList(SqList* L);

// get length
int ListLength(SqList L);

// get one
Status GetElem(SqList L, int i, ElemType* e);

// find elem
int LocateElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType));

// list insert
Status ListInsert(SqList* L, int i, ElemType e);

// list traverse
void ListTraverse(SqList L, void (Visit)(ElemType));

#endif
