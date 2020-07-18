#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<long long int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	while (k-- != 0)
	{
		long long int l, r, x;
		cin >> l >> r >> x;
		vector<long long int> temp(r - l + 1);
		if (x == 0)
			continue;
		for (int i = l - 1; i < r; i++)
		{
			temp[i - l + 1] = arr[i] + x;
		}
		if (x < 0)
		{
			int i = 0;
			int idx = upper_bound(arr.begin(), arr.begin() + l, temp[0]) - arr.begin();
			queue<long long int> q;

			while (idx != r)
			{
				if(idx < l - 1)
					q.push(arr[idx]);
				if (q.empty())
				{
					arr[idx] = temp[i];
					i++;
				}
				else if (i == r - l + 1)
				{
					arr[idx] = q.front();
					q.pop();
				}
				else if (q.front() < temp[i])
				{
					arr[idx] = q.front();
					q.pop();
				}
				else
				{
					arr[idx] = temp[i];
					i++;
				}
				idx++;
			}
		}
		else
		{
			int i = 0;
			int idx = l - 1;
			int j = r;
			queue<long long int> q;

			while (i != r - l + 1)
			{
				if (j < n)
					q.push(arr[j++]);
				if (q.empty())
				{
					arr[idx] = temp[i];
					i++;
				}
				else if (q.front() < temp[i])
				{
					arr[idx] = q.front();
					q.pop();
				}
				else
				{
					arr[idx] = temp[i];
					i++;
				}
				idx++;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}