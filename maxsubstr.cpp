#include <iostream>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
	int maxbegin = 0;
	int maxend = 0;
	int curbegin = 0;
	int curend = 0;
	int i = 0;

	while (curend != s.size())
	{
		for (i = curbegin; i < curend; ++i)
		{
			if (s[i] == s[curend])
			{
				if (curend-curbegin>maxend-maxbegin)
				{
					maxbegin = curbegin;
					maxend = curend-1;
					curbegin = i + 1;
				}
				curbegin = i + 1;
			}
		}
		curend++;
	}

	if (maxend == maxbegin && maxbegin == 0)
	{
		return curend - curbegin;
	}
	return curend - curbegin> maxend - maxbegin + 1 ? curend - curbegin: maxend - maxbegin + 1;
}

int main()
{
	string s = "ggububgvfk";
	cout << lengthOfLongestSubstring(s) << endl;
	return 0;
}