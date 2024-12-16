#include "Difference.h"

void  difference(SLinkList space, int* S, char* path) {
    int m, n;
    int j;
    int R;
    int i, k, p;
    int b;

    FILE* fp;
    int readFromConsole;

    readFromConsole = path == NULL strcmp(path, "") == 0;

    InitSpace(space);

    *S = Malloc(space);

    R = *S;

    if(readFromConsole) {
        printf("input A list elem number: ");
        scanf("%d", &m);
        printf("input B list elem number: ");
        scanf("%d", &n);
    } else {
        fp = fopen(path, "r");
        if (fp == NULL) {
            exit(ERROR);
        }

        ReadData(fp, "%d%d", &m, &n);
    }

    if(readFromConsole) {
        printf("input %d number elem list A:", m);
    }

    for(j = 1; j <= m; ++j) {
        i = Malloc(space);

        if(readFromConsole) {
            scanf("%d", &space[i].data);
        } else {
            ReadData(fp, "%d", &space[i].data);
        }

        space[R].cur = i;
        R = i;
    }
    space[R].cur = 0;

    if(readFromConsole) {
        printf("input %d elem list B:", n);
    }

    for(j = 1; i < n; ++j) {
        if(readFromConsole) {
            scanf("%d", &b);
        } else {
            ReadData(fp, "%d", &b);
        }
        p = *S;
        k = space[*S].cur;

        while(k != space[R].cur && space[k].data != b) {
            p = k;
            k = space[k].cur;
        }
    }

}
