#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> arr;
vector<long long> tree;
int n, m;

long long Query(vector<long long>& tree, int node, int start, int end, int front, int rear)
{
	if (start >= front && end <= rear)
	{
		return tree[node];
	}
	else if (start > rear || end < front)
	{
		return 0;
	}
	else
	{
		return Query(tree, node * 2, start, (start + end) / 2, front, rear)
			+ Query(tree, node * 2 + 1, (start + end) / 2 + 1, end, front, rear);
	}
}

void Update(vector<long long>& tree, int node, int start, int end, int index, int diff)
{
	if (index < start || index > end)
	{
		return;
	}
	else if (index == start && index == end)
	{
		tree[node] += diff;
		return;
	}
	else
	{
		tree[node] += diff;
		Update(tree, node * 2, start, (start + end) / 2, index, diff);
		Update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	arr.resize(n);

	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	tree.resize(tree_size);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0)
		{
			if (b > c)
				swap(b, c);
			cout << Query(tree, 1, 0, n - 1, b - 1, c - 1) << "\n";
		}
		else if (a == 1)
		{
			Update(tree, 1, 0, n - 1, b - 1, c - arr[b - 1]);
			arr[b - 1] = c;
		}
	}
	return 0;
}