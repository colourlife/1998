#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> arr;
int sum = 0;
int dfs(int begini, int beginj)
{
	if (beginj - 1 >= 0 && arr[begini][beginj - 1] == '.')
	{
		sum++;
		arr[begini][beginj-1] = '#';
		dfs( begini, beginj - 1) ;
	}
	if (beginj + 1 < arr[0].size() && arr[begini][beginj +1] == '.')
	{
		sum++;
		arr[begini][beginj+1] = '#';
		dfs(begini, beginj + 1);
	}
	if (begini + 1 < arr.size() && arr[begini+1][beginj] == '.')
	{
		sum++;
		arr[begini+1][beginj] = '#';
		dfs( begini+1, beginj);
	}
	if (begini - 1 >= 0 && arr[begini - 1][beginj] == '.')
	{
		sum++;
		arr[begini-1][beginj] = '#';
		dfs(begini - 1, beginj);
	}
	return sum;
}
int main()
{
	int m, n;
	int starti, startj;
	while (cin >> m >> n)
	{
		arr.resize(m);
		for (int i = 0; i < m; ++i)
		{
			arr[i].resize(n);
		}
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> arr[i][j];
				if (arr[i][j] == '@')
				{
					starti = i;
					startj = j;
				}
			}
		}
		int r = dfs(starti, startj) + 1;
		cout << r << endl;
		sum = 0;
		arr.clear();
	}
	return 0;
}