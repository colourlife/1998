#define _CRT_SECURE_NO_WARNINGS = 1
//�������� �ǿ� ������������ʾ�����Ǹ������������У����Ǹ��Ե�λ���ǰ��� ���� �ķ�ʽ�洢�ģ��������ǵ�ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�
//
//��������ǽ��������������������᷵��һ���µ���������ʾ���ǵĺ͡�
//
//�����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��
//
//ʾ����
//
//���룺(2 -> 4 -> 3) + (5 -> 6 -> 4)
//�����7 -> 0 -> 8
//ԭ��342 + 465 = 807

#include <stdio.h>

 struct ListNode {
     int val;
     struct ListNode *next;
 };


#if 0 

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* first = l1;
	struct ListNode* second = l2;
	int n = 1;
	int data;
	int data1 = 0;
	int data2 = 0;
	while (first->next != NULL)
	{
		data1 += (n*first->val);
		first = first->next;
		n = n * 10;
	}
	n = 1;
	while (second->next != NULL)
	{
		data1 += (n*second->val);
		second = second->next;
		n = n * 10;
	}
	data = data1 + data2;


	struct ListNode* ret = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* result = ret;
	while (data > 10)
	{
		struct ListNode* cur1 = (struct ListNode*)malloc(sizeof(struct ListNode));
		cur1->val = data % 10;
		data = data / 10;
		cur1->next = NULL;
		ret->next = cur1;
		ret = ret->next;
	}
	struct ListNode* cur2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	cur2->val = data;
	cur2->next = NULL;

	ret->next = cur2;
	return result->next;
}

#endif



struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* first = l1;
	struct ListNode* second = l2;

	int data = 0;
	int data1 = 0;
	int data2 = 0;   //��λ
	int cur = 0;
	struct ListNode* ret = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* result = ret;
	while (first != NULL && second != NULL)
	{
		data = first->val + second->val + data2;
		//data1 = data % 10;
		struct ListNode* cur1 = (struct ListNode*)malloc(sizeof(struct ListNode));
		cur1->val = data % 10;
		cur1->next = NULL;
		ret->next = cur1;
		ret = ret->next;
		first = first->next;
		second = second->next;
		if (data >= 10)
		{
			data2 = 1;
		}
		else
			data2 = 0;
	}



	if (first == NULL &&  second != NULL)
	{
		while (second != NULL)
		{
			struct ListNode* cur1 = (struct ListNode*)malloc(sizeof(struct ListNode));
			cur1->val = (data2 + second->val) % 10;
			cur1->next = NULL;
			ret->next = cur1;
			ret = ret->next;
			data2 = (data2 + second->val) / 10;
			second = second->next;
		}

	}
	else if (second == NULL &&  first != NULL)
	{
		while (first != NULL)
		{
			struct ListNode* cur1 = (struct ListNode*)malloc(sizeof(struct ListNode));
			cur1->val = (data2 + first->val) % 10;
			cur1->next = NULL;
			ret->next = cur1;
			ret = ret->next;
			data2 = (data2 + first->val) / 10;
			first = first->next;
		}
	}

	if (data2 != 0)
	{
		struct ListNode* cur1 = (struct ListNode*)malloc(sizeof(struct ListNode));
		cur1->val = 1;
		cur1->next = NULL;
		ret->next = cur1;
	}


	return result->next;
}
