#include <stdio.h>
#include "Union.h"
#include "SqList.h"

void PrintElem(ElemType e) {
    printf("%d ", e);
}

int main(int argc, char** argv) {
    ElemType a[5] = {5, 2, 1, 3, 9};
    ElemType b[7] = {7, 2, 6, 9, 11, 3, 10};
    SqList La, Lb;
    int i;

    InitList(&La);
    for(i = 1; i <= 5; i++){
        ListInsert(&La, i, a[i -1]);
    }

    InitList(&Lb);
    for(i = 1; i<= 7; i++) {
        ListInsert(&Lb, i, b[i -1]);
    }

    printf("La = ");
    ListTraverse(La, PrintElem);

    printf("Lb =");
    ListTraverse(Lb, PrintElem);

    printf("La = La L Lb = ");
    Union(&La, Lb);
    ListTraverse(La, PrintElem);

    return 0;
}
