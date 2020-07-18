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
vector<pll> v;	//x값에 대해 정렬
map<pll, int> m;	//y값에 대해 정렬
int dist = 1e9;		//최소 거리 제곱
int cand_start = 0;	//x기준 구역의 최소위치

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

	//x값에 대해 정렬
	sort(v.begin(), v.end());

	//m의 초기값 설정
	m[{v[0].second, v[0].first}] = 0;
	m[{v[1].second, v[1].first}] = 0;
	dist = get_len(v[0], v[1]);
	
	for (int cur_idx = 2; cur_idx < n; cur_idx++)
	{
		pll cur = v[cur_idx];
		//x기준 범위 밖의 map 삭제
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

		//y기준 범위 low ~ high 검색
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

//Sol 1)	점에서 각 점까지 거리 다 구해서 정렬 -> n^2
//Sol 2)	x값 정렬해서 그때의 y변화량 최소와 제곱한 길이 구함
//			그 다음에 그 x값에서 x변화량이 제곱한 길이보다 커지기
//			전까지 최소를 계속 구한다.?
//Sol 3)	1. x값에 대해 정렬
//			2. i번째 값에 대하여 i-1번째까지의 최소거리 = d라 할때
//			   i의 x값 -d 에서부터 x까지의 0 ~ i-1 에서
//			   i와 y값 차이가 가장 작은 위 아래 값을 구해서 -> 아래찾고 +1하면 될듯
//			   거리비교 시작 -> d값 갱신
//			3. 최초의 d값은 0,1의 거리로 해두는걸로.
//	map이 key값에 대하여 정렬