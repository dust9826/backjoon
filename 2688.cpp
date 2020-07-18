#include <iostream>
using namespace std;

long long arr[65][10] = { 0, };
long long sum[65] = { 0, };

int main()
{
	int tc;
	cin >> tc;
	int pre_n = 0;
	while (tc-- != 0)
	{
		int n;
		cin >> n;
		for (int i = pre_n; i < n; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (i == 0)
					arr[i][j] = 1;
				for (int k = j; k < 10; k++)
				{
					arr[i][j] += arr[i - 1][k];
				}
				sum[i] += arr[i][j];
			}
		}

		cout << sum[n - 1] << "\n";

		if(pre_n < n)
			pre_n = n;
	}
}