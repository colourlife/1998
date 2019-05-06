#define _CRT_SECURE_NO_WARNINGS = 1

#if 0
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1;
	getline(cin, s1);
	string ret;
	int i = s1.size() - 1;

	while (i>=0)
	{
		int tmp = i;
		while (s1[i] != ' '&&i != 0)
		{
			i--;
		}
		if (i == 0)
			i--;
		for (int j = i + 1; j <= tmp; ++j)
		{
			ret += s1[j];
		}
		i--;
		if (i>=0)
			ret += ' ';
	}
	cout << ret << endl;
	return 0;
}


#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1;
	string s2;
	getline(cin , s1);
	getline(cin , s2);
	for (int i = 0; i < s2.size(); ++i)
	{
		for (int j = 0; j < s1.size(); ++j)
		{
			if (s1[j] == s2[i])
			{
				for (int k = j; k < s1.size() - 1; k++)
				{
					s1[k] = s1[k + 1];
				}
				s1.pop_back();
			}
		}
	}
	cout << s1 << endl;

	return 0;
}

#endif
#include <iostream>
#include <vector>
using namespace std;
void fun(int n, int m, vector<int>v, int beg)
{
	if (m == 0)
	{
		for (int i = 0; i < v.size(); ++i)
		{
			i == 0 ? cout << v[i] : cout << " "<<v[i];
		}
		cout << endl;
	}
	for (int i = beg; i <= n&&i <= m; ++i)
	{
		v.push_back(i);
		fun(n, m - i, v, i + 1);
		v.pop_back();
	}
}
int main()
{
	int n = 0;
	int m = 0;
	cin >> n >> m;
	vector<int> v;
	fun(n, m, v, 1);
	return 0;
}
