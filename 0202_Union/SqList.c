#include "SqList.h"

Status InitList(SqList* L){
   (*L).elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
   if((*L).elem == NULL) {
       exit(OVERFLOW);
   }
   (*L).length = 0 ;
   (*L).listsize = LIST_INIT_SIZE;
   
   return OK;
}

int ListLength(SqList L) {
    return L.length;
}

Status GetElem(SqList L, int i, ElemType* e){
    if(i < 1 || i > L.length) {
        return ERROR;
    }
    *e = L.elem[i -1];
    return OK;
}

int LocateElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType)) {
    int i;
    ElemType* p;

    if(L.elem == NULL) {
        return ERROR;
    }

    i = 1;
    p = L.elem;

    while(i <= L.length && !Compare(*p++, e)) {
        ++i;
    }
    if(i <= L.length) {
        return i;
    } else {
        return 0;
    }
}

Statue ListInsert(SqList* L, int i, ElemType e){
    ElemType* newbase;
    ElemType* p, *q;

    if((*L).length >= (*L).listsize) {
        newbase = (ElemType*) realloc((*L).elem, ((*L).listsize + LISTINCREMENT) * sizeof(ElemType));
        if(newbase == NULL){
            exit(OVERFLOW);
        }
        (*L).elem = newbase;
        (*L).listsize += LISTINCREMENT;
    }
    q = &(*L).elem[i -1];
    for(p = (*L).elem[(*L).length -1]; p >= q; --p){
        *(p + 1) = *p;
    }
    *q = e;
    (*L).length++;
    return OK;
}

void ListTraverse(SqList L, void(Visit)(ElemTpe)) {
    int i;
    for(i = 0; i<L.length; i++){
        Visit(L.elem[i]);
    }
    printf("\n");
}
