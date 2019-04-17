#include <iostream>
#include <vector>
using namespace std;
int fun(int m, int n)
{
	if (m%n == 0)
		return n;
	return fun(n, m%n);
}
int main()
{
	int n = 0;
	int a = 0;		
	vector<int> arr;
	while (cin >> n)
	{
		cin>> a;
		while (n--)
		{
			int tmp = 0;
			cin >> tmp;
			if (a >= tmp)
				a += tmp;
			else
			{
				a += fun(a, tmp);
			}
		}
		cout << a << endl;
	}
	return 0;
}