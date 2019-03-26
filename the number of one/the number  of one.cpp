#include <iostream>
using namespace std;

int fun(int n)
{
	int ret = 0;
	int sum = 0;
	while (n)
	{
		ret = n % 10;
		n /= 10;
		if (ret == 1)
			sum++;
	}
	return sum;
}
int NumberOf1Between1AndN_Solution(int n)
{
	int count = 0;
	for (int i = 1; i <= n; ++i)
	{
		count += fun(i);
	}
	return count;
}
int main()
{
	int ret = NumberOf1Between1AndN_Solution(55);
	cout << ret << endl;
	return 0;
}
