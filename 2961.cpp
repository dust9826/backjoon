#include <iostream>
#include <vector>
using namespace std;

int n;
int min1;
vector<pair<int, int>> arr;

void Func(int index, pair<int, int> a)
{
	if (index == n)
	{
		if (a.second == 0)
			return;
		int b = a.first - a.second;
		if (b < 0)
			b *= -1;
		if (min1 > b)
			min1 = b;
		return;
	}
	Func(index + 1, a);
	a.first *= arr[index].first;
	a.second += arr[index].second;
	Func(index + 1, a);
}

int main()
{
	cin >> n;
	min1 = 1000000000;
	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	Func(0, make_pair(1, 0));
	cout << min1;
}