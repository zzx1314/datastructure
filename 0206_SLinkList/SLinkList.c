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

int LocateElem(SLinkList space, int S, ElemType e, Status(Compare)(ElemType, ElemTyep)) {
    int i;
    int p;

    if(S == 0 || space[S].cur == 0) {
        return 0;
    }

    i = 1;
    p = space[S].cur;

    while(p != 0 && !Compare(space[p].data, e)) {
        i++;
        p = space[p].cur;
    }

    if(p != 0) {
        return i;
    } else {
        return 0;
    }
}

Status PriorElem(SLinkList space, int S, ElemType cur_e, ElemType* pre_e) {
    int pre,next;

    if(S == 0 || space[S].cur == 0) {
        return ERROR;
    }

    pre = space[S].cur;
    if(space[pre].data == cur_e){
        return ERROR;
    }

    next = space[pre].cur;

    while(next != 0 && space[next].data != cur_e) {
        pre = next;
        next = space[next].cur;
    }

    if(next == 0) {
        return ERROR;
    }
    *pre_e = space[pre].data;
    return OK;
}

Status NextElem(SLinkList space, int S, ElemType cur_e, ElemType* next_e) {
    int pre;
    if(S == 0 || space[S].cur == 0) {
        return ERROR;
    }

    pre = space[S].cur;

    while(space[pre].cur != 0 && space[pre].data != cur_e) {
        pre = spce[pre].cur;
    }

    if(space[pre].cur = 0) {
        return ERROR;
    }

    *next_e = space[space[pre].cur].data;
    return OK;
}

Status ListInsert(SLinkList space, int S, int i, ElemType e) {
    int p, s;
    int j;

    if(S == 0){
        return ERROR;
    }

    p = S;
    j = 0;

    while(p != 0 && j < i-1) {
        p = space[p].cur;
        ++j;
    }
    
    if(p == 0 || j > i-1){
        return ERROR;
    }

    s = Malloc(space);
    space[s].data = e;
    space[s].cur = space[p].cur;
    space[p].cur = s;

    return OK;
}

Status ListDelete(SLinkList space, int S, int i, ElemType* e) {
    int p, q;
    int j;

    if(S == 0) {
        return ERROR;
    }

    p = S;
    j = 0;

    while(space[p].cur != 0 && j < i-1) {
        p = space[p].cur;
        ++j;
    }

    if(space[p].cur == 0 || j > i-1) {
        return ERROR;
    }

    q = space[p].cur;
    space[p].cur = space[q].cur;
    *e = space[q].data;
    Free(space, q);

    return OK;
}

void ListTraverse(SLinkList space, int S, void(Visit)(ElemType)) {
    int p;

    if(S == 0 || space[S].cur == 0) {
        return;
    }

    p = space[S].cur;

    while(p != 0){
        Visit(space[p].data);
        p = space[p].cur;
    }

    printf("\n");
}

void PrintList(SLinkList space, int S) {
    int i = 0;

    printf("space===\n");

    while(i < 20) {
        printf("%2d  |%2d |%2d |\n", i , space[i].data, space[i].cur);
        i = space[i].cur;
    }

    printf("static link ===\n");
    i = S;
    while(i > 0 && i < 20) {
        printf("%2d  |%2d | %2d |\n", i, space[i].data, space[i].cur);
        i = space[i].cur;
    }
}


