#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n = 0;
	while (cin >> n)
	{
		string tmp;
		vector<string> arr;
		getchar();
		for (int i = 0; i<n; ++i)
		{
			getline(cin, tmp);
			arr.push_back(tmp);
		}
		for (int i = 0; i<n; ++i)
		{
			if (i == n - 1)
			{
				if ((arr[i].find(',') >= 0 && arr[i].find(',')<arr[i].size()) || (arr[i].find(' ') >= 0 && arr[i].find(' ')<arr[i].size()))
					cout << "\"" << arr[i] << "\"" << endl;
				else
					cout << arr[i] << endl;
				continue;
			}
			if ((arr[i].find(',') >= 0 && arr[i].find(',')<arr[i].size()) || (arr[i].find(' ') >= 0 && arr[i].find(' ')<arr[i].size()))
				cout << "\"" << arr[i] << "\"" << "," << " ";
			else
				cout << arr[i] << ", ";
		}
	}
	return 0;
}