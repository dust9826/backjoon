//https://www.acmicpc.net/problem/2261

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int n;
vector<pll> v;	//x���� ���� ����
map<pll, int> m;	//y���� ���� ����
int dist = 1e9;		//�ּ� �Ÿ� ����
int cand_start = 0;	//x���� ������ �ּ���ġ

ll get_len(pll a, pll b)
{
	return (a.first - b.first) * (a.first - b.first) 
		+ (a.second - b.second) * (a.second - b.second);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		ll x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	//x���� ���� ����
	sort(v.begin(), v.end());

	//m�� �ʱⰪ ����
	m[{v[0].second, v[0].first}] = 0;
	m[{v[1].second, v[1].first}] = 0;
	dist = get_len(v[0], v[1]);
	
	for (int cur_idx = 2; cur_idx < n; cur_idx++)
	{
		pll cur = v[cur_idx];
		//x���� ���� ���� map ����
		while (true)
		{
			ll d = pow(cur.first - v[cand_start].first, 2);
			if (d > dist)
			{
				m.erase({ v[cand_start].second, v[cand_start].first });
				cand_start++;
			}
			else
			{
				break;
			}
		}

		//y���� ���� low ~ high �˻�
		auto low = m.lower_bound({ cur.second - sqrt(dist),-1e9 });
		auto high = m.upper_bound({ cur.second + sqrt(dist),1e9 });
		
		for (low; low != high; low++)
		{
			ll d = get_len(cur, { low->first.second, low->first.first });
			if (d < dist)
				dist = d;
		}
		m[{cur.second, cur.first}] = 0;
		if (dist == 0)
		{
			cout << "0";
			return 0;
		}
	}
	cout << dist;
}

//Sol 1)	������ �� ������ �Ÿ� �� ���ؼ� ���� -> n^2
//Sol 2)	x�� �����ؼ� �׶��� y��ȭ�� �ּҿ� ������ ���� ����
//			�� ������ �� x������ x��ȭ���� ������ ���̺��� Ŀ����
//			������ �ּҸ� ��� ���Ѵ�.?
//Sol 3)	1. x���� ���� ����
//			2. i��° ���� ���Ͽ� i-1��°������ �ּҰŸ� = d�� �Ҷ�
//			   i�� x�� -d �������� x������ 0 ~ i-1 ����
//			   i�� y�� ���̰� ���� ���� �� �Ʒ� ���� ���ؼ� -> �Ʒ�ã�� +1�ϸ� �ɵ�
//			   �Ÿ��� ���� -> d�� ����
//			3. ������ d���� 0,1�� �Ÿ��� �صδ°ɷ�.
//	map�� key���� ���Ͽ� ����