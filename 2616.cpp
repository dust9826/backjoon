#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> input;
vector<int> _sum;
int dp[4][50001];
int N, K;
int ans=0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	input.resize(N + 1);
	_sum.resize(N +1);
	for (int i = 1; i <= N; i++)
	{
		cin >> input[i];
		_sum[i] = input[i] + _sum[i - 1];
	}
	cin >> K;

	for (int n = 1; n <= 3; n++) 
	{
		for (int m = n * K; m <= N; m++) 
		{
			if (n == 1)
				dp[n][m] = dp[n][m - 1] > _sum[m] - _sum[m - K] ? dp[n][m - 1] : _sum[m] - _sum[m - K];
			else
				dp[n][m] = dp[n][m - 1] > dp[n - 1][m - K] + _sum[m] - _sum[m - K] ? dp[n][m - 1] : dp[n - 1][m - K] + _sum[m] - _sum[m - K];

			ans = ans > dp[n][m] ? ans : dp[n][m];
		}
	}
	cout << ans;
}