#include <stdio.h>
#include "SqList.h"

// 判断data>e 是否成立
Status CmpGreater(ElemType data, ElemType e) {
    return data > e ? TRUE : FALSE;
}

// 测试打印函数
void PrintElem(ElemType e){
    printf("%d ", e);
}

int main(int argc, char** argv){
    SqList L;
    int i;
    ElemType e;
    printf("InitList \n");
    {
        printf("初始化顺序表L ...\n");
        InitList(&L);
    }
    PressEnterToContinue(debug);
    printf("ListEmpty \n");
    {
        if(ListEmpty(L) == TRUE) {
            printf("L 为空！！\n");
        } else {
            printf("L 不为空。\n");
        }
    }
    PressEnterToContinue(debug);
    
    printf("ListInsert \n");
    {
        for(i = 1; i<=8; i++){
            printf("在L的第%d个位置插入\"%d\"...\n", i, 2*i);
            ListInsert(&L, i, 2 * i);
        }
    }
    PressEnterToContinue(debug);
    printf("ListTraverse \n");
    {
        printf("L中的元素是：L=");
        ListTraverse(L, PrintElem);
    }
    PressEnterToContinue(debug);
    
    printf("ListLength \n");
    {
        i = ListLength(L);
        printf("L 的长度是 %d\n", i);
    }
    PressEnterToContinue(debug);
    
    printf("ListDelete \n");
    {
        printf("删除前的元素是：L=");
        ListTraverse(L, PrintElem);
        printf("尝试删除L中的第6个元素。。。\n");
        if (ListDelete(&L, 6, &e) == OK) {
            printf("删除成功，删除的元素是：%d \n", e);
        } else {
            printf("删除失败，第6个元素不存在！");
        }
        printf("删除后的元素是：L=");
        ListTraverse(L, PrintElem);
    }
    PressEnterToContinue(debug);
    
    printf("GetElem \n");
    {
        GetElem(L, 4, &e);
        printf("L 中第4个位置的元素为：%d\n", e);
    }
    PressEnterToContinue(debug);
    
    printf("LocateElem \n");
    {
        i = LocateElem(L, 7, CmpGreater);
        printf("L中大于7的元素是%d\n", L.elem[i -1]);   
    }
    PressEnterToContinue(debug);
    
    printf("PriorElem\n");
    {
        ElemType cur_e = 6;
        if(PriorElem(L, cur_e, &e) == OK) {
            printf("元素%d的前驱元素是%d\n", cur_e, e);
        } else {
            printf("元素的%d的前驱元素不存在！\n", cur_e);
        }
    }   
    PressEnterToContinue(debug);
    printf("NextElem\n");   
    {
        ElemType cur_e = 6;
        if(NextElem(L, cur_e, &e) == OK){
            printf("元素%d的后继元素是%d\n", cur_e, e);
        } else {
            printf("元素%d的后继元素不存在！\n", cur_e);    
        }
    }
    PressEnterToContinue(debug);
    printf("ClearList\n");
    {
        printf("清空L前：");
        if(ListEmpty(L) == TRUE){
            printf(" L 为空\n");
        } else {
            printf("L不为空\n");
        }
        ClearList(&L);
        printf("清空L后：");
    
        if(ListEmpty(L) == TRUE){
            printf(" L 为空\n");
        } else {
            printf("L不为空\n");
        }
    }   
    PressEnterToContinue(debug);
    
    printf("DestroyList");
    {
        printf("销毁L后");
        if(L.elem != NULL) {
            printf("L 存在！\n");
        } else {
            printf("L 不存在！\n");
        }
        DestroyList(&L);
        printf("销毁后");
        if(L.elem != NULL) {
            printf("L 存在！\n");
        } else {
            printf("L 不存在！\n");
        }
    }
}
