#include <stdio.h>
#include "SqList.h"
#include "MergeSqList.h"

void PrintElem(ElemType e) {
    printf("%d,", e);
}

int main(int argc, char** argv) {
    ElemType a[4] = {3, 5, 8, 11};
    ElemType b[7] = {2, 6, 8, 9, 11, 15, 20};

    SqList La, Lb, Lc1, Lc2;
    int i;

    InitList(&La);
    for(i = 1; i<= 4; i++) {
        ListInsert(&La, i, a[i - 1]);
    }

    InitList(&Lb);
    for(i = 1; i<= 7; i++) {
        ListInsert(&Lb, i, b[i-1]);
    }
    printf("La ===");
    ListTraverse(La, PrintElem);

    printf("Lb ===");
    ListTraverse(Lb, PrintElem);

    MergeSqList_1(La, Lb, &Lc1);
    printf("lc1 ===");
    ListTraverse(Lc1, PrintElem);

    MergeSqList_2(La, Lb, &Lc2);
    printf("lc2 ===");
    ListTraverse(Lc2, PrintElem);
    return 0;
}
