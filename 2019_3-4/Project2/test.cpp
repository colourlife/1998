#define _CRT_SECURE_NO_WARNINGS = 1
#include <iostream>
#include <vector>
using namespace std;


#if 0
int main()
{
	int n = 0;
	cin >> n;
	vector<int> arr;
	int tmp;

	for (int i = 0; i < 3 * n; ++i)
	{
		cin >> tmp;
		arr.push_back(tmp);
	}

	for (size_t i = 0; i < arr.size(); ++i)
	{
		for (size_t j = 0; j < arr.size() - i - 1; ++j)
		{
			if (arr[j + 1]>arr[j])
			{
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
	int c = 2;
	int k = 1;
	int sum = arr[1];

	while (--n)
	{
		sum += arr[k + c];
		k = k + c;
	}
	cout << sum << endl;

	return 0;
}


#endif
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1;
	string s2;

	getline(cin, s1);
	getline(cin, s2);

	for (size_t i = 0; i < s2.length(); ++i)
	{
		while (1)
		{
			int pos = s1.find(s2[i]);
			if (pos == string::npos)
			{
				break;
			}
			s1.erase(pos,1);
		}
	}
	cout << s1 << endl;

	return 0;
}

