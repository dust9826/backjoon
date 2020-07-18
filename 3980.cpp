#include <iostream>
using namespace std;

int arr[11][11] = { 0, };

int Func(int y, int bit)
{
	if (y == 11)
		return -1;
	int max = 0;
	for (int x = 0; x < 11; x++)
	{
		if (arr[y][x] == 0)
			continue;
		if (!(bit & (1 << x)))
		{
			int temp = Func(y + 1, bit + (1 << x));
			if (temp == 0)
				continue;
			if (temp == -1)
				temp = 0;
			temp += arr[y][x];
			if (max < temp)
				max = temp;
		}
	}
	return max;
}

int main()
{
	int tc;
	cin >> tc;
	while (tc-- != 0)
	{
		for (int y = 0; y < 11; y++)
		{
			for (int x = 0; x < 11; x++)
			{
				cin >> arr[y][x];
			}
		}

		cout << Func(0, 0)<<"\n";
	}
}