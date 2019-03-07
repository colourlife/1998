#define _CRT_SECURE_NO_WARNINGS = 1
#if 0
#include <iostream>
using namespace std;
int main()
{
	int arr[4] = { 0 };
	for (int i = 0; i < 4; ++i)
	{
		cin >> arr[i];
	}

	int m = (arr[2] - arr[0]) / 2;
	int n = (arr[3] - arr[1]) / 2;

	if (m - n == arr[1])
	{
		int k = arr[0] + m;
		if (m >= 0 && n >= 0 && k >= 0)
		{
			cout << k << " " << m << " " << n;
		}
		else
		{
			cout << "No";
		}
	}
	else
		cout << "No";
	return 0;
}

#endif


#include <iostream>
#include <string>

using namespace std;

int main()
{
	string ret;
	int n = 0;
	int k = 0;
	int flag = 1;  //Õý¸º
	cin >> n;
	cin >> k;

	if (n < 0)
	{
		flag = -1;
		n = -n;
	}
	if (n == 0)
	{
		cout << n;
		return 0;
	}
	if (k <= 9)
	{
		if (flag == -1)
			cout << "-";
		if (n < k)
		{
			cout << n;
			return 0;
		}
		while (n >= k)
		{
			char ch = '0';
			ch += n%k;
			ret += ch;
			n /=k;
		}
		cout << n;
		for (int i = ret.length() - 1; i >= 0; --i)
		{
			cout << ret[i];
			if (i == 0)
				break;
		}
	}
	else
	{
		if (flag == -1)
			cout << "-";
		if (n < k)
		{
			if (n == 10)
				cout << 'A';
			if (n == 11)
				cout << 'B';
			if (n == 12)
				cout << 'C';
			if (n == 13)
				cout << 'D';
			if (n == 14)
				cout << 'E';
			if (n == 15)
				cout << 'F';
			if (n < 10)
				cout << n;
			return 0;
		}
		while (n >= k)
		{
			char ch = '0';
			if (n%k < 10)
				ch += (n%k);
			else if (n%k == 10)
				ch = 'A';
			else if (n%k == 11)
				ch = 'B';
			else if (n%k == 12)
				ch = 'C';
			else if (n%k == 13)
				ch = 'D';
			else if (n%k == 14)
				ch = 'E';
			else if (n%k == 15)
				ch = 'F';
			ret += ch;
			n /=k;
		}
		if (n == 10)
			cout << 'A';
		if (n == 11)
			cout << 'B';
		if (n == 12)
			cout << 'C';
		if (n == 13)
			cout << 'D';
		if (n == 14)
			cout << 'E';
		if (n == 15)
			cout << 'F';
		if (n < 10)
			cout << n;

		for (size_t i = ret.length() - 1; i >= 0; --i)
		{
			cout << ret[i];
			if (i == 0)
				break;
		}

	}

	return 0;
}