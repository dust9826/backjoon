#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int tc;
	int n;
	int k;
	cin >> tc;
	while (tc-- != 0)
	{
		cin >> n >> k;
		vector<long long int> time(n + 1);
		vector<vector<int>> relate(n+1);	//n번째와 연결된 노드들
		vector<int> sequence(n+1);			//n번째를 만들기 위해 필요한 건물 수
		vector<long long int> answer(n + 1);
		queue<int> q;
		for (int i = 0; i < n; i++)
		{
			cin >> time[i + 1];
		}
		int x, y;
		for (int i = 0; i < k; i++)
		{
			cin >> x >> y;
			relate[x].push_back(y);
			sequence[y]++;
		}

		for (int i = 1; i <= n; i++)
		{
			if (sequence[i] == 0)
			{
				q.push(i);
				answer[i] = time[i];
			}
		}

		while (!q.empty())
		{
			for (int i = 0; i < relate[q.front()].size(); i++)
			{
				x = relate[q.front()][i];
				if (--sequence[x] == 0)
				{
					q.push(x);
				}
				if (answer[x] < time[x] + answer[q.front()])
					answer[x] = time[x] + answer[q.front()];
			}
			q.pop();
		}
		cin >> y;
		cout << answer[y] << "\n";
	}
}