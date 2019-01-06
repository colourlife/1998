#define _CRT_SECURE_NO_WARNINGS = 1
#include "jichu.h"

//�����ӡ������
void TailPrint(Node *first)
{
	Node *last = NULL;
	while (last!=NULL)
	{
		Node *cur = first;
		while (cur->next != last)
		{
			cur = cur->next;
		}
		printf("%d", cur->data);
		last = cur;
	}
}

void TailPrintRec(Node *first)
{
	if (first == NULL)
	{
		return;
	}
	TailPrintRec(first->next);
	printf("%d", first->data);
}

//ɾ��һ��ָ�����
void RemoveNoHeadNotTail(Node *node)
{
	node->data = node->next->data;
	Node*cur = node->next;
	node->next = node->next->next;
	free(cur);
}

//����ͷ����Ľ��ǰ����һ������
void InsertBeforeNode(Node *node, DataType data)
{
	Node *cur = CreateNode(data);
	cur->data = node->data;
	cur->next = node->next;
	node->next = cur;
	node->data = data;

}