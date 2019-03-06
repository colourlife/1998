#define _CRT_SECURE_NO_WARNINGS = 1
#if 0
#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int n = 0;
	int i = 0;
	vector<int> arr(100);
	int count = 0;
	while (cin >> n)
	{
		arr[i] = n;
		++i;
		++count;
	}
	int ret[100] = { 0 };

	for (int j = 0; j < count; j++)
	{
		ret[arr[j]]++;
	}
	for (int j = 0; j < 100; j++)
	{
		if (ret[j]>=count / 2)
		{
			cout << j;
		}
	}
	return 0;
}

#endif


#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	string s1;
	int fast = 0;
	int slow = 0;
	getline(cin, s1);
	if (s1.empty())
		return 0;
	int length = s1.length();
	vector<int> cur(length);

	while (fast <= length - 1)
	{
		if (s1[fast] - '0' > 9)
		{
			++fast;
		}
		else
		{
			slow = fast;
			while (s1[fast] - '0' <= 9 && fast <= length - 1)
			{
				fast++;
			}
			cur[slow] = fast - slow;
		}
	}
	int max = 0;
	for (int i = 0; i < length; ++i)
	{
		if (cur[i]>max)
		{
			max = cur[i];
		}
	}
	for (int i = 0; i < length; ++i)
	{
		if (cur[i] == max)
		{
			for (int j = i; j < i+max; ++j)
			{
				cout << s1[j];
			}
			cout << endl;
		}
	}
	return 0;
}