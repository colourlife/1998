#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	string ret;
	getline(cin, s);
	int i = 0;
	int j = 0;
	while (j<s.size())
	{
		while (s[i] == s[j] && j != s.size())
		{
			j++;
		}
		if (j - 1 - i > 0)
		{
			ret += (char)('0' + j - i - 1);
			ret += s[i];
			i = j-1;
		}
		else
		{
			ret += s[i];
		}
		i++;
		j++;
		cout << ret << endl;
	}
	while (i < j)
	{
		ret += s[i];
		i++;
	}
	cout << ret << endl;
	return 0;
}