#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 10000000

int N;
int dirx[4] = { 0,0,1,-1 };
int diry[4] = { 1,-1,0,0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int count = 0;
	while (true)
	{
		count++;
		cin >> N;
		if (N == 0)
			break;
		int map[126][126];
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				cin >> map[x][y];
			}
		}

		int dist[126][126];
		bool isVisit[126][126];
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				dist[x][y] = INF;
				isVisit[x][y] = false;
			}
		}
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> dist_queue;
		dist[0][0] = map[0][0];
		dist_queue.push(make_pair(map[0][0], make_pair(0,0)));

		while (true)
		{
			int min_x = 0;
			int min_y = 0;
			bool isEnd = false;
			while (true)
			{
				if (dist_queue.empty())
				{
					isEnd = true;
					break;
				}
				int x = dist_queue.top().second.first;
				int y = dist_queue.top().second.second;
				if (isVisit[x][y])
				{
					dist_queue.pop();
				}
				else
				{
					min_x = x;
					min_y = y;
					dist_queue.pop();
					break;
				}
			}

			if (isEnd)
				break;

			isVisit[min_x][min_y] = true;

			for (int i = 0; i < 4; i++)
			{
				int x = min_x + dirx[i];
				int y = min_y + diry[i];
				if (x < 0 || x > N || y < 0 || y > N)
					continue;
				int len = dist[min_x][min_y] + map[x][y];
				if (len < dist[x][y])
				{
					dist[x][y] = len;
					dist_queue.push(make_pair(len, make_pair(x,y)));
				}
			}
		}

		cout <<"Problem " << count << ": "<< dist[N - 1][N - 1]<<"\n";
	}
}