#include <stdio.h>
#include "Difference.h"

void PrintElem(ElemType e) {
    printf("%d ", e);
}

int main(int argc, char* argv) {
    SLinkList space;

    int S;

    difference(space, &S, "TestData.txt");

    printf("S difference");

    ListTraverse(space, S, PrintElem);

    return 0;
}
