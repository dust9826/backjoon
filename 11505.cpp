#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define NUM 1000000007

int n, m, k;

vector<long long> arr;
vector<long long> segment;

long long Query(vector<long long>& segment, int node, int start, int end, int front, int rear)
{
	if (start >= front && end <= rear)
	{
		return segment[node];
	}
	else if(start > rear || end < front)
	{
		return 1;
	}
	else
	{
		long long a = Query(segment, node * 2, start, (start + end) / 2, front, rear);
		long long b = Query(segment, node * 2 + 1, (start + end) / 2 + 1, end, front, rear);
		return (a * b) % NUM;
	}
}

long long Update(vector<long long>& segment, int node, int start, int end, int index, int diff)
{
	if (start == index && end == index)
	{
		return segment[node] = diff;
	}
	else if(start > index || end < index)
	{
		return segment[node];
	}
	else
	{
		long long a = Update(segment, node * 2, start, (start + end) / 2, index, diff);
		long long b = Update(segment, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
		return segment[node] = (a * b) % NUM;
	}
}

long long Init(vector<long long>& arr, vector<long long>& segment, int node, int start, int end)
{
	if (start == end)
	{
		return segment[node] = arr[start];
	}
	else
	{
		long long a = Init(arr, segment, node * 2, start, (start + end) / 2);
		long long b = Init(arr, segment, node * 2 + 1, (start + end) / 2 + 1, end);
		return segment[node] = (a * b) % NUM;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;

	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int h = (int)ceil(log2(n));
	int tree_size = 1 << (h + 1);
	segment.resize(tree_size);
	Init(arr, segment, 1, 0, n - 1);

	for (int i = 0; i < m + k; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			Update(segment, 1, 0, n - 1, b - 1, c);
		}
		else if (a == 2)
		{
			cout << Query(segment, 1, 0, n - 1, b - 1, c - 1) << "\n";
		}
	}
}

