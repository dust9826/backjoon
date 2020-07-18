//https://www.acmicpc.net/problem/8983

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
using namespace std;

typedef pair<int, int> pii;

int m, n, l, cnt = 0;
vector<int> point;
vector<pii> animal;

int main()
{
	cin >> m >> n >> l;

	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		point.push_back(x);
	}

	sort(point.begin(), point.end());

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		animal.push_back({x, y});
	}

	sort(animal.begin(), animal.end());

	int idx = 0;
	int mid = point[idx];
	if (idx < m - 1) 
		mid = (point[idx] + point[idx + 1]) / 2;

	for (int i = 0; i < n; i++)
	{
		while (idx != m - 1)
		{
			if (animal[i].first > mid)
			{
				idx++;
				if (idx == m - 1)
					break;
				mid = (point[idx] + point[idx + 1]) / 2;
			}
			else
				break;
		}
		int dist = abs(point[idx] - animal[i].first) + animal[i].second;
		if (dist <= l)
			cnt++;
	}
	cout << cnt;
}