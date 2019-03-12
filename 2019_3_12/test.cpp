#define _CRT_SECURE_NO_WARNINGS = 1

#if 0 
#include <iostream>
#include <vector>

using namespace std;
int main()
{
	vector<int> arr;
	arr.push_back(0);
	arr.push_back(1);
	int n = 0;
	cin >> n;
	int i = 2;
	int pos = 0;
	while (1)
	{
		arr.push_back(arr[i - 1] + arr[i - 2]);
		if (arr[arr.size() - 1] > n)
		{
			break;
		}
		i++;
	}

	int ret = (arr[arr.size() - 1] - n) < (n - arr[arr.size() - 2]) ? (arr[arr.size() - 1] - n) : (n - arr[arr.size() - 2]);
	cout << ret;

	return 0;
}
#endif

#include <iostream>
#include <stack>
using namespace std;


bool chkParenthesis(string A, int n) {
	stack<char> s;
	int i = 0;
	while (n--)
	{
		if (A[i] == '(')
		{
			s.push('(');
			i++;
		}
		else if (A[i] == ')')
		{
			if (s.empty())
			{
				return false;
			}
			else if (s.top() == '(')
			{
				s.pop();
				i++;
			}
			//else
			//{
			//	return false;
			//}
		}
		else
			i++;
	}
	if (!s.empty())
	{
		return false;
	}
	return true;
}

int main()
{
	string r = "()a(())";
	bool ret = chkParenthesis(r, 7);


	return 0;
}