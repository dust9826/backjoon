#include <iostream>
#include <vector>
using namespace std;

bool Cycle(vector<vector<int>>& graph, vector<int>& visited, int node)
{
	for (int i = 0; i < graph[node].size(); i++)
	{
		if (visited[graph[node][i]] != 0)
		{
			if ((visited[node] - visited[graph[node][i]]) % 2 == 0)
				return true;
		}
		else
		{
			visited[graph[node][i]] = visited[node] + 1;
			if (Cycle(graph, visited, graph[node][i]))
				return true;
		}
	}
	return false;
}

int main()
{
	int tc;
	cin >> tc;
	while (tc-- != 0)
	{
		int n, m;
		cin >> n >> m;
		vector<vector<int>> graph(n + 1);
		vector<int> visited(n + 1, 0);
		for (int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		bool isPos = false;
		for (int i = 1; i <= n; i++)
		{
			if (visited[i] != 0)
				continue;
			visited[i] = 1;
			if (Cycle(graph, visited, i))
			{
				isPos = true;
				break;
			}
		}
		if (isPos)
			cout << "impossible\n";
		else
			cout << "possible\n";
	}
}