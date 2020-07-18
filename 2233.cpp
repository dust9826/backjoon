#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define MAX 2001
#define MAX_SQR 11

pair<int, int> pos[2001];	//노드번호에 따른 in, out의 위치
int posToi[4001];	//	위치를 갖고 노드번호 찾기
int parent[MAX_SQR + 1][MAX];
int depth[MAX];

void make_tree(string  s)
{
	int seq = 1;
	stack<int> t;	//	t.top() = 현제 노드의 번호
	t.push(0);
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '0')
		{
			parent[0][seq] = t.top();
			depth[seq] = depth[t.top()] + 1;
			t.push(seq++);
			pos[t.top()].first = i+1;
			posToi[i+1] = t.top();
		}
		else
		{
			pos[t.top()].second = i+1;
			posToi[i+1] = t.top();
			t.pop();
		}
	}
}

int LCA(int a, int b)
{
	if (depth[a] < depth[b])
		swap(a, b);
	if (depth[a] != depth[b])
	{
		for (int i = MAX_SQR; i >= 0; i--)
		{
			if (depth[a] - depth[b] >= (1 << i))
			{
				a = parent[i][a];
			}
		}
	}

	if (a == b)return a;
	for (int i = MAX_SQR; i >= 0; i--)
	{
		if (parent[i][a] != parent[i][b])
		{
			a = parent[i][a];
			b = parent[i][b];
		}
	}
	return parent[0][a];
}

int main()
{
	int n;
	string s;
	cin >> n;
	cin >> s;
	make_tree(s);

	for (int i = 1; i <= MAX_SQR; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}

	int a, b;
	cin >> a >> b;
	int ans = LCA(posToi[a], posToi[b]);
	cout << pos[ans].first << " " << pos[ans].second;
}