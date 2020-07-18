#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	const int max = 0b1111111111111111111111111111111;
	priority_queue<int,vector<int>,greater<int>> queue;
	int n, k;
	cin >> k >> n;
	int * arr = new int[k];

	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
		queue.push(arr[i]);
	}

	for (int i = 0; i < n-1; i++)
	{
		long long a = queue.top();
		for (int j = 0; j < k; j++)
		{
			long long b = a * arr[j];
			if (b < max)
			{
				queue.push(b);
			}
			if (a % arr[j] == 0)
				break;
		}
		queue.pop();
	}
	cout << queue.top();
}