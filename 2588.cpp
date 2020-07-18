#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n, a;
	string s;
	cin >> n;
	while (n--!=0)
	{
		cin >> a >> s;
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = 0; j < a; j++)
			{
				cout << s[i];
			}
		}
		cout << "\n";
	}
}