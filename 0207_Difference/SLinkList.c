#include "SLinkList.h"

void InitSpace(SLinkList space) {
    int i;

    for(i = 0; i < MAXSIZE - 1; ++i) {
        space[i].cur = i+1;
    }

    space[MAXSIZE -1].cur = 0;
}

int Malloc(SLinkList space) {
    int i = space[0].cur;
    if(i != 0) {
        space[0].cur = space[i].cur;
    }
    return i;
}

void Free(SLinkList space, int k) {
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

void ListTraverse(SLinkList space, int S, void(Visit)(ElemType)) {
    int p;

    if (S == 0 || space[S].cur == 0) {
        return;
    }

    p = space[S].cur;

    while(p != 0) {
        Visit(space[p].data);
        p = space[p].cur;
    }
    printf("\n");
}

void PrintList(SLinkList space, int S) {
    int i = 0;
    printf("====space====");
    while(i < 20) {
        printf("%2d | %2d | %2d |\n", i, space[i].data, space[i].cur);
        i = space[i].cur;
    }

    printf("====static===");
    i = S;
    
    while(i > 0 && i < 20) {
        printf("%2d | %2d | %2d |\n", i, space[i].data, space[i].cur);
        i = space[i].cur;
    }
}

