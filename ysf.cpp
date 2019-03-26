#include <iostream>
#include <vector>
using namespace std;

int LastRemaining_Solution(int n, int m)
{
	vector<int> arr(n);
	int count = 0;
	int i = 0;
	int ret = 0;
	int flag = n;
	if (n == 1)
		return -1;
	while (flag!= 1)
	{
		if (arr[i] == 0)
		{
			count++;
		}
		if (arr[i] == 0 && count == m)
		{
			count = 0;
			arr[i] = 1;
			flag--;
		}
		i = (i + 1) % n;	
	}
	for (i = 0; i < arr.size(); ++i)
	{
		if (arr[i] == 0)
			ret = i;
	}
	return ret;
}

int main()
{
	int c = LastRemaining_Solution(6, 2);
	cout << c;
	return 0;
}