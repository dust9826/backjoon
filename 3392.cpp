#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;

#define SIZE 30001
#define X 0
#define Y1 1
#define Y2 2
#define DIFF 3

vector<pii> seg;

int Update(int node, int start, int end, int front, int rear, int diff)
{
	if (front <= start && rear >= end)
	{
		seg[node].second += diff;
		if (seg[node].second > 0)
			seg[node].first = end - start + 1;
		else if (start != end)
			seg[node].first = seg[node * 2].first + seg[node * 2 + 1].first;
		else
			seg[node].first = 0;
		return seg[node].first;
	}
	else if (start > rear || end < front)
	{
		return seg[node].first;
	}
	else
	{
		int a = Update(node * 2, start, (start + end) / 2, front, rear, diff)
			+ Update(node * 2 + 1, (start + end) / 2 + 1, end, front, rear, diff);
		if (seg[node].second == 0)
			seg[node].first = a;
		return seg[node].first;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<int>> coord(2 * n, vector<int>(4));
	for (int i = 0; i < n; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		coord[i * 2] = { a,b,d,1 };
		coord[i * 2 + 1] = { c,b,d,-1 };
	}
	sort(coord.begin(), coord.end());

	int h = (int)ceil(log2(SIZE));
	int tree_size = 1 << (h + 1);
	seg.resize(tree_size);

	int pre_x = coord[0][0];
	int sum = 0;
	Update(1, 0, SIZE - 1, coord[0][Y1], coord[0][Y2] - 1, coord[0][DIFF]);
	for (int i = 1; i < 2 * n; i++)
	{
		sum += seg[1].first * (coord[i][X] - coord[i-1][X]);
		Update(1, 0, SIZE - 1, coord[i][Y1], coord[i][Y2] - 1, coord[i][DIFF]);
		pre_x = coord[i][X];
	}
	cout << sum;
}