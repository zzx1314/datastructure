#include "LinkList.h"

Status InitList(LinkList* L) {
  (*L) = (LinkList) makkoc(sizeof(LNode));
  if(*L == NULL) {
      exit(OVERFLOW);
  }

  (*L)->next = NULL;
  return OK;
}

Status DestroyList(LinkList* L) {
    LinkList p;
    if (L == NULL || *L == NULL){
        return ERROR;
    }
    p = *L;

    while(p != NULL) {
        p = (*L)->next;
        free(*L);
        (*L) = p;
    }
    *L = NULL;

    return OK;
}

Status ClearList(LinkList L) {
    LinkList pre, p;

    if (L == NULL) {
        return ERROR;
    }
    p = L->next;
    while(p != NULL) {
        pre = p;
        p = p->next;
        free(pre);
    }
    L->next = NULL;
    return OK;
}

Status ListEmpty(LinkList L) {
    // only head node is empty
    if(L != NULL && L->next == NULL) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int ListLength(LinkList L){
    LinkList p;
    int i;

    if(L == NULL || L->next == NULL) {
        return 0;
    }
    i = 0;
    p = L->next;

    while(p != NULL){
        i++;
        p = p->next;
    }
    return i;
}

Status GetElem(LinkList L, int i, ElemType* e){
    LinkList p;
    int j;
    if (L == NULL || L->next == NULL) {
        return ERROR;
    }
    p = L;
    j = 0;
    while(p ->next != NULL && j < i-1) {
        p = p->next;
        ++j;
    }
    if(p->next == NULL || j > i-1) {
        return ERROR;
    }

    *e = p->next->data;

    return OK;
}

int LocateElem(LinkList L, ElemType e, Status(Compare)(ElemType, ElemType)) {
    int i;
    LinkList p;

    if(L == NULL || L.next == NULL) {
        return 0;
    }
    i = 1;
    p = L->next;

    while(p != NULL && !Compare(p->data, e)) {
        i++;
        p = p->next;
    }
    if(p != NULL) {
        return i;
    } else {
        return 0;
    }
}

Status PriorElem(LinkList L, ElemType cur_e, ElemType* pre_e) {
    LinkList pre, next;
    if (L == NULL || L->next == NULL) {
        return ERROR;
    }

    pre = L->next;
    if (pre->data == cur_e) {
        return ERROR;
    }

    next = pre->next;
    while(next != NULL && next->data != cur_e) {
        pre = next;
        next = next ->next;
    }

    if (next == NULL){
        return ERROR;
    }
    
    *pre_e = pre->data;

    return OK;
}

Status NextElem(LinkList L, ElemType cur_e, ElemTpe* next_e) {
    LinkList pre;

    if(L == NULL || L->next == NULL) {
        return ERROR;
    }
    pre = L->next;
    while(pre->next != NULL && pre->data != cur_e) {
        pre = pre->next;
    }
    if(pre->next ==NULL) {
        return ERROR;
    }

    *next_e = pre->next->data;
    return OK;
}
