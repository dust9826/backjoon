#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> dp;

bool Check(string a, string b)
{
	string s1 = b.substr(0, a.length());
	string s2 = b.substr(b.length() - a.length(), a.length());
	if (s1 == a || s2 == a)
	{
		return true;
	}
	return false;
}

long long int Func(string str)
{
	long long int sum = 0;
	for (int i = 1; i < str.length(); i++)
	{
		string a = str.substr(0, i);
		string b = str.substr(i, str.length() - i);

		if (a.length() == b.length())
		{
			continue;
		}
		else if (a.length() > b.length())
		{
			string temp = a;
			a = b;
			b = temp;
		}

		if (Check(a, b))
		{
			sum++;
			if (b.length() > 2)
			{
				if (dp.find(b) == dp.end())
				{
					dp[b] = Func(b);
				}
				sum += dp[b];
			}
		}
		sum %= 2014;
	}
	return sum;
}

int main()
{
	string input;
	cin >> input;
	long long int answer = Func(input);
	answer %= 2014;
	cout << answer;
}