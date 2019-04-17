#include <iostream>
#include <string>
using namespace std;

int main()
{
	string arr;
	cin >> arr;
	int tmp[26] = { 0 };
	for (int i = 0; i<arr.size(); ++i)
	{
		tmp[arr[i] - 'a']++;
	}
	for (int i = 0; i<arr.size(); ++i)
	{
		if (tmp[arr[i]-'a'] == 1)
		{
			cout << arr[i] << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}