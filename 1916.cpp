#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 2147483647

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, A, B;
	cin >> N >> M;

	vector<vector<pair<int, int>>> graph(N + 1);

	for (int i = 0; i < M; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}

	cin >> A >> B;
	vector<int> dist(N + 1, INF);
	vector<bool> isVisit(N + 1, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dist_queue;
	dist[A] = 0;
	dist_queue.push(make_pair(0, A));

	while (true)
	{
		int min_index = 0;
		bool isEnd = false;
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

	cout << dist[B];
}