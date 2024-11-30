#include "Union.h"

void Union(SqList* La, SqList Lb) {
    int La_len, Lb_len;
    int i;
    ElemType e;

    La_len = ListLength(*La);
    lb_len = ListLength(Lb);

    for(i = 1; i<= Lb_len; i++){
        GetElem(Lb, i, &e);

        if(!LocateElem(*La, e, equal)) {
            ListInsert(La, ++La_len, e);
        }
    }
}

Status equal(ElemType e1, ElemType e2) {
    return e1 == e2 ? TRUE: FALSE;
}
