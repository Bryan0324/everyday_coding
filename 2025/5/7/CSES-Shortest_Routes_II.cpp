#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define ssize_t long long 
#define size_t unsigned long long


int main()
{
	cin.tie(0)->sync_with_stdio(false);
	size_t n, m, q, a, b, c;
	cin >> n >> m >> q;
	vector<vector<size_t>> canva(n, vector(n, (size_t)LLONG_MAX));
	
	while(m--)
	{
		cin >> a >> b >> c;
		a--;
		b--;
		if(canva[a][b] > c)canva[b][a] = canva[a][b] = c;
	}
	for (size_t i = 0; i < n; i++)canva[i][i] = 0;
	for (size_t k = 0; k < n; k++)
	{
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				if(canva[i][j] > canva[i][k]+canva[k][j])canva[i][j] = canva[i][k]+canva[k][j];
			}
		}
	}
	while(q--)
	{
		cin >> a >> b;
		a--;
		b--;
		if(a > b)swap(a, b);
		if(canva[a][b] == LLONG_MAX)cout << "-1\n";
		else cout << canva[a][b] << '\n';
	}
}
