#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[10001];
int parent[10001][20];
int depth[10001];

void reset()
{
	for (int i = 0; i < 10001; i++)
	{
		tree[i].clear();
		for (int j = 0; j < 20; j++)
			parent[i][j] = 0;
		depth[i] = 0;
	}
}

void DFS(int x)
{
	for (int i = 0; i < tree[x].size(); i++)
	{
		int child = tree[x][i];
		if (child == parent[x][0])
			continue;

		parent[child][0] = x;
		depth[child] = depth[x] + 1;

		DFS(child);
	}
}

int LCA(int a, int b)
{
	if (depth[a] < depth[b])
		swap(a, b);
	if (depth[a] != depth[b])
	{
		for (int i = 19; i >= 0; i--)
		{
			if (depth[a] - depth[b] >= (1 << i))
				a = parent[a][i];
		}
	}

	if (a == b)return a;
	for (int i = 19; i >= 0; i--)
	{
		if (parent[a][i] != parent[b][i])
		{
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	return parent[a][0];
}

int main()
{
	int t;
	cin >> t;
	while (t-- != 0)
	{
		int n;
		cin >> n;
		vector<bool> bo(n + 1,true);
		for (int i = 0; i < n - 1; i++)
		{
			int a, b;
			cin >> a >> b;
			tree[a].push_back(b);
			bo[b] = false;
		}
		for (int i = 1; i <= n; i++)
		{
			if(bo[i])
				DFS(i);
		}
		for (int i = 1; i < 20; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				parent[j][i] = parent[parent[j][i - 1]][i - 1];
			}
		}
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b)<<"\n";
		reset();
	}
}