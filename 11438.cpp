#include <cstdio>
#include <vector>
#include <cmath>
#pragma warning(disable : 4996)
using namespace std;

vector<int> tree[100001];
int parent[20][100001];
int depth[100001];
int two[20];
int max_depth = 0;

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

int main()
{
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d %d",&a ,&b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	DFS(1);
	two[0] = 1;

	int log_maxDepth = (int)ceil(log2(max_depth)) + 1;
	for (int i = 1; i < log_maxDepth; i++)
	{
		two[i] = two[i-1] * 2;
		for (int j = 0; j <= n; j++)
		{
			int p = parent[i - 1][j];
			parent[i][j] = parent[i - 1][p];
		}
	}

	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (depth[a] > depth[b])
			swap(a, b);
		// aøÕ b¿« ±Ì¿Ã ∏¬√Á¡÷±‚
		while (depth[a] != depth[b])
		{
			int diff = depth[b] - depth[a];
			int k;
			for (k = 1; k < n; k++)
			{
				if (two[k] > diff)
					break;
			}
			k--;
			b = parent[k][b];
		}

		while (a != b)
		{
			int k;
			for (k = 1; k < n; k++)
			{
				if (parent[k][a] == parent[k][b])
					break;
			}
			a = parent[k - 1][a];
			b = parent[k - 1][b];
		}
		printf("%d \n", a);
	}
}