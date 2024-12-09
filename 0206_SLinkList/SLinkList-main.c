#include <stdio.h>
#include "Status.h"
#include "SLinkList.h"

Status CmpGreater(ElemType data, ElemType e) {
    return data > e ? TRUE : FALSE;
}

void PrintElem(ElemType e) {
    printf("%d ", e);
}

int main(int argc, char** argv) {
    SLinkList space;
    int S;

    int i;
    ElemType e;
    printf("InitList \n");
    {
        InitList(space, &S);
    }
    PressEnterToContinue(debug);

    printf("ListEmpth \n");
    {
        ListEmpty(space, S) ? printf("S is empth!\n") : printf("S is not empty \n");
    }
    PressEnterToContinue(debug);

    printf("ListInsert \n");
    {
        for(i = 1; i < 8; i++) {
            printf("in S %d insert %d...\n", i, 2*i);
            ListInsert(space, S, i, 2*i);
        }
    }
    PressEnterToContinue(debug);
    
    printf("ListTraverse \n");
    {
        printf("S in elem: S = ");
        ListTraverse(space, S, PrintElem);
    }
    PressEnterToContinue(debug);

    printf("ListLength \n");
    {
        printf("S is length %d \n", ListLength(space, S));
    }
    PressEnterToContinue(debug);

    printf("ListDelete \n");
    {
        printf("delete is before S=");
        ListTraverse(space, S, PrintElem);

        printf("delete S frist 6 elem \n");

       /* if(ListDelete(space, S, 6, &e) == OK) {
            printf("delete sucess, delete is %d", e);
        } else {
            printf("delete fail, 6 elem is not exist");
        }*/

        printf("delete after: S=");
        ListTraverse(space, S, PrintElem);
    }
    PressEnterToContinue(debug);

    printf("GetElem\n");
    {
        GetElem(space, S, 4, &e);
        printf("in S frist 4 is elem %d \n", e);
    }
    PressEnterToContinue(debug);

    printf("LocateElem \n");
    {
        i = LocateElem(space, S, 7, CmpGreater);
        GetElem(space, S, i, &e);
        printf("in S one frist >7 elem is %d \n", e);
    }
    PressEnterToContinue(debug);

    printf("PriorElem \n");
    {
        ElemType cur_e = 6;
        if(PriorElem(space, S, cur_e, &e) == OK) {
            printf("elem %d prior elem is %d \n", cur_e, e);
        } else {
            printf("elem %d prior elem is not exist!\n");
        }
    }
    PressEnterToContinue(debug);

    printf("NextElem \n");
    {
        ElemType cur_e = 6;
        
        if(NextElem(space, S, cur_e, &e) == OK) {
            printf("elem %d next is %d \n", cur_e, e);
        } else {
            printf("elem %d next is not exist\n", cur_e);
        }
    }
    PressEnterToContinue(debug);

    printf("ClearList \n");
    {
        printf("clear S before\n");
        ListEmpty(space, S) ? printf("S is empty\n") : printf("S is not empty\n");

        ClearList(space, S);

        printf("clear S after \n");
        ListEmpty(space, S)? printf("S is empty\n") : printf("S is not empty\n");
    }
    PressEnterToContinue(debug);

    printf("DestroyList \n");
    {
        printf("destroy S before\n");
        S != 0 ? printf("S exist\n") : printf("S is not exist \n");

        DestroyList(space, &S);

        printf("destroy S after:\n");
        S != 0 ? printf("S is exist\n") : printf("S is not exist\n");
    }
    return 0;

}
