#include <stdio.h>
#include <Status.h>
#include "LinkList.h"

Status CmpGreater(ElemType data, ElemType e) {
    return data > e ? TRUE : FALSE;
}

void PrintElem(ElemType e){
    printf("%d ", e);
}

int main(int argc, char** argv) {
    LinkList L;
    int i;
    ElemType e;
    printf("InitList \n");
    {
        InitList(&L);
    }
    PressEnterToContinue(debug);
    
    printf("ListEmpty \n");
    {
        ListEmpty(L)? printf("l is empty \n") : printf("l is not empty\n");
    }
    PressEnterToContinue(debug);
    
    printf("ListInsert \n");
    {
        for(i=1; i<=8; i++) {
            printf("in L %d number insert %d \n", i, 2 * i);
            ListInsert(L, i, 2 * i);
        }
    }
    PressEnterToContinue(debug);
    
    printf("ListTraverse \n");
    {
        printf("L = ");
        ListTraverse(L, PrintElem);
    }
    PressEnterToContinue(debug);
    
    printf("ListDelete \n");
    {
        printf("delete before: L=");
        ListTraverse(L, PrintElem);
        if(ListDelete(L, 6, &e) == OK) {
            printf("delete sucess, delete is %d \n", e);
        } else {
            printf("delete error, is not exit");
        }
        printf("delete after is L=");
        ListTraverse(L, PrintElem);
    }
    PressEnterToContinue(debug);
    
    printf("GetElem\n");
    {
        GetElem(L, 4, &e);
        printf("the fourth element is %d \n", e);
    }
    PressEnterToContinue(debug);
    
    printf("LocateElem \n");
    {
        i = LocateElem(L, 7, CmpGreater);
        GetElem(L, i, &e);
        printf("the first element large than 7 is  %d\n", e);
    }
    PressEnterToContinue(debug);
    
    printf("PriorElem\n");
    {
        ElemType cur_e = 6;
        if (PriorElem(L, cur_e, &e) == OK) {
            printf("element %d is prior is %d", cur_e, e);
        } else {
            printf("element %d is prior is not exist");
        }
    }
    PressEnterToContinue(debug);
    
    printf("NextElem \n");
    {
        ElemType cur_e = 6;
        if(NextElem(L, cur_e, &e) == OK) {
            printf("element %d is nextelem is %d\n", cur_e, e);
        } else {
            printf("element %d is nextelem is not exist");
        }
    }
    PressEnterToContinue(debug);
   
    printf("ClearList \n");
    {
        printf("clear before:");
        ListEmpty(L) ? printf("L is empty\n") : printf("L is not empty\n");
        ClearList(L);
        printf("clear after:");
        ListEmpty(L) ? printf("L is empty\n") : printf("L is not empty \n");
    }
    PressEnterToContinue(debug);
    
    printf("DestroyList \n");
    {
        printf("destroy L before");
        L ? printf("L exist\n") : printf("L is not exist\n");
        DestroyList(&L);
        printf("destroy L after");
        L ? printf("L is exist \n") : printf("L is not exist\n");
    }
    PressEnterToContinue(debug);
    
    printf("CreateList_Head \n");
    {
        LinkList L;
        CreateList_Head(&L, 5, "TestData_Head.txt");
        printf("head insert list is L=");
        ListTraverse(L, PrintElem);
    }
    PressEnterToContinue(debug);

    printf("CreateList_Tail \n");
    {
        LinkList L;
        CreateList_Tail(&L, 5, "TestData_Tail.txt");
        printf("taril insert list is L= ");
        ListTraverse(L, PrintElem);
    }
    PressEnterToContinue(debug);
    return 0;
}
