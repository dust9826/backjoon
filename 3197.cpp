#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

vector<int> parent;
vector<pair<int, int>> pack;
queue<pair<int, int>> unchecked;
queue<pair<int, int>> checked;
vector<vector<int>> map;
int arr[4][2] = { 0,1,0,-1,1,0,-1,0 };
int r, c, group;

int Find_Parent(int a)
{
	if (parent[a] == a) 
		return a;
	parent[a] = Find_Parent(parent[a]);
	return parent[a];
}

bool Find(int a, int b)
{
	return Find_Parent(a) == Find_Parent(b);
}

bool Union(int a, int b)
{
	if (Find_Parent(a) == Find_Parent(b))
		return true;
	parent[Find_Parent(a)] = Find_Parent(b);
	return false;
}

//-1인 구역을 새로 지정 / k번째 구역으로 설정
void Fill(pair<int, int> a, int k)
{
	map[a.first][a.second] = k;
	queue<pair<int, int>> temp;
	temp.push(a);
	while (!temp.empty())
	{
		int x = temp.front().first;
		int y = temp.front().second;
		temp.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextx = x + arr[i][0];
			int nexty = y + arr[i][1];

			if (nextx < 0 || nextx >= r || nexty < 0 || nexty >= c)
				continue;
			if (map[nextx][nexty] == 0)
			{
				continue;
			}
			if (map[nextx][nexty] == -1)
			{
				map[nextx][nexty] = map[x][y];
				temp.push(make_pair(nextx, nexty));
			}
		}
	}
}

//구역끼리 합칠 수 있는지. 가능하면 합침
void Check()
{
	while (!unchecked.empty())
	{
		int x = unchecked.front().first;
		int y = unchecked.front().second;
		checked.push(unchecked.front());
		unchecked.pop();
		if (map[x][y] == -1)
			continue;
		for (int i = 0; i < 4; i++)
		{
			int nextx = x + arr[i][0];
			int nexty = y + arr[i][1];

			if (nextx < 0 || nextx >= r || nexty < 0 || nexty >= c)
				continue;
			if (map[x][y] == map[nextx][nexty])
				continue;
			if (map[nextx][nexty] == 0)
				continue;
			if (!Union(map[x][y], map[nextx][nexty]))
			{
				group--;
			}
		}
	}
}

//구역을 넓힌다
void Bigger()
{
	while (!checked.empty())
	{
		int x = checked.front().first;
		int y = checked.front().second;
		checked.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextx = x + arr[i][0];
			int nexty = y + arr[i][1];

			if (nextx < 0 || nextx >= r || nexty < 0 || nexty >= c)
				continue;
			if (map[x][y] == map[nextx][nexty])
				continue;
			if (map[nextx][nexty] == 0)
			{
				map[nextx][nexty] = map[x][y];
				unchecked.push(make_pair(nextx, nexty));
				continue;
			}

			if (!Union(map[x][y], map[nextx][nexty]))
			{
				group--;
			}
		}
	}
}

int main()
{
	cin >> r >> c;

	map.resize(r);
	for (int i = 0; i < r; i++)
	{
		map[i].resize(c,0);
	}

	parent.push_back(0);
	for (int i = 0; i < r; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < c; j++)
		{
			if (s[j] == '.')
				map[i][j] = -1;
			else if (s[j] == 'X')
				map[i][j] = 0;
			else
			{
				map[i][j] = -1;
				pack.push_back(make_pair(i,j));
			}
		}
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (map[i][j] == -1)
			{
				Fill(make_pair(i, j),++group);
				parent.push_back(group);
			}
			if (map[i][j] != 0)
			{
				checked.push(make_pair(i, j));
			}
		}
	}

	int sum = 0;
	while (true)
	{
		Check();
		if (Find(map[pack[0].first][pack[0].second], map[pack[1].first][pack[1].second])) break;
		Bigger();
		sum++;
	}
	cout << sum;
}