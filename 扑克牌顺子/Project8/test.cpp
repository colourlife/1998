#define _CRT_SECURE_NO_WARNINGS = 1
#include <iostream>
#include <vector>
using namespace std;


bool IsContinuous(vector<int> numbers) {
	if (numbers.size() == 0)
		return false;
	for (size_t i = 0; i<numbers.size(); ++i)
	{
		for (size_t j = 0; j<numbers.size() - i - 1; ++j)
		{
			if (numbers[j]>numbers[j + 1])
			{
				int tmp = numbers[j + 1];
				numbers[j + 1] = numbers[j];
				numbers[j] = tmp;
			}
		}
	}
	int count = 0;
	int sum = 0;
	vector<int> ret;
	ret.resize(numbers.size());
	for (size_t i = 0; i<numbers.size(); ++i)
	{
		if (numbers[i] == 0)
		{
			count++;
			continue;
		}
		if (i < numbers.size() - 1)
		{
			if (numbers[i] == numbers[i + 1])
				return false;
			ret[i] = numbers[i + 1] - numbers[i] - 1;
		}
	}
	for (size_t i = 0; i<numbers.size(); ++i)
	{
		sum += ret[i];
	}
	if (sum <= count)
		return true;
	return false;
}

int main()
{
	vector<int> n{ 1, 3, 0, 0, 7};
	bool er = IsContinuous(n);
	cout << er;
	return 0;
}