#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001] = { 0, };
int dp[100001] = { 0, };
int seg[500001] = { 0, };

int query(int l, int r, int node, int begin, int end)
{
	if (r < begin || l > end) return 0;
	else if (l <= begin && r >= end) return seg[node];
	else
	{
		int mid = (begin + end) / 2;
		return max(query(l, r, node * 2, begin, mid),
			query(l, r, node * 2 + 1, mid + 1, end));
	}
}

int update(int index, int data, int node, int begin, int end)
{
	if (index < begin || index > end) return seg[node];
	else if (index == begin && index == end)
	{
		seg[node] = data;
		return seg[node];
	}
	else
	{
		int mid = (begin + end) / 2;
		return seg[node] = max(update(index, data, node * 2, begin, mid),
			update(index, data, node * 2 + 1, mid + 1, end));
	}
}

int main()
{
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		dp[i] = query(0, arr[i], 1, 0, n - 1) + 1;
		update(arr[i], dp[i], 1, 0, n - 1);
		ans = max(ans, dp[i]);
	}

	cout << n - ans;
	
}