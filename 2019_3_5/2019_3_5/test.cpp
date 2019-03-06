#define _CRT_SECURE_NO_WARNINGS = 1

#if 0 
#include <iostream>
#include <string>
using namespace std;


int main()
{
	string s1;
	int count = 0;
	getline(cin, s1);
	for (size_t i = 0; i < s1.length(); ++i)
	{
		if (s1[i] == ' ')
		{
			count++;
		}
	}
	int pos = s1.length()-1;
	int j = pos;
	string s2;
	while (count)
	{
		if (s1[j] != ' ')
			j--;
		else
		{
			for (size_t k = j+1; k <= pos; k++)
			{
				s2 += s1[k];
			}
			s2 += ' ';
			pos = j;
			count--;
			j--;
		}
	}
	for (size_t k = 0; k <= s1.length(); k++)
	{
		if (s1[k] != ' ')
		{
			s2 += s1[k];
		}
		else
			break;
	}

	cout << s2;
	return 0;
}

#endif
#if 0
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1;
	int count = 0;
	getline(cin, s1);
	int pos = s1.length() - 1;
	int end = pos;
	int flag = 0;
	while (pos)
	{
		if (s1[pos] != ' ')
		{
			pos--;
		}
		else
		{
			for (size_t i = pos+1; i <= end; ++i)
			{
				cout << s1[i];
			}
			if (flag == 0)
			{
				cout << ' ';
				flag++;
			}
			end = pos;
			pos--;
		}
	}
	for (size_t j = 0; j < s1.length(); ++j)
	{
		if (s1[j] != ' ')
			cout << s1[j];
		else
			break;
	}

	system("pause");
	return 0;
}

#endif


#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	vector<int> arr(n);
	for (size_t i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	vector<int> cur(n - 1);

	for (size_t i = 0; i < n - 1; ++i)
	{
		if (arr[i + 1] > arr[i])
			cur[i] = 1;
		else if (arr[i + 1] < arr[i])
			cur[i] = 0;
		else
			cur[i] = -1;
	}
	int count = 0;
	for (size_t j = 0; j < n - 1; ++j)
	{
		if (cur[j] * cur[j + 1] == 0)
			count++;
	}
	
	cout << count;

	system("pause");
	return 0;
}