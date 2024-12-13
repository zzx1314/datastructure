#ifndef SLINKLIST_H
#define SLINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

#define MAXSIZE 1000
typedef int ElemType;

typedef struct SLinkLNode {
    ElemType data;
    int cur;
} SLinkList[MAXSIZE];

void InitSpace(SLinkList space);

int Malloc(SLinkList space);

void Free(SLinkList space, int k);

void ListTraverse(SLinkList space, int S, void(Visit)(ElemType));

void PrintList(SLinkList space, int S);

#endif
