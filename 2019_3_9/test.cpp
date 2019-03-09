#define _CRT_SECURE_NO_WARNINGS = 1
//½£Ö¸offer ×Ö·û´®µÄÅÅÁÐ

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#if 0 
void swap(int arr[], int m, int n)
{
	int tmp = arr[m];
	arr[m] = arr[n];
	arr[n] = tmp;
}


void permutation(int arr[], int p, int q)
{
	if (p == q)
	{
		for (int i = 0; i <= q; ++i)
		{
			cout << arr[i];
		}
		cout << endl;
	}
	for (int i = p; i <= q; ++i)
	{
		swap(arr, p, i);
		permutation(arr, p + 1, q);
		swap(arr, p, i);
	}
}
#endif

#if 0
void swap(string& arr, int m, int n)
{
	int tmp = arr[m];
	arr[m] = arr[n];
	arr[n] = tmp;
}

void permutation(vector<string>& ret,string& arr, int p, int q)
{
	if (p == q)
	{
		string c;
		for (int i = 0; i <= q; ++i)
		{
			c += arr[i];
		}
		//cout << endl;
		ret.push_back(c);
	}

	for (int i = p; i <= q; ++i)
	{
		swap(arr, p, i);
		permutation(ret,arr, p + 1, q);
		swap(arr, p, i);
	}
}


vector<string> Permutation(string str) {
	vector<string> ret;
	size_t p = 0;
	size_t q = str.length()-1;
	permutation(ret,str, p, q);
	return ret;
}

int main()
{
	string arr;
	cin >> arr;
	Permutation(arr);
	return 0;
}

#endif

void swap(string& arr, int m, int n)
{
	int tmp = arr[m];
	arr[m] = arr[n];
	arr[n] = tmp;
}

void permutation(vector<string>& ret, string& arr, int p, int q)
{
	if (p == q)
	{
		string c;
		for (int i = 0; i <= q; ++i)
		{
			c += arr[i];
		}
		//cout << endl;
		ret.push_back(c);
	}

	for (int i = p; i <= q; ++i)
	{
		swap(arr, p, i);
		permutation(ret, arr, p + 1, q);
		swap(arr, p, i);
	}
}


vector<string> Permutation(string str) {
	vector<string> ret;
	size_t p = 0;
	size_t q = str.length() - 1;
	permutation(ret, str, p, q);

	int n = ret.size() - 1;
	for (int i = 0; i<=n; ++i)
	{
		for (int k = i + 1; k <= n; k++)
		{
			if (ret[i] == ret[k])
			{
				for (int j = k + 1; j <= n; j++)
				{
					ret[j - 1] = ret[j];
				}
				ret.resize(n);
				n--;
			}
		}
	}
	sort(ret.begin(), ret.end());
	return ret;
}

int main()
{
	string arr;
	cin >> arr;
	Permutation(arr);
	return 0;
}