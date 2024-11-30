#include "SqList.h"

/**
 * 算法2.3
 * 初始化
 */
Status InitList(SqList* L){
	(*L).elem = (ElemType*) malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if((*L).elem == NULL){
		exit(OVERFLOW);
	}
	(*L).length = 0;
	(*L).listsize = LIST_INIT_SIZE;
	return OK;
}

/**
 * 销毁
 */
Status DestroyList(SqList* L){
	if(L == NULL || (*L).elem == NULL){
		return ERROR;
	}
	free((*L).elem);
	(*L).elem = NULL;
	(*L).length = 0;
	(*L).listsize = 0;
	
	return OK;	
}

/**
 * 置空
 */
Status ClearList(SqList* L) {
	if(L == NULL || (*L).elem == NULL) {
		return ERROR;
	}
	
	(*L).length = 0;
	return OK;	
}

/*
 * 判空
 */
Status ListEmpty(SqList L){
	return L.length == 0 ? TRUE: FALSE;
}

/**
 * 计数
 */
int ListLength(SqList L) {
	return L.length;
}

/**
 * 取值
 */
Status GetElem(SqList L, int i, ElemType* e){
	if(i < 1 || i > L.length) {
		return ERROR;		
	}
	*e = L.elem[i -1];
	return OK;	
}

/**
 * 查找
 */
int LocateElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType)) {
	int i;
	ElemType* p;
	
	if(L.elem == NULL) {
		return ERROR;
	}
	i = 1;
	p = L.elem;
	while(i <= L.length && !Compare(*p++, e)) {
		++i;
	}
	
	if(i <= L.length) {
		return i;
	} else {
		return 0;
	}
}

/**
 * 前驱
 */
Status PriorElem(SqList L, ElemType cure_e, ElemType* pre_e) {
	int i;
	if(L.elem == NULL || L.length < 2) {
		return ERROR;		
	}
	
	i = 0;
	
	while(i < L.length && L.elem[i] != cure_e) {
		++i;		
	}
	if(i == 0 || i>= L.length){
		return ERROR;
	}
	*pre_e = L.elem[i -1];
	return OK;
}

/**
 * 获取元素的后继
 */
Status NextElem(SqList L, ElemType cure_e, ElemType* next_e) {
	int i;
	if(L.elem == NULL || L.length < 2) {
		return ERROR;
	}
	i = 0;
        while(i < L.length-1 && L.elem[i] != cure_e) {
		++i;
	}
	if(i >= L.length -1){
		return ERROR;
	}
	*next_e = L.elem[i+1];
	return OK;
}

/**
 * 插入
 */
Status ListInsert(SqList* L,int i, ElemType e) {
	ElemType* newbase;
	ElemType* p, * q;
	
	if(L == NULL || (*L).elem == NULL){
		return ERROR;
	}
	
	if(i < 1 || i> (*L).length +1) {
		return ERROR;
	}
	// 如果存储空间已满，则增加新的空间
	if((*L).length >= (*L).listsize) {
		newbase = (ElemType*) realloc((*L).elem, ((*L).listsize + LISTINCRMENT) * sizeof(ElemType));
		if (newbase == NULL){
			exit(OVERFLOW);
		}
		(*L).elem = newbase;
		(*L).listsize += LISTINCRMENT;
	}
	// q为插入元素的位置
	q = &(*L).elem[i - 1];
	for(p = &(*L).elem[(*L).length - 1]; p >= q; --p){
		*(p + 1) = *p;
	}
	*q = e;
       (*L).length++;
	return OK; 
}
/**
 * 删除
 */
Status ListDelete(SqList* L, int i, ElemType* e){
	ElemType* p, * q;
	if(L == NULL || (*L).elem == NULL){
		return ERROR;
	}
	
	if(i < 1 || i> (*L).length) {
		return ERROR;
	}
	// p为被删除的元素的位置
	p = &(*L).elem[i -1];
	*e = *p;
	// 表尾的元素位置
	q = (*L).elem + (*L).length -1;
	
	for(++p; p <= q; ++p){
		*(p-1) = *p;
	}
	(*L).length --;
	return OK;
}

/**
 * 遍历
 */
void ListTraverse(SqList L, void(Visit)(ElemType)){
	int i;
	for(i = 0; i< L.length; i++){
	 	Visit(L.elem[i]);
	}
	printf("\n");
}
