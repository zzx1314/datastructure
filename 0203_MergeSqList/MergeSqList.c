#include "MergeSqList.h"

void MergeSqList_1(SqList La, SqList Lb, SqList* Lc) {
    int La_len, Lb_len;
    int i, j, k;
    ElemType ai, bj;

    i = j =1;
    k = 0;

    InitList(Lc);

    La_len = ListLength(La);
    Lb_len = ListLength(Lb);

    while(i <= La_len && j <= Lb_len) {
        GetElem(La, i, &ai);
        GetElem(Lb, j, &bj);

        if(ai <= bj) {
            ListInsert(Lc, ++k, ai);
            i++;
        } else {
            ListInsert(Lc, ++k, bj);
            j++;
        }
    }

    while(i <= La_len) {
        GetElem(La, i++, &ai);
        ListInsert(Lc, ++k, ai);
    }

    while(j <= Lb_len) {
        GetElem(Lb, j++, &bj);
        ListInsert(Lc, ++k, bj);
    }
}

void MergeSqList_2(SqList La, SqList Lb, SqList* Lc) {
    ElemType* pa, * pb, * pc;
    ElemType* pa_last, * pb_last;

    pa = La.elem;
    pb = Lb.elem;
    (*Lc).listsize = (*Lc).length = La.length + Lb.length;
    pc = (*Lc).elem = (ElemType*) malloc((*Lc).listsize * sizeof(ElemType));
    if (pc == NULL) {
        exit(OVERFLOW);
    }

    pa_last = La.elem + La.length -1;
    pb_last = Lb.elem + Lb.length -1;

    while(pa <= pa_last && pb <= pb_last) {
        if (*pa <= *pb) {
            *pc++ = *pa++;
        } else {
            *pc++ = *pb++;
        }
    }

    while(pa <= pa_last) {
        *pc++ = *pa++;
    }

    while(pb <= pb_last) {
        *pc++ = *pb++;
    }
}

