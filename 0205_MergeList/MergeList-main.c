#include <stdio.h>
#include "MergeList.h"

void PrintElem(ElemType e) {
    printf("%d", e);
}

int main(int argc, char** argv) {
    LinkList La, Lb, Lc;
    int n = 5;
    
    printf("La length is %d, Lb length is %d", n, n);
    
    CreateList_Head(&La, n, "TestData_Head.txt");
    printf("La ==");
    ListTraverse(La, PrintElem);

    CreateList_Tail(&Lb, n, "TestData_Tail.txt");
    printf("Lb ==");
    ListTraverse(Lb, PrintElem);

    printf("merge La and Lb is Lc =");
    MergeList(&La, &Lb, &Lc);
    ListTraverse(Lc, PrintElem);

    return 0;
}
