#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define max(x,y) (x)>(y)?(x):(y)
int main()
{
	string s1;
	string s2;
	vector<vector<int>> arr;
	while (cin >> s1 >> s2)
	{
		int m = s1.size();
		int n = s2.size();
		arr.resize(m, vector<int>(n));
		if (s1[0] == s2[0])
			arr[0][0] = 1;
		for (int i = 1; i < m; ++i)
		{
			if (s1[i] == s2[0])
				arr[i][0] = 1;
			arr[i][0] = max(arr[i][0], arr[i - 1][0]);

		}
		for (int j = 1; j < n; ++j)
		{
			if (s1[0] == s2[j])
				arr[0][j] = 1;
			arr[0][j] = max(arr[0][j], arr[0][j-1]);
		}
		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				if (s1[i] == s2[j])
				{
					arr[i][j] = arr[i - 1][j - 1] + 1;
				}
				else
				{
					arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
				}
			}
		}
		cout << arr[s1.size()-1][s2.size()-1] << endl;
		arr.clear();
	}
	return 0;
}