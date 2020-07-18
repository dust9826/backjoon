#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<int> b(n-1);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (i != 0)
		{
			b[i - 1] = a[i] - a[i - 1];
			sum += b[i - 1];
		}
	}
	sort(b.begin(), b.end());
	for (int i = 0; i < k-1; i++)
	{
		sum -= b[n - i - 2];
	}
	cout << sum;
}