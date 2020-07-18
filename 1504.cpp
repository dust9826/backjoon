#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 10000000

int N, E, arr[4];
vector<vector<pair<int, int>>> graph;

int Func(int from, int to)
{
	vector<int> dist(N + 1, INF);
	vector<bool> isVisit(N + 1, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dist_queue;
	dist[from] = 0;
	dist_queue.push(make_pair(0, from));

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

	return dist[to];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> E;

	graph.resize(N + 1);

	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	arr[0] = 1;
	cin >> arr[1] >> arr[2];
	arr[3] = N;

	int answer1 = 0;
	for (int i = 0; i < 3; i++)
	{
		answer1 += Func(arr[i], arr[i + 1]);
	}

	int temp = arr[1];
	arr[1] = arr[2];
	arr[2] = temp;

	int answer2 = 0;
	for (int i = 0; i < 3; i++)
	{
		answer2 += Func(arr[i], arr[i + 1]);
	}

	if (answer1 > INF)
		cout << "-1";
	else if (answer1 < answer2)
		cout << answer1;
	else
		cout << answer2;
}