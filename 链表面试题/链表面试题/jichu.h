#define _CRT_SECURE_NO_WARNINGS = 1
#pragma once

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef int DataType;

// 不是链表的结构体
// 链表中一个结点的结构体
typedef struct Node {
	DataType	data;
	struct Node *next;
}	Node;

void SListInit(Node **ppfirst)
{
	assert(ppfirst != NULL);
	*ppfirst = NULL;
}

void SListDestroy(Node *first)
{
	Node *cur, *next;
	for (cur = first; cur != NULL; cur = next) {
		next = cur->next;
		free(cur);
	}
}

// 预处理 -》 编译 -》汇编 -》链接
static Node * CreateNode(DataType data)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	return node;
}

// 头插
void SListPushFront(Node **ppfirst, DataType data)
{
	assert(ppfirst != NULL);

	// 正常情况
	Node *node = CreateNode(data);

	node->next = *ppfirst;
	*ppfirst = node;
}

// 尾插
void SListPushBack(Node **ppfirst, DataType data)
{
	Node *node = CreateNode(data);

	assert(ppfirst != NULL);
	if (*ppfirst == NULL) {
		*ppfirst = node;
		return;
	}

	// 找链表中的最后一个结点	（链表中至少有一个结点）
	Node *cur = *ppfirst;
	while (cur->next != NULL) {
		cur = cur->next;
	}

	cur->next = node;
}

// 删除
// 头删
void SListPopFront(Node **ppfirst)
{
	assert(ppfirst != NULL);
	assert(*ppfirst != NULL);	// 链表不是空链表

	Node *first = *ppfirst;
	*ppfirst = (*ppfirst)->next;
	free(first);
}

void SListPopBack(Node **ppfirst)
{
	assert(ppfirst != NULL);
	assert(*ppfirst != NULL);	// 链表不是空链表

	if ((*ppfirst)->next == NULL) {
		free(*ppfirst);
		*ppfirst = NULL;
		return;
	}

	// 链表中至少有两个结点，才能找倒数第二个
	Node *cur = *ppfirst;
	while (cur->next->next != NULL) {
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
}

void SListPrint(Node *first)
{
	for (Node *cur = first; cur != NULL; cur = cur->next) {
		printf("%d ", cur->data);
	}
	printf("\n");
}



// 查找（顺序查找）
// 找到了，返回所在结点地址，没有找到返回 NULL
Node * SListFind(Node *first, DataType data)
{
	for (Node *cur = first; cur != NULL; cur = cur->next) {
		if (cur->data == data) {
			return cur;
		}
	}

	return NULL;
}

// 插入，在结点 pos 前面插入
void SListInsert(Node **ppfirst, Node *pos, DataType data)
{
	if (*ppfirst == pos) {
		SListPushFront(ppfirst, data);
		return;
	}

	Node *newNode = CreateNode(data);	// *** 不要忘了申请空间
	Node *cur;
	// 找到 pos 前的一个结点
	for (cur = *ppfirst; cur->next != pos; cur = cur->next) {}

	// 改变的是字段内的值，而不是指针的值
	cur->next = newNode;
	newNode->next = pos;
}

// 删除 pos 这个结点	（pos一定在链表中）
void SListErase(Node **ppfirst, Node *pos)
{
	if (*ppfirst == pos) {
		SListPopFront(ppfirst);
		return;
	}

	Node *cur = *ppfirst;
	while (cur->next != pos) {
		cur = cur->next;
	}
	cur->next = pos->next;
	free(pos);	// 不要忘记释放结点
}

void Test()
{
	Node *first;	// 没有初始化
	SListInit(&first);
	// 期望 p == NULL

	// 当对空链表尾插时，first的值还是会变化
	SListPushBack(&first, 0);
	SListPushBack(&first, 1);
	SListPushBack(&first, 2);
	SListPushBack(&first, 3);
	SListPushBack(&first, 4);

	Node *p3 = SListFind(first, 3);
	SListInsert(&first, p3, 25);
	SListPrint(first);
	SListErase(&first, p3);
	SListPrint(first);
}