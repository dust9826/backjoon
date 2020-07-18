#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 11e10

typedef long long ll;
typedef pair<ll, ll> pll;

vector<pll> _graph[2501];
priority_queue<pair<ll,pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> pq;	//�Ÿ�, ��ġ, �ּ� �⸧
ll dist[2501][2501];	//�Ÿ�, �ּ� �⸧��
ll cost[2501];
ll n, m;

void Dijkstra(int cur)
{
	int ans = 0;
	for (int i = 0; i <= 2500; i++)
	{
		for (int j = 0; j <= 2500; j++)
		{
			dist[i][j] = -1;
		}
	}

	pq.push({ 0,{1,cost[cur]} });
	while (!pq.empty())
	{
		ll curdist = pq.top().first;
		ll curidx = pq.top().second.first;
		ll curcost = pq.top().second.second;
		pq.pop();
		if (dist[curidx][curcost] != -1) 
			continue;
		dist[curidx][curcost] = curdist;

		if (curidx == n)
		{
			cout << curdist;
			break;
		}

		for (int i = 0; i < _graph[curidx].size(); i++)
		{
			auto next = _graph[curidx][i];
			ll mcost = min(curcost, cost[next.first]);
			if (dist[next.first][mcost] != -1)
				continue;
			pq.push({ curdist + next.second * curcost, {next.first, mcost} });
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i];
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		_graph[a].push_back({ b,c });
		_graph[b].push_back({ a,c });
	}
	Dijkstra(1);
}