#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

typedef tuple<string, string, int, int> tu;

bool Compare(tu a, tu b)
{
	if (get<2>(a) == get<2>(b))
	{
		if (get<3>(a) == get<3>(b))
		{
			return get<1>(a) > get<1>(b);
		}
		return get<3>(a) < get<3>(b);
	}
	return get<2>(a) > get<2>(b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector<tu> info(n);
	for (int i = 0; i < n; i++)
	{
		string a, b;
		int c, d;
		cin >> a >> b >> c >> d;
		info[i] = tu{ a,b,c,d };
	}
	sort(info.begin(), info.end(), Compare);
	vector<string> s;
	int cnt = 0;
	for (int i = 0; i < k+ cnt; i++)
	{
		string a = get<0>(info[i]);
		bool isTrue = true;
		for (int j = 0; j < s.size(); j++)
		{
			if (a == s[j])
			{
				isTrue = false;
				cnt++;
				break;
			}
		}
		if (isTrue)
		{
			s.push_back(a);
			cout << get<1>(info[i]) << "\n";
		}
	}
}