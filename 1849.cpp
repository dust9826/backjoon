#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<int> arr;	//i앞에 i보다 작은 수의 갯수
vector<int> tree;

void Init(int node, int start, int end)
{
	if (start == end)
	{
		tree[node] = 1;
	}
	else
	{
		Init(node * 2, start, (start + end) / 2);
		Init(node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

void Update(int node, int start, int end, int index, int diff)
{
	if (index > end || index < start) {
		return;
	}
	if (start == end)
	{
		tree[node] += diff;
		return;
	}
	Update(node * 2, start, (start + end) / 2, index, diff);
	Update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int Find(int node, int start, int end, int data)
{
	if (start == end)
		return start;
	if (tree[node * 2] >= data)
		return Find(node * 2, start, (start + end) / 2, data);
	else
		return Find(node * 2 + 1, (start + end) / 2 + 1, end, data - tree[node * 2]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	arr.resize(n);
	int treeH = (int)ceil(log2(n));
	int tree_size = 1 << (treeH + 1);
	tree.resize(tree_size);
	vector<int> answer(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		arr[i]++;
	}

	Init(1, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		int index = Find(1, 0, n - 1, arr[i]);
		Update(1, 0, n - 1, index, -1);
		answer[index] = i + 1;
	}

	for (int i = 0; i < n; i++)
	{
		cout << answer[i] << "\n";
	}
}