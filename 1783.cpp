#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	n--;
	m--;
	int count = 1;
	if (n >= 2 && m >= 6)
	{
		m -= 6;
		count += 4 + m;
	}
	else
	{
		if (n >= 2)
		{
			count += m;
		}
		if (n == 1)
		{
			count += m / 2;
		}
		if (count > 4)
		{
			count = 4;
		}
	}
	cout << count;
}