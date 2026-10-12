#include"linklist.h"
#include<iostream>
using namespace std;

void CreateListF(LinkNode*& L, ElemType a[], int n) {
	LinkNode* s;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
	for (int i = 0;i < n;i++) {
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = L->next;//新节点指向首节点
		L->next = s;//头节点指向新节点
	}
}
void CreateListR(LinkNode*& L, ElemType a[], int n) {
	LinkNode* s, * r;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	r = L;//r始终指向尾节点初始时指向头节点
	for (int i = 0;i < n;i++) {
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}
//初始化线性表
void InitLIist(LinkNode*& L) {
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
}
//销毁线性表
void DestroyList(LinkNode*& L) {
	LinkNode* pre = L, * p = L->next;//pre指向节点p的前驱节点
	while (p != NULL) {
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
	L = NULL;
}
//判断线性表是否为空
bool ListEmpty(LinkNode* L) {
	return(L->next == NULL);
}
//求线性表的长度
int ListLength(LinkNode* L) {
	int n = 0;
	LinkNode* p = L;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
//输出线性表
void DispList(LinkNode* L) {
	LinkNode* p = L->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
//按位查找
bool GetElem(LinkNode* L, int i, ElemType& e) {
	int j = 0;
	LinkNode* p = L;
	if (i <= 0)return false;
	while (j < i && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else {
		e = p->data;
		return true;
	}
}
//按值查找
int LocateElem(LinkNode* L, ElemType e) {
	int i = 1;
	LinkNode* p = L->next;
	while (p != NULL) {
		p = p->next;
		i++;
	}
	if (p == NULL)
		return 0;
	else
		return i;
}
//插入元素
bool ListInsert(LinkNode*& L, int i, ElemType e) {
	int j = 0;
	LinkNode* p = L, * s;
	if (i <= 0)
		return false;
	while (j < i - 1 && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else {
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
}
//删除元素
bool ListDelete(LinkNode*& L, int i, ElemType& e) {
	int j = 0;
	LinkNode* p = L, * q;
	if (i <= 0)
		return false;
	while (j < i - 1 && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else {
		q = p->next;//此时q指向第i个元素，p指向第i-1个元素
		if (q == NULL)
			return false;
		e = q->data;
		p->next = q->next;
		free(q);
		return true;
	}
}
