#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> arr;
vector<pair<int,int>> tree;
int n, m;

pair<int, int> Query(int front, int rear, int node = 1, int start = 0, int end = n - 1)
{
	if (start >= front && end <= rear)
	{
		return tree[node];
	}
	else if (start > rear || end < front)
	{
		return make_pair(1000000000, 0);
	}
	else
	{
		pair<int, int> a = Query(front, rear, node * 2, start, (start + end) / 2);
		pair<int, int> b = Query(front, rear, node * 2 + 1, (start + end) / 2 + 1, end);
		pair<int, int> temp;
		temp.first = a.first < b.first ? a.first : b.first;
		temp.second = a.second > b.second ? a.second : b.second;
		return temp;
	}
}

pair<int, int> Init(int node = 1, int start = 0, int end = n - 1)
{
	if (start == end)
	{
		return tree[node] = make_pair(arr[start], arr[start]);
	}
	else
	{
		pair<int, int> a = Init(node * 2, start, (start + end) / 2);
		pair<int, int> b = Init(node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node].first = a.first < b.first ? a.first : b.first;
		tree[node].second = a.second > b.second ? a.second : b.second;
		return tree[node];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	tree.resize(tree_size);
	Init();

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		pair<int, int> answer = Query(a - 1, b - 1);
		cout << answer.first << " " << answer.second << "\n";
	}
	return 0;
}