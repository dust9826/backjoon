#include <iostream>
#include <string>
using namespace std;

long long sum[200001][26] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	for (int i = 1; i <= s.size(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			sum[i][j] += sum[i - 1][j];
		}
		sum[i][s[i-1] - 'a']++;
	}
	int n;
	cin >> n;
	while (n-- != 0)
	{
		int l, r;
		char a;
		cin >> a >> l >> r;
		cout << sum[r+1][a - 'a'] - sum[l][a - 'a'] << "\n";
	}
}