#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
	string s1;
	string s2;
	int len1;
	int len2;
	vector<int> arr;
	while (cin >> s1 >> s2 >> len1 >> len2)
	{
		s1.append(len2 - s1.size(),'a');
		s1.append(len2 - s2.size(), char('z' + 1));
		for (int i = 0; i < len2; ++i)
		{
			arr.push_back(s2[i] - s1[i]);
		}
		int ret = 0;
		for (int i = len1; i <=len2; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				ret += arr[j] * pow(26, i - j - 1);
			}
		}
		arr.clear();
		cout << ret-1 << endl;
	}
	return 0;
}