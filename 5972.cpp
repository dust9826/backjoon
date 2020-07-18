#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> name;

bool Compare(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	name.resize(n);
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		name[i].first = s.length();
		name[i].second = i;
	}
	sort(name.begin(), name.end(), Compare);
	name.push_back(make_pair(1000, 1));
	int sum = 0;
	int num = name[0].first;
	int front = 0, rear = 1;
	while (rear < n + 1)
	{
		if (name[front].first == name[rear].first)
		{
			if (name[front].second + k < name[rear].second)
			{
				sum += rear - front - 1;
				front++;
			}
			else
			{
				rear++;
			}
		}
		else
		{
			for (; front < rear; front++)
			{
				sum += rear - front - 1;
			}
			rear++;
		}
	}
	cout << sum;
}