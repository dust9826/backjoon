#include <iostream>
#include <queue>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	const int max = 0b1111111111111111111111111111111;
	priority_queue<int> arr;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (a)
		{
			arr.push(max - a);
		}
		else
		{
			if (arr.empty())
				cout << 0 << '\n';
			else
			{
				cout << max - arr.top() << '\n';
				arr.pop();
			}
		}
	}
}