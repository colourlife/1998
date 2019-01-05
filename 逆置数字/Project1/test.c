#define _CRT_SECURE_NO_WARNINGS = 1
#include <stdio.h>
#include <math.h>

int reverse(int x) {
	int cur = x;
	int ret = x;
	int count = 1;
	//判断正负
	if (x<0)
	{
		count = 0;
		cur = -x;
		ret = -x;
	}

	//判断位数
	int n = 1;
	while (cur != 1)
	{
		cur = cur/10;
		n++;
	}
	//逆向相加


	int sum = 0;
	while (n--)
	{
		sum = sum * 10 + ret % 10;
		ret /= 10;
	}
	if (count == 1)
	{
		return sum;
	}
	return -sum;
}


int main()
{
	int n = 123454356;
	int ret = reverse(n);
	printf("%d", ret);
	system("pause");
	return 0;
}















//给出二叉树的根，找出出现次数最多的子树元素和。一个结点的子树元素和定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。
//然后求出出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的元素（不限顺序）。
//#include <stdio.h>
//
//typedef struct TreeNode {
//	int val;
//	struct TreeNode *left;
//	struct TreeNode *right;
//}TreeNode;
//int* findFrequentTreeSum(TreeNode* root, int* returnSize) {
//	if (root == NULL)
//	{
//		return NULL;
//	}
//	if (root->left == NULL&&root->right == NULL)
//	{
//		return root->val;
//	}
//	TreeNode *left = root->left;
//	TreeNode *right = root->right;
//	int sum = root->val;
//	while (left != NULL)
//	{
//		sum += left->val;
//	}
//	while (right != NULL)
//	{
//		sum += right->val;
//	}
//
//}

//#include <stdio.h>
//
//int fun(int a)
//{
//	if (a<2)
//		return 1;
//	return fun(a - 1) + fun(a - 2);
//}
//
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[30];
//	for (int i = 0; i<n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (int j = 0; j<n; j++)
//	{
//		printf("%d\n", fun(arr[j]));
//	}
//	system("pause");
//	return 0;
//}


#include <stdio.h>

//int Sum(int a)
//{
//	int sum =0 ;
//	for (int i = 1; i <= a; i++)
//	{
//		sum += i;
//	}
//	return sum;
//
//}
//int main()
//{
//	int arr[100];
//	int n = 0;
//	for (int i = 0; i < 100; i++)
//	{
//		scanf("%d", &arr[i]);
//		if (arr[i] == 0)
//		{
//			n = i;
//			break;
//		}
//	}
//
//	for (int j = 0; j < n; j++)
//	{
//		printf("%d\n", Sum(arr[j]));
//	}
//
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int arr[100] = { 0 };
//	char ch;
//	int i = 0;
//	int j = 1;
//	while (EOF)
//	{
//		scanf("%d", &arr[i]);
//		scanf("%d", &arr[j]);
//		i += 2;
//		j += 2;
//	}
//
//	for (int i = 0; i < 100; i += 2)
//	{
//		printf("%d\n", arr[i] + arr[i + 1]);
//	}
//	
//
//	system("pause");
//	return 0;
//}

//int partitionDisjoint(int* A, int ASize) {
//	int cur1 = 1;
//	int cur2 = 0;
//	int max = cur2;
//	for (int i = 1; i < ASize; i++)
//	{
//
//		if (A[cur1] >= A[max])
//		{
//			cur1++;
//		}
//		else
//		{
//			cur2 = cur1;
//			cur1++;
//		}
//		for (int m = 0; m <= cur2; m++)
//		{
//			if (A[m]>A[max])
//			{
//				max = m;
//			}
//		}
//	}
//	return cur2 + 1;
//}
//
//int fun(int n)
//{
//	if (n < 3)
//		return 1;
//	return fun(n - 1) + fun(n - 2);
//}
//
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[n];
//	printf("%d", fun(n));
//
//	system("pause");
//	return 0;
//}




























//#include <stdio.h>
//
//
//
//int hasGroupsSizeX(int* deck, int deckSize) {
//	int arr[10000] = { 0 };
//	for (int i = 0; i < 10000; i++)
//	{
//		for (int j = 0; j < deckSize; j++)
//		{
//			if (*(deck + j) == i)
//				arr[i]++;
//		}
//	}
//	int n = 0;
//	int flag = 1;
//	for (int i = 0; i < 10000; i++)
//	{
//		if (arr[i] != 0)
//		{
//			if (arr[i] != 1)
//			{
//				if (flag)
//				{
//					n = arr[i];
//					flag = 0;
//					continue;
//				}
//			}
//			if (arr[i] == 1)
//			{
//				return 0;
//			}
//			if (arr[i]与n的最大公因数大于等于二)
//			{
//				return 0;
//			}
//
//		}
//	}
//	if (n == 0)
//		return 0;
//	return 1;
//}
//int main()
//{
//	int arr[] = { 1, 1, 2,2,2,2 };
//	printf("%d",hasGroupsSizeX(arr, 8));
//	system("pause");
//	return 0;
//}
//{
//	int n = 0;
//	int ret = 0;
//
//	scanf("%d", &n);
//	if (n == 0)
//	{
//		return 0;
//	}
//
//	for (int j = 1; j<=n; j++)
//	{
//		ret+=j;
//	}
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}