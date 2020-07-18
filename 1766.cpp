#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> tree(n + 1);
	vector<int> count(n + 1, 0);
	vector<int> result;
	while (m-- != 0)
	{
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		count[b]++;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (count[j] == 0)
			{
				//result.push_back(j);
				cout << j << " ";
				for (int k = 0; k < tree[j].size(); k++)
				{
					count[tree[j][k]]--;
				}
				count[j]--;
				break;
			}
		}
	}
}