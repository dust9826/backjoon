#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 10000000

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E, K;
	cin >> V >> E;
	cin >> K;

	vector<vector<pair<int, int>>> graph(V + 1);
	vector<int> dist(V + 1, INF);
	vector<bool> isVisit(V + 1, false);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> dist_queue;
	dist[K] = 0;
	dist_queue.push(make_pair(0,K));

	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v,w));
	}

	while (true)
	{
		int min_index = 0;
		bool isEnd=false;
		while (true)
		{
			if (dist_queue.empty())
			{
				isEnd = true;
				break;
			}
			if (isVisit[dist_queue.top().second])
			{
				dist_queue.pop();
			}
			else
			{
				min_index = dist_queue.top().second;
				dist_queue.pop();
				break;
			}
		}

		if (isEnd)
			break;

		isVisit[min_index] = true;

		for (int i = 0; i < graph[min_index].size(); i++)
		{
			int len = dist[min_index] + graph[min_index][i].second;
			int index = graph[min_index][i].first;
			if (len < dist[index])
			{
				dist[index] = len;
				dist_queue.push(make_pair(len, index));
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}
}