#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<long long, long long> pii;

long long INF = 1e18;
long long n, m;
vector<vector<pii>> graph;
vector<long long> toRoot;
vector<long long> dist;

long long in[303030];
long long out[303030];

void Dijkstra(long long bit, bool is1)
{
	priority_queue<pii, vector<pii>, greater<pii>> minQ;

	for (auto a : toRoot)
	{
		if (is1 == (a & (1 << bit)))
		{
			minQ.push({ in[a],a });
			dist[a] = in[a];
		}
	}

	while (!minQ.empty())
	{
		auto a = minQ.top();
		minQ.pop();
		if (a.first > dist[a.second])
			continue;
		for (auto b : graph[a.second])
		{
			if (dist[a.second] + b.second < dist[b.first])
			{
				dist[b.first] = dist[a.second] + b.second;
				minQ.push({ dist[b.first],b.first });
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	graph.resize(n + 1);
	dist.resize(n + 1);
	for (long long i = 0; i < m; i++)
	{
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a != 1 && b != 1)
		{
			graph[a].push_back({ b,c });
			graph[b].push_back({ a,d });
		}
		if (a == 1)
		{
			toRoot.push_back(b);
			in[b] = c;
			out[b] = d;
		}
		if (b == 1)
		{
			toRoot.push_back(a);
			in[a] = d;
			out[a] = c;
		}
	}
	long long _min = INF;
	for (long long i = 0; i <= 13; i++)
	{
		for (long long j = 1; j <= n; j++)
		{
			dist[j] = INF;
		}
		Dijkstra(i, true);
		for (auto x : toRoot)
		{
			if (false == (x & (1 << i)))
			{
				_min = min(_min, out[x] + dist[x]);
			}
		}
		for (long long j = 1; j <= n; j++)
		{
			dist[j] = INF;
		}
		Dijkstra(i, false);
		for (auto x : toRoot)
		{
			if (true == (x & (1 << i)))
			{
				_min = min(_min, out[x] + dist[x]);
			}
		}
	}
	cout << _min;
}