#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int n;
	cin >> n;
	map<string, int> maap;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (maap.find(s) == maap.end())
		{
			maap[s] = 1;
		}
		else
		{
			maap[s]++;
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		cin >> s;
		if (--maap[s] == 0)
		{
			maap.erase(s);
		}
	}
	cout << maap.begin()->first;
}