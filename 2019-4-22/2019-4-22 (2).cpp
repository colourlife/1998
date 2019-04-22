#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
bool fun(int a)
{
	for (int i = 3; i < sqrt(a); ++i)
	{
		if (a%i == 0)
			return false;
	}
	return true;
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		int tmp = n;
		vector<int> arr;
		for (int i = 2; i <= sqrt(n); ++i)
		{
			if (n%i == 0 && fun(i))
			{
				while (n%i == 0)
				{
					arr.push_back(i);
					n /= i;
				}
			}
		}
		if (n != 1)
			arr.push_back(n);
		cout << tmp << " = ";
		for (int i = 0; i < arr.size() - 1; ++i)
			cout << arr[i] << " * ";
		cout << arr[arr.size() - 1] << endl;
	}

	return 0;
}