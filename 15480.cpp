#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

vector<int> tree[100001];
int parent[21][100001];
int depth[100001] = { 0,1, };
int max_depth=0;

void DFS(int cur)
{
	for (int i = 0; i < tree[cur].size(); i++)
	{
		int child = tree[cur][i];
		if (child == parent[0][cur])
			continue;

		parent[0][child] = cur;
		depth[child] = depth[cur] + 1;
		if (max_depth < depth[child])
			max_depth = depth[child];
		DFS(child);
	}
}

int LCA(int x, int y) {

	if (depth[x] > depth[y])
		swap(x, y);
	for (int i = 20; i >= 0; i--)
	{
		if (depth[x] <= depth[parent[i][y]])
		{
			y = parent[i][y];
		}
	}
	if (x == y)
		return x;
	for (int i = 20; i >= 0; i--)
	{
		if (parent[i][x] != parent[i][y])
		{
			x = parent[i][x];
			y = parent[i][y];
		}
	}
	return parent[0][x];

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	DFS(1);

	int h = (int)ceil(log2(max_depth));
	for (int i = 1; i <= h; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			int p = parent[i - 1][j];
			parent[i][j] = parent[i - 1][p];
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int r, u, v;
		cin >> r >> u >> v;
		int a = LCA(r, u);
		int b = LCA(r, v);
		int c = LCA(u, v);
		int ans = 0;
		if (depth[a] < depth[b])
			if (depth[b] < depth[c])
				ans = depth[c];
			else
				ans = depth[b];
		else
			if (depth[a] < depth[c])
				ans = depth[c];
			else
				ans = depth[a];
		if (ans == depth[a]) ans = a;
		else if (ans == depth[b])ans = b;
		else ans = c;
		cout << ans << "\n";
	}
}