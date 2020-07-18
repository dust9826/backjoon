#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int arr[5] = { 0, };
	char roma[6] = "IVXLC";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == roma[0])
		{
			arr[0]++;
		}
		else if (s[i] == roma[1])
		{
			arr[1]++;
		}
		else if (s[i] == roma[2])
		{
			arr[2]++;
		}
		else if (s[i] == roma[3])
		{
			arr[3]++;
		}
		else if (s[i] == roma[4])
		{
			arr[4]++;
		}
	}

	string answer = "";
	if (arr[4] == 1)
	{
		answer += roma[2];
		arr[2]--;
		
		answer += roma[4];
		arr[4]--;
	}
	if (arr[3] == 1)
	{
		if (arr[2] == 1)
		{
			answer += roma[2];
			arr[2]--;
		}
		if (arr[2] == 2 && arr[0] == 1)
		{
			answer += roma[2];
			arr[2]--;
		}

		answer += roma[3];
		arr[3]--;
	}
	if (arr[2] == 1)
	{
		if (arr[0] == 1)
		{
			answer += roma[0];
			arr[0]--;
		}

		answer += roma[2];
		arr[2]--;
	}
	for (int i = 0; i < arr[2]; i++)
	{
		answer += roma[2];
	}
	if (arr[1] == 1)
	{
		if (arr[0] == 1)
		{
			answer += roma[0];
			arr[0]--;
		}

		answer += roma[1];
		arr[1]--;
	}
	for (int i = 0; i < arr[0]; i++)
	{
		answer += roma[0];
	}
	cout << answer;
}