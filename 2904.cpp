#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000000 + 1;
int minFactor[MAX];
vector<int> prime;

void eratosthenes(void)
{
	minFactor[0] = minFactor[1] = -1;
	for (int i = 2; i < MAX; i++)
		minFactor[i] = i;
	for (int i = 2; i * i < MAX; i++)
		if (minFactor[i] == i)
			for (int j = i * i; j < MAX; j += i)
				if (minFactor[j] == j)
					minFactor[j] = i;
	for (int i = 2; i < MAX; i++)
		if (minFactor[i] == i)
			prime.push_back(i);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	eratosthenes();
	vector<int> usedPrime(prime.size(), 0);
	vector<vector<int>> factor(N, vector<int>(prime.size(), 0));
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		for (int j = 0; j < prime.size(); j++)
		{
			while (!(num % prime[j]))
			{
				factor[i][j]++;
				usedPrime[j]++;
				num /= prime[j];
				if (num == 1)
					break;
			}
			if (num == 1)
				break;
		}
	}
	int result = 1, cnt = 0;
	for (int i = 0; i < prime.size(); i++)
	{
		int temp = usedPrime[i] / N;
		for (int j = 0; j < temp; j++)
			result *= prime[i];
		for (int j = 0; j < N; j++)
			if (temp > factor[j][i])
				cnt += temp - factor[j][i];
	}
	cout << result << " " << cnt << "\n";
	return 0;
}