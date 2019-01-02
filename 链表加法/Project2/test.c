#define _CRT_SECURE_NO_WARNINGS = 1
//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
//
//如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
//
//您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//
//示例：
//
//输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807

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
	int data2 = 0;   //进位
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
