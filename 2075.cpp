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
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			arr.push(max - a);
			if (arr.size() > n)
				arr.pop();
		}
	}
	cout << max - arr.top();
	return 0;
}