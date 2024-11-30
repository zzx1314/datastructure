#ifndef SQLIST_H
#define SQLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

/*宏定义*/
#define LIST_INIT_SIZE 100 // 顺序表初始分配空间
#define LISTINCRMENT   10 // 顺序表空间分配增量

/*定义元素类型*/
typedef int ElemType;

/**
 * 顺序表结构
 */
typedef struct {
	ElemType* elem;
	int length;
	int listsize;
} SqList;

/**
 * 算法2.3
 * 初始化
 * 返回值OK,或者ERROR
 */
Status InitList(SqList* L);

/**
 * 销毁（结构）
 * 释放顺序表所占的内存
 */
Status DestroyList(SqList* L);


/**
 * 置空内容
 * 只清理内容，不释放表的内存
 */
Status ClearList(SqList* L);

/**
 * 判空
 */
Status ListEmpty(SqList L);

/**
 * 计数
 */
int gistLength(SqList L);

/**
 * 取值
 */
Status GetElem(SqList L, int i, ElemType* e);

/**
 * 查找
 */
int LocateElem(SqList L, ElemType e, Status(Compara)(ElemType, ElemType));

/**
 * 前驱
 * 获取当前元素的前一个元素
 */
Status PriorElem(SqList L, ElemType cure_e, ElemType* pre_e);

/**
 * 后继
 * 获取后一个元素
 */
Status NextElem(SqList L, ElemType cur_e, ElemType* next_e);

/**
 * 插入元素
 */
Status ListInsert(SqList* L, int i, ElemType e);

/**
 * 删除元素
 */
Status ListDelete(SqList* L, int i, ElemType* e);

/**
 * 遍历
 */
void ListTraverse(SqList L, void (Visit)(ElemType));

#endif
