#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int arr[1000][100];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int a = 0, b = 0;
			for (int k = 0; k < m; k++)
			{
				if (arr[i][k] > arr[j][k])
					a++;
				if (arr[i][k] < arr[j][k])
					b++;
			}
			if (a * b != 0)
			{
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}