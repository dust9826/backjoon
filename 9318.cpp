#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX 1000000

struct Line {
	int x;
	int y1, y2;
	int diff;
};

bool Compare(Line a, Line b)
{
	return a.x < b.x;
}

void Update(vector<pair<int, int>>& seg, int front, int rear, int diff, int node = 1, int begin = 0, int end = MAX - 1)
{
	if (begin > rear || end < front)
		return;

	if (begin >= front && end <= rear)
	{
		seg[node].second += diff;
	}
	else
	{
		int mid = (begin + end) / 2;
		Update(seg, front, rear, diff, node * 2, begin, mid);
		Update(seg, front, rear, diff, node * 2 + 1, mid + 1, end);
	}

	if (seg[node].second)
		seg[node].first = end - begin + 1;
	else if (begin == end)
		seg[node].first = 0;
	else
		seg[node].first = seg[node * 2].first + seg[node * 2 + 1].first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin >> tc;
	while (tc-- != 0)
	{
		int n;
		long long sum = 0;
		cin >> n;
		vector<Line> line;
		int h = (int)ceil(log2(MAX));
		int tree_size = 1 << (h + 1);
		vector<pair<int,int>> seg(tree_size);
		for (int i = 0; i < n; i++)
		{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			line.push_back({ x1,y1,y2,1 });
			line.push_back({ x2,y1,y2,-1 });
		}
		sort(line.begin(),line.end(),Compare);
		int pre = line[0].x;
		for (int i = 0; i < line.size(); i++)
		{
			sum += ((long long)line[i].x - pre) * seg[1].first;
			Update(seg, line[i].y1, line[i].y2 - 1, line[i].diff);
			pre = line[i].x;
		}
		cout << sum << "\n";
	}
}