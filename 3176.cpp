#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100001

typedef pair<int, int> pii;

vector<pii> tree[MAX];
int parent[20][MAX] = { 0,1, };
int p_max[20][MAX] = { 1, };
int p_min[20][MAX] = { 1, };
int depth[MAX] = { 0,1, };

void DFS(int cur)
{
	for (int i = 0; i < tree[cur].size(); i++)
	{
		int child = tree[cur][i].first;
		if (child == parent[0][cur])
			continue;
		parent[0][child] = cur;
		p_max[0][child] = tree[cur][i].second;
		p_min[0][child] = tree[cur][i].second;
		depth[child] = depth[cur] + 1;
		DFS(child);
	}
}

pii LCA(int a, int b)
{
	pii ans = { 1000001,0 };
	if (depth[a] < depth[b])
		swap(a, b);
	if (depth[a] != depth[b])
	{
		for (int i = 19; i >= 0; --i)
		{
			if (depth[a] - depth[b] >= (1 << i))
			{
				ans.first = min(ans.first, p_min[i][a]);
				ans.second = max(ans.second, p_max[i][a]);
				a = parent[i][a];
			}
		}
	}

	if (a == b) 
	{
		return ans;
	}
	for (int i = 19; i >= 0; --i)
	{
		if (parent[i][a] != parent[i][b])
		{
			ans.first = min(ans.first, p_min[i][a]);
			ans.first = min(ans.first, p_min[i][b]);
			ans.second = max(ans.second, p_max[i][a]);
			ans.second = max(ans.second, p_max[i][b]);
			a = parent[i][a];
			b = parent[i][b];
		}
	}
	ans.first = min(ans.first, p_min[0][a]);
	ans.first = min(ans.first, p_min[0][b]);
	ans.second = max(ans.second, p_max[0][a]);
	ans.second = max(ans.second, p_max[0][b]);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a = 0, b = 0, len = 0;
		cin >> a >> b >> len;
		tree[a].push_back({ b,len });
		tree[b].push_back({ a,len });
	}
	DFS(1);
	for (int i = 1; i < 20; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			int pre = parent[i - 1][j];
			parent[i][j] = parent[i - 1][pre];
			p_min[i][j] = min(p_min[i - 1][j], p_min[i - 1][pre]);
			p_max[i][j] = max(p_max[i - 1][j], p_max[i - 1][pre]);
		}
	}

	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		auto ans = LCA(a, b);
		cout << ans.first << " " << ans.second << "\n";
	}
}
//썜 풀이
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#define MOD 998244353
#define ll long long
using namespace std;

int n;
map<pair<int, int>, int> m;
vector<int> graph[100001];
int parent[20][100001];
int minLen[20][100001];
int maxLen[20][100001];
int depth[100001];

// parent[i][j] : 노드 j에서 1<<i만큼 위에 있는 부모의 노드 번호

// minLen[i][j] : 노드 j에서 1<<i만큼 위에 있는 부모까지 갈때 최단 간선의 길이

// maxLen[i][j] : 노드 j에서 1<<i만큼 위에 있는 부모까지 갈때 최장 간선의 길이


void dfs(int cur) {
	for(int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i];
		if(depth[next] != 0) continue;

		parent[0][next] = cur;
		minLen[0][next] = m[{cur, next}];
		maxLen[0][next] = m[{cur, next}];
	}
}

struct ans{
	int road_min, road_max, idx;
};

ans lca(int a, int b) {
	if(a == b) return {(int)1e9, 0, a};

	// 1. depth 맞추기

	if (depth[a] > depth[b]) return lca(b, a);

	else if (depth[a] < depth[b]) {
		int diff = depth[b] - depth[a];
		// 한 번에 최대한 많은 거리를 이동하여야 한다
		.
		for(int k = 19; k >= 0; k--)
			if(diff >= (1 << k)) {
				ans ret = lca(a, parent[k][b]);
				int newMin = min(minLen[k][b], ret.road_min);
				int newMax = max(maxLen[k][b], ret.road_max);
				return {newMin, newMax, ret.idx};
			}
	}

	// 2.depth가 맞추어 졌으므로 이진 탐색 수행

	// 기저 사례: a랑 b의 부모가 같은 경우

	if(parent[0][a] == parent[0][b]) return parent[0][a];
	// 이외의 경우에는 부모가 달라지는 첫 번재 위치에서 재귀 호출을 한다!

	for(int k = 19; k >= 0; k--) {
		if(parent[k][a] != parent[k][b]) {
			ans ret = lca(parent[k][a], parent[k][b]);
			int newMin = minn(minLen[k][a], minLen[k][b], ret.road_min);
			int newMax = minn(maxLen[k][a], maxLen[k][b], ret.road_max);
			return {newMin, newMax, ret.idx};
		}
	}
}

int main()
{
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		m[{a, b}] = w;
		m[{b, a}] = w;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	depth[1] = 1;
	dfs(1);

	for(int i = 1; i < 20; i++) {
		for(int j = 1; j <= n; j++) {
			// 2^(i-1)을 두 번 가면 2^i 만큼 위에 있는 부모가 누군지 알 수 있다.
			int mid = parent[i - 1][j];
			parent[i][j] = parent[i - 1][mid];
			minLen[i][j] = min(...);
			maxLen[i][j] = max(...);
		}
	}


	int k;
	cin >> k;
	vector<pair<int, int>> vv;
	for(int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		vv.push_back({a, b});
	}

	for(int i = 0; i < vv.size(); i++) {
		ans a = lca(vv[i].first, vv[i].second);
		printf("%d %d\n", a.road_min, a.road_max);
	}

}
*/