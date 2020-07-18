#include <iostream>
#include <queue>
#include <stack>
using namespace std;

typedef struct _Info {
	int weight;
	int num;
	int id;
}Info;

bool operator>(Info a,Info b)
{
	if(a.weight==b.weight)
		return (a.num > b.num);
	return a.weight > b.weight;
}

int main()
{
	int n, k;
	long long sum = 0;
	cin >> n >> k;
	vector<int> arr(n);
	priority_queue<Info, vector<Info>, greater<Info>> q;
	stack<int> s;
	int pre = 0, j = 1;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		if (i < k)
		{
			q.push({ b,i,a });
		}
		else
		{
			auto m = q.top();
			q.pop();
			if (m.weight != pre)
			{
				while (!s.empty())
				{
					sum += (long long)s.top() * j++;
					s.pop();
				}
				s.push(m.id);
				pre = m.weight;
			}
			else
			{
				s.push(m.id);
			}
			q.push({ b + m.weight,m.num,a });
		}
	}

	while (!q.empty())
	{
		auto m = q.top();
		q.pop();
		if (m.weight != pre)
		{
			while (!s.empty())
			{
				sum += (long long)s.top() * j++;
				s.pop();
			}
			s.push(m.id);
			pre = m.weight;
		}
		else
		{
			s.push(m.id);
		}
	}
	while (!s.empty())
	{
		sum += (long long)s.top() * j++;
		s.pop();
	}

	cout << sum;
}