#define _CRT_SECURE_NO_WARNINGS = 1
1.
实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，
输入9，输出9 * 9口诀表，输出12，输出12 * 12的乘法口诀表。

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
使用函数实现两个数的交换。

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
实现一个函数判断year是不是润年。
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
		printf("是闰年\n");
	}
	else
	{
		printf("不是闰年\n");
	}
	system("pause");
	return 0;
}


4.
创建一个数组，
实现函数init（）初始化数组、
实现empty（）清空数组、
实现reverse（）函数完成数组元素的逆置。
要求：自己设计函数的参数，返回值。

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


5.实现一个函数，判断一个数是不是素数。
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
		printf("是素数\n");
	else
		printf("不是素数\n");



	system("pause");
	return 0;
}