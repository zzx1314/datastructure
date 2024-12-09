#ifndef SLINKLIST_H
#define SLINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

#define MAXSIZE 1000

typedef int ElemType;

typedef struct SLinkNode {
    ElemType data;
    int cur;
} SLinkList[MAXSIZE];


void InitSpace(SLinkList space);

int Malloc(SLinkList space);

void Free(SLinkList space, int k);

Status InitList(SLinkList space, int* S);

Status DestoryList(SLinkList space, int* S);

Status ClearList(SLinkList space, int S);

Status ListEmpty(SLinkList space, int S);

int ListLength(SLinkList space, int S);

Status GetElem(SLinkList space, int S, int i, ElemType* e);

int LocateElem(SLinkList space, int S, ElemType e, Status(Compare)(ElemType, ElemType));

Status PriorElem(SLinkList space, int S, ElemType cur_e, ElemType* pre_e);

Status NextElem(SLinkList space, int S, ElemType cur_e, ElemType* next_e);

Status ListInsert(SLinkList space, int S, int i, ElemType e);

Status ListDelete(SLinkList space, int S, int i, ElemType* e);

void ListTraverse(SLinkList space, int S, void(Visit)(ElemType));

void PrintList(SLinkList space, int S);

#endif
