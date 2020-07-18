#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
vector<vector<int>> tree;

vector<int> LIS(vector<int> a)
{
	vector<int> temp;
	for (int i = 0; i < a.size(); i++)
	{

	}
}

vector<int> Init(int node, int start, int end)
{
	if (start == end)
	{
		tree[node].resize(1);
		tree[node][0] = arr[start];
		return tree[node];
	}
	else
	{
		vector<int> a = Init(node * 2, start, (start + end) / 2);
		vector<int> b = Init(node * 2 + 1, (start + end) / 2 + 1, end);
		
		int max = 0;
		int i = 0, j = 0;
		while (i < a.size() && j < b.size())
		{
			if(a[i] < b[j])
			{

			}
			else
			{

			}
		}
	}
}

int main()
{
	int n;
	cin >> n;

	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	tree.resize(tree_size);
	Init(arr, tree, 1, 0, n - 1);
}