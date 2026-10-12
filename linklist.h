#ifndef _LINKLIST_H_
#define _LINKLIST_H_

typedef 
int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LinkNode;
//建立单链表
void CreateListF(LinkNode*& L, ElemType a[], int n);//头插法建立单链表
void CreateListR(LinkNode*& L, ElemType a[], int n);//尾插法建立单链表
//初始化线性表
void InitLIist(LinkNode*& L);
//销毁线性表
void DestroyList(LinkNode*& L);
//判断线性表是否为空
bool ListEmpty(LinkNode* L);
//求线性表的长度
int ListLength(LinkNode* L);
//输出线性表
void DispList(LinkNode* L);
//按位查找
bool GetElem(LinkNode* L, int i, ElemType& e);
//按值查找
int LocateElem(LinkNode* L, ElemType e);
//插入元素
bool ListInsert(LinkNode*& L, int i, ElemType e);
//删除元素
bool ListDelete(LinkNode*& L, int i, ElemType& e);

#endif