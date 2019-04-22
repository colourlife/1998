#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	vector<int> arr;
	int a = 1;
	int b = 1;
	int c = 1;
	arr.push_back(1);
	for (int i = 2; i < 100001; ++i)
	{
		c = a + b;
		a = b;
		b = c;
		if (c >= 1000000)
		{
			c = c % 1000000;
			b = c;
		}
		arr.push_back(c);
	}
	while (cin >> n)
	{
		if (n < 30)
			cout << arr[n - 1] << endl;
		else
		{
			if (arr[n - 1] >= 100000)
			{
				cout << arr[n - 1] << endl;
				continue;
			}
			if (arr[n - 1] >= 10000)
			{
				cout << "0" << arr[n - 1] << endl;
				continue;
			}
			
			if (arr[n - 1] >= 1000)
			{
				cout << "00" << arr[n - 1] << endl;
				continue;
			}
			if (arr[n - 1] >= 100)
			{
				cout << "000" << arr[n - 1] << endl;
				continue;
			}
				
			if (arr[n - 1] >= 10)
			{
				cout << "0000" << arr[n - 1] << endl;
				continue;
			}
				
			if (arr[n - 1] >= 1)
			{
				cout << "00000" << arr[n - 1] << endl;
				continue;
			}		
		}
	}
	return 0;
}