#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define MAX 40001
typedef pair<int, int> pii;

vector<pii> tree[MAX];
pii parent[20][MAX];
int depth[MAX];
int max_depth = 0;

void DFS(int cur)
{
	for (int i = 0; i < tree[cur].size(); i++)
	{
		int child = tree[cur][i].first;
		if (child == parent[0][cur].first)
			continue;

		parent[0][child].first = cur;
		parent[0][child].second = tree[cur][i].second;
		depth[child] = depth[cur] + 1;

		if (depth[child] > max_depth)
			max_depth = depth[child];

		DFS(child);
	}
}

int LCA(int a, int b)
{
	int sum = 0;
	if(depth[a] !=depth[b])
	{
		int diff = depth[a] - depth[b];
		int i;
		for (i = 1; i < depth[a]; i++)
		{
			if (diff < (1 << i))
				break;
		}
		i--;
		return LCA(parent[i][a].first, b) + parent[i][a].second;
	}

	if (a == b)return sum;
	else
	{
		int i;
		for (i = 1; i < 20; i++)
		{
			if (parent[i][a].first == parent[i][b].first)
				break;
		}
		i--;
		return LCA(parent[i][a].first, parent[i][b].first) 
			+ parent[i][a].second + parent[i][b].second;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++)
	{
		int a, b, len;
		cin >> a >> b >> len;
		tree[a].push_back({ b,len });
		tree[b].push_back({ a,len });
	}

	DFS(1);

	int h = (int)ceil(log2(max_depth));
	for (int i = 1; i < h+1; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int p = parent[i - 1][j].first;
			int len = parent[i - 1][p].second + parent[i - 1][j].second;
			parent[i][j] = { parent[i - 1][p].first, len };
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (depth[a] < depth[b])
			swap(a, b);
		cout << LCA(a, b) << "\n";
	}
}