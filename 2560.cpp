#include <iostream>
#include <vector>
using namespace std;

long long dp[1000001] = { 1, 0 };
long long sum = 0;
long long ans = 0;

int main()
{
	long long a, b, d, N;
	cin >> a >> b >> d >> N;
	vector<long long> bug(N + 1);
	bug[0] = 1;
	for (int i = 1; i <= N; i++)
	{
		if (i >= a)
			sum += dp[i - a];
		if (i >= b)
			sum -= dp[i - b];

		dp[i] = (sum + 1000) % 1000;
	}
	for (int i = N - d+1; i <= N; i++)
	{
		ans += dp[i];
	}
	cout << ans%1000;
}