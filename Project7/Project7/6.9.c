#define _CRT_SECURE_NO_WARNINGS = 1

//1.��ɲ�������Ϸ��
//




#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void meau()

{
	printf("********************************\n");
	printf("***********1.��ʼ��Ϸ***********\n");
	printf("***********0.�˳���Ϸ***********\n");
	printf("********************************\n");
}

void game()
{
	int random_num = rand() % 100 + 1;
	int a = 0;
	while (1)
	{
		printf("������Ҫ�²������:");
		scanf("%d", &a);
		if (a > random_num)
		{
			printf("�´���");
		}
		else if (a < random_num)
		{
			printf("��С��");
		}
		else
		{
			printf("��ϲ��¶��ˣ�\n");
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
		printf("��ѡ��>:");
		scanf("%d", &input);
		switch(input)
		{
			case 1:game();
				break;
			case 0:
				break;
			default:
				printf("ѡ���������������:");
				break;
		}

	} while (input);
		


	system("pause");
	return 0;
}





//2.д����������������������в�����Ҫ�����֣��ҵ��˷����±꣬�Ҳ������� - 1.���۰���ң�
//



//#include <stdio.h>
//int main()
//{
//	int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int i = 0;
//	int sz = sizeof(a) / sizeof(a[0])-1;
//	int left = 0;
//	int right = 0;
//	printf("������һ����:");
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
//3.��д����ģ��������������ĳ�����


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
//		printf("����������:");
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
//		printf("������ȷ\n");
//	}
//
//
//
//	system("pause");
//	return 0;
//}
//����������������룬������ȷ����ʾ����¼�ɹ���, ������󣬿����������룬����������Ρ����ξ�������ʾ�˳�����
//
//4.��дһ�����򣬿���һֱ���ռ����ַ��������Сд�ַ��������Ӧ�Ĵ�д�ַ���������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ�����������ֲ������


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