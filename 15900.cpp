#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

tuple<int,int> Func(int idx,int pre, vector<vector<int>>& arr, vector<int>& a)
{
	if (arr[idx].size() == 1 && idx != 1)
		return make_tuple(0, 1);
	int sum = 0;
	int num = 0;
	for (int i = 0; i < arr[idx].size(); i++)
	{
		if (arr[idx][i] == pre)
			continue;
		auto t = Func(arr[idx][i], idx, arr, a);
		sum += get<0>(t) + get<1>(t);
		num += get<1>(t);
	}
	return make_tuple(sum, num);
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> arr(n+1);
	vector<int> a(n + 1);
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	int k = get<0>(Func(1, 0, arr, a));
	if (k % 2 != 0)
		cout << "Yes";
	else
		cout << "No";
}