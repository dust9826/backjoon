#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

#define INF 10000000

int main()
{
	int n;
	float arr[103][103];
	vector<pair<float, float>> map;

	float x, y;
	cin >> x >> y;
	map.push_back(make_pair(x, y));	//자신위치 index = 0
	cin >> x >> y;
	map.push_back(make_pair(x, y));	//대포위치 index = 1

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		map.push_back(make_pair(x, y));
	}

	for (int i = 0; i < n + 2; i++)
	{
		for (int j = 0; j < n + 2; j++)
		{
			float x = map[i].first - map[j].first;
			float y = map[i].second - map[j].second;
			float len = x * x + y * y;
			float time = 0;
			len = sqrt(len);
			if (i == 0)
				time = len / 5;
			else
			{
				time += 2;
				len -= 50;
				if (len < 0)
					len = -len;
				time += len / 5;
			}
			arr[i][j] = time;
		}
	}

	float dist[103];
	bool isVisit[103];
	for (int x = 0; x < n + 2; x++)
	{
		dist[x] = INF;
		isVisit[x] = false;
	}
	priority_queue<pair<float, int>, vector<pair<float, int>>, greater< pair<float, int>>> dist_queue;
	dist[0] = arr[0][0];
	dist_queue.push(make_pair(dist[0], 0));

	while (true)
	{
		int index;
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
				index = dist_queue.top().second;
				dist_queue.pop();
				break;
			}
		}

		if (isEnd)
			break;

		isVisit[index] = true;

		for (int i = 0; i < n + 2; i++)
		{
			float len = dist[index] + arr[index][i];
			if (len < dist[i])
			{
				dist[i] = len;
				dist_queue.push(make_pair(len, i));
			}
		}
	}
	cout << dist[1];
}