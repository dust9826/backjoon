//#include<iostream>
//#define ep emplace
//#define eb emplace_back
//#define fi first
//#define se second
//#define all(x) (x).begin(),(x).end()
//using namespace std;
//typedef long long ll;
//typedef pair<int, int>pi;
//typedef pair<ll, ll>pl;
//const int inf = 1e9 + 7;
//const ll INF = 1e18 + 7;
//int l[300010], h[300010];
//int s[300010];
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int n = 300000;
//	int c = 5000000;
//	int it = 5;
//	l[0] = c;
//	l[3] = c - it;
//	h[0] = h[3] = c + 1;
//	l[1] = l[2] = c;
//	h[1] = h[2] = c + 3;
//	s[0] = c;
//	s[1] = c + 3;
//	for (int i = 2; i < n; i++)
//		s[i] = c - it * (i - 2);
//	for (int i = 4; i < n; i++)
//		l[i] = s[i], h[i] = s[i - 1];
//	l[n] = h[n] = s[n - 1];
//	cout << n << endl;
//	cout << s[0];
//	for (int i = 1; i < n; i++)
//		cout << ' ' << s[i];
//	cout << endl;
//	for (int i = 0; i <= n; i++)
//		cout << l[i] << ' ' << h[i] << endl;
//	return 0;
//}