#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	while (tc-- != 0)
	{
		priority_queue<int, vector<int>, less<int>> maxQ; // l
		priority_queue<int, vector<int>, greater<int>> minQ; // r
		int n;
		cin >> n;
		int ave = 0;
		cout << (n + 1) / 2 << "\n";
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			if (i == 0)
			{
				ave = a;
			}
			else
			{
				if (ave > a)
				{
					maxQ.push(a);
				}
				else
				{
					minQ.push(a);
				}
			}
			if (i % 2 == 0)
			{
				if (maxQ.size() < minQ.size())
				{
					maxQ.push(ave);
					ave = minQ.top();
					minQ.pop();
				}
				else if(maxQ.size() > minQ.size())
				{
					minQ.push(ave);
					ave = maxQ.top();
					maxQ.pop();
				}
				cout << ave;
				if ((i + 2) % 20 == 0)
					cout << "\n";
				else
					cout << " ";
			}
		}

		cout << "\n";
	}
}