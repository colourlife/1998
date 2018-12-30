#define _CRT_SECURE_NO_WARNINGS = 1

//1.完成猜数字游戏。
//




#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void meau()

{
	printf("********************************\n");
	printf("***********1.开始游戏***********\n");
	printf("***********0.退出游戏***********\n");
	printf("********************************\n");
}

void game()
{
	int random_num = rand() % 100 + 1;
	int a = 0;
	while (1)
	{
		printf("请输入要猜测的数字:");
		scanf("%d", &a);
		if (a > random_num)
		{
			printf("猜大了");
		}
		else if (a < random_num)
		{
			printf("猜小了");
		}
		else
		{
			printf("恭喜你猜对了！\n");
			break;
		}
	}
}


int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		meau();
		printf("请选择>:");
		scanf("%d", &input);
		switch(input)
		{
			case 1:game();
				break;
			case 0:
				break;
			default:
				printf("选择错误，请重新输入:");
				break;
		}

	} while (input);
		


	system("pause");
	return 0;
}





//2.写代码可以在整型有序数组中查找想要的数字，找到了返回下标，找不到返回 - 1.（折半查找）
//



//#include <stdio.h>
//int main()
//{
//	int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int i = 0;
//	int sz = sizeof(a) / sizeof(a[0])-1;
//	int left = 0;
//	int right = 0;
//	printf("请输入一个数:");
//	scanf("%d", &i);
//	right = sz;
//	int tmp = (left + right) / 2;
//
//
//	while (i != a[tmp]&&left<=right)
//	{
//		tmp = (left + right) / 2;
//		if (i > a[tmp])
//		{
//			left = tmp+1;
//			
//		}
//		else if (i < a[tmp])
//		{
//			right =tmp-1;
//			
//		}
//
//	}
//
//	if (i == a[tmp])
//		printf("%d\n", tmp-1);
//	else 
//		printf("-1\n");
//
//	system("pause");
//	return 0;
//}
//3.编写代码模拟三次密码输入的场景。


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int a[6] = { 123456 };
//	int b[6] = { 0 };
//	int i = 0;
//	int count = 0;
//
//
//
//
//	while (count < 3)
//	{
//		printf("请输入密码:");
//		scanf("%d", &b);
//		if (strcmp(a, b) == 0)
//		{
//			break;
//		}
//		else
//			count++;
//	}
//	if (count < 3)
//	{
//		printf("密码正确\n");
//	}
//
//
//
//	system("pause");
//	return 0;
//}
//最多能输入三次密码，密码正确，提示“登录成功”, 密码错误，可以重新输入，最多输入三次。三次均错，则提示退出程序。
//
//4.编写一个程序，可以一直接收键盘字符，如果是小写字符就输出对应的大写字符，如果接收的是大写字符，就输出对应的小写字符，如果是数字不输出。


//#include <stdio.h>
//int main()
//{
//	int m = 0;
//	scanf("%d", &m);
//	while ((m = getchar()) != EOF)
//	{
//		if (m >= 'a' && m <= 'z')
//			{
//				putchar(m-32);
//			}
//		else if(m>='A' && m<='Z')
//			{
//				putchar(m+32);
//			}
//		else if(m>='0' && m<='9')
//			{
//						;
//			}
//		else
//			{
//			putchar(m);
//			}
//	}
//	
//	
//	system("pause");
//	return 0;
//}