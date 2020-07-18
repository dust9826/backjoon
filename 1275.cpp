#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define SWAP(x,y) x^=y^=x^=y;

int n, q;
vector<long long> arr;
vector<long long> segment;

void Update(vector<long long>& segment, int node, int start, int end, int index, long long diff)
{
	if (index == start && index == end)
	{
		segment[node] += diff;
	}
	else if(index < start || index > end)
	{
		return;
	}
	else
	{
		segment[node] += diff;
		Update(segment, node * 2, start, (start + end) / 2, index, diff);
		Update(segment, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

long long Query(vector<long long>& segment, int node, int start, int end, int front, int rear)
{
	if (start >= front && end <= rear)
	{
		return segment[node];
	}
	else if(end < front || start > rear)
	{
		return 0;
	}
	else
	{
		return Query(segment, node * 2, start, (start + end) / 2, front, rear)
			+ Query(segment, node * 2 + 1, (start + end) / 2 + 1, end, front, rear);
	}
}

long long Init(vector<long long> &arr, vector<long long> &segment, int node, int start, int end)
{
	if (start == end)
	{
		return segment[node] = arr[start];
	}
	else
	{
		return segment[node] = Init(arr, segment, node * 2, start, (start + end) / 2)
			+ Init(arr, segment, node * 2 + 1, (start + end) / 2 + 1, end);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> q;

	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int h = (int)ceil(log2(n));
	int tree_size = 1 << (h + 1);
	segment.resize(tree_size);

	Init(arr, segment, 1, 0, n - 1);

	while (q-- != 0)
	{
		long long x, y, a, b;
		cin >> x >> y >> a >> b;
		if (x > y)
		{
			SWAP(x, y);
		}
		cout << Query(segment, 1, 0, n - 1, x - 1, y - 1) << "\n";
		Update(segment, 1, 0, n - 1, a - 1, b - arr[a - 1]);
		arr[a - 1] = b;
	}
}