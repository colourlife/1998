#define _CRT_SECURE_NO_WARNINGS = 1
1.
ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ����
����9�����9 * 9�ھ������12�����12 * 12�ĳ˷��ھ���

#include <stdio.h>
void fun(int a)
{
	int i = 0;
	int n = 0;
	for (i = 1; i <= a; i++)
	{
		for (n = 1; n <= i; n++)
		{
			printf("%d*%d= %d     ", i, n, i*n);
		}
		printf("\n");
	}
	
}





int main()
{
	int m = 0;
	scanf("%d", &m);
	fun(m);
	system("pause");
	return 0;
}







2.
ʹ�ú���ʵ���������Ľ�����

#include<stdio.h>

int fun2(int *a, int *b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;

}

int main()
{
	int m = 0;
	int n = 0;
	scanf("%d %d", &m,&n);
	fun2(&m, &n);
	printf("%d,%d\n", m, n);
	system("pause");
	return 0;
}
3.
ʵ��һ�������ж�year�ǲ������ꡣ
#include <stdio.h>
int fun3(int m)
{
	
	return ((m % 4 == 0) && (m % 100 != 0) || (m % 400 == 0));;

	
}
int main()
{
	int i = 0;
	scanf("%d", &i);

	if (fun3(i))
	{
		printf("������\n");
	}
	else
	{
		printf("��������\n");
	}
	system("pause");
	return 0;
}


4.
����һ�����飬
ʵ�ֺ���init������ʼ�����顢
ʵ��empty����������顢
ʵ��reverse���������������Ԫ�ص����á�
Ҫ���Լ���ƺ����Ĳ���������ֵ��

#include <stdio.h>
#include <string.h>
void init(int *a[])
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		a[i] = i;
	}

}


void reverse(int *a[])
{
	
	int i = 0;
	int m[10] = { 0 };
	init(a);
	for (i = 0; i < 10; i++)
	{
		m[9 - i] = a[i];
	}
	for (i = 0; i < 10; i++)
	{
		a[i] = m[i];
	}
}


void empty(int *a[])
{
	int i = 0;
	
	for (i = 0; i < 10; i++)
	{
		a[i] = 0;
	}
}
int main()
{
	int a[10] = { 0 };
	int i = 0;
	init(a);
	for (i = 0; i < 10; i++)
	{
	printf("%d", a[i]);
	}
	printf("\n");
	reverse(a);
	for (i = 0; i < 10; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
	
	empty(a);
	for (i = 0; i < 10; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
	
	system("pause");
	return 0;
}


5.ʵ��һ���������ж�һ�����ǲ���������
#include <stdio.h>

int fun5(int a)
{
	int n = 0;
	if (a % 2 == 0)
		return 0;
	for (n = 3; n <= a / 2; n += 2)
	{
		if (a%n == 0)
			return 0;
	}
	return 1;
}



int main()
{
	int i = 0;
	scanf("%d", &i);
	if (fun5(i))
		printf("������\n");
	else
		printf("��������\n");



	system("pause");
	return 0;
}