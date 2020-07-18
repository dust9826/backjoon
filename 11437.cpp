#include <iostream>
#include <vector>
using namespace std;

vector<int> arr[50001];
int parent[20][50001];
int depth[50001];

void DFS(int cur)
{
	for (int i = 0; i < arr[cur].size(); i++)
	{
		int child = arr[cur][i];
		if (parent[0][cur] == child)
			continue;
		parent[0][child] = cur;
		depth[child] = depth[cur] + 1;
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
				a = parent[i][a];
		}
	}

	if (a == b)return a;
	for (int i = 19; i >= 0; i--)
	{
		if (parent[i][a] != parent[i][b])
		{
			a = parent[i][a];
			b = parent[i][b];
		}
	}
	return parent[0][a];
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	DFS(1);
	for (int i = 1; i < 20; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << "\n";
	}
}