#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define MAX 1000000001

//first : 높이 값 / second : 위치
pair<long long,int> Query(vector<pair<long long, int>>& segment, int node, int start, int end, int front, int rear)
{
	if (start >= front && end <= rear)
	{
		return segment[node];
	}
	else if (end < front || start > rear)
	{
		return make_pair(MAX, 0);
	}
	else
	{
		pair<long long, int> a = Query(segment, node * 2, start, (start + end) / 2, front, rear);
		pair<long long, int> b = Query(segment, node * 2 + 1, (start + end) / 2 + 1, end, front, rear);
		return segment[node] = a.first < b.first ? a : b;
	}
}

pair<long long, int> Init(vector<long long>& arr, vector<pair<long long, int>>& segment, int node, int start, int end)
{
	if (start == end)
	{
		return segment[node] = make_pair(arr[start], start);
	}
	else
	{
		pair<long long, int> a = Init(arr, segment, node * 2, start, (start + end) / 2);
		pair<long long, int> b = Init(arr, segment, node * 2 + 1, (start + end) / 2 + 1, end);
		return segment[node] = a.first < b.first ? a : b;
	}
}

long long Find(vector<pair<long long, int>>& segment, int node, int start, int end, int front, int rear)
{
	if (front > rear)
		return 0;
	pair<long long, int> min_Data = Query(segment, node, start, end, front, rear);
	long long first = min_Data.first * ((rear + 1) - front);
	long long second = Find(segment, node, start, end, front, min_Data.second - 1);
	long long third = Find(segment, node, start, end, min_Data.second + 1, rear);
	long long max = 0;
	if (max < first)
		max = first;
	if (max < second)
		max = second;
	if (max < third)
		max = third;
	return max;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int n;
		cin >> n;
		if (n == 0)
			break;
		
		vector<long long> arr(n);
		int h = (int)ceil(log2(n));
		int tree_size = 1 << (h + 1);
		vector<pair<long long, int>> segment(tree_size);

		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		Init(arr, segment, 1, 0, n - 1);

		cout << Find(segment, 1, 0, n - 1, 0, n - 1) << "\n";
	}
}