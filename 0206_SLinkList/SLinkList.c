#include "SLinkList.h"

void InitSpace(SLinkList space) {
    int i;
    for (i = 0; i<MAXSIZE-1; ++i) {
        space[i].cur = i + 1;
    }
    space[MAXSIZE - 1].cur = 0;
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

Status InitList(SLinkList space, int* S) {
    int index;
    InitSpace(space);

    index = Malloc(space);

    if(index == 0) {
        return ERROR;
    }
    
    space[index].cur = 0;

    *S = index;

    return OK;
}

Status DestroyList(SLinkList space, int* S) {
    int cur;

    if (S == NULL || *S == 0) {
        return ERROR;
    }

    while(*S != 0) {
        cur = space[*S].cur;
        Free(space, *S);
        *S = cur;
    }

    return OK;
}

Status ClearList(SLinkList space, int S) {
    int P;
    int cur;

    if(S == 0) {
        return ERROR;
    }
    P = space[S].cur;

    while(P != 0) {
        cur = space[P].cur;
        Free(space, P);
        P = cur;
    }
    space[S].cur = 0;
    
    return OK;
}

Status ListEmpty(SLinkList space, int S) {
    if (S != 0 && space[S].cur == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int ListLength(SLinkList space, int S) {
    int count;
    if (S == 0 || space[S].cur == 0) {
        return 0;
    }
    S = space[S].cur;
    count = 0;

    while(S != 0) {
        count++;
        S = space[S].cur;
    }
    return count;
}

Status GetElem(SLinkList space, int S, int i, ElemType* e) {
    int count;

    if(S == 0 || space[S].cur == 0) {
        return ERROR;
    }
    S = space[S].cur;
    count = 0;

    while(S != 0 && count < i-1) {
        count++;
        S = space[S].cur;
    }

    if(S == 0 || count > i-1) {
        return ERROR;
    }

    *e = space[S].data;

    return OK;
}


