#define _CRT_SECURE_NO_WARNINGS = 1
#pragma once

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef int DataType;

// ��������Ľṹ��
// ������һ�����Ľṹ��
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

// Ԥ���� -�� ���� -����� -������
static Node * CreateNode(DataType data)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	return node;
}

// ͷ��
void SListPushFront(Node **ppfirst, DataType data)
{
	assert(ppfirst != NULL);

	// �������
	Node *node = CreateNode(data);

	node->next = *ppfirst;
	*ppfirst = node;
}

// β��
void SListPushBack(Node **ppfirst, DataType data)
{
	Node *node = CreateNode(data);

	assert(ppfirst != NULL);
	if (*ppfirst == NULL) {
		*ppfirst = node;
		return;
	}

	// �������е����һ�����	��������������һ����㣩
	Node *cur = *ppfirst;
	while (cur->next != NULL) {
		cur = cur->next;
	}

	cur->next = node;
}

// ɾ��
// ͷɾ
void SListPopFront(Node **ppfirst)
{
	assert(ppfirst != NULL);
	assert(*ppfirst != NULL);	// �����ǿ�����

	Node *first = *ppfirst;
	*ppfirst = (*ppfirst)->next;
	free(first);
}

void SListPopBack(Node **ppfirst)
{
	assert(ppfirst != NULL);
	assert(*ppfirst != NULL);	// �����ǿ�����

	if ((*ppfirst)->next == NULL) {
		free(*ppfirst);
		*ppfirst = NULL;
		return;
	}

	// ������������������㣬�����ҵ����ڶ���
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



// ���ң�˳����ң�
// �ҵ��ˣ��������ڽ���ַ��û���ҵ����� NULL
Node * SListFind(Node *first, DataType data)
{
	for (Node *cur = first; cur != NULL; cur = cur->next) {
		if (cur->data == data) {
			return cur;
		}
	}

	return NULL;
}

// ���룬�ڽ�� pos ǰ�����
void SListInsert(Node **ppfirst, Node *pos, DataType data)
{
	if (*ppfirst == pos) {
		SListPushFront(ppfirst, data);
		return;
	}

	Node *newNode = CreateNode(data);	// *** ��Ҫ��������ռ�
	Node *cur;
	// �ҵ� pos ǰ��һ�����
	for (cur = *ppfirst; cur->next != pos; cur = cur->next) {}

	// �ı�����ֶ��ڵ�ֵ��������ָ���ֵ
	cur->next = newNode;
	newNode->next = pos;
}

// ɾ�� pos ������	��posһ���������У�
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
	free(pos);	// ��Ҫ�����ͷŽ��
}

void Test()
{
	Node *first;	// û�г�ʼ��
	SListInit(&first);
	// ���� p == NULL

	// ���Կ�����β��ʱ��first��ֵ���ǻ�仯
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