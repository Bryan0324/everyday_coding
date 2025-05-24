#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define ssize_t long long 
#define size_t unsigned long long

vector<pair<size_t, size_t>> ans;

void solve(size_t total, size_t start, size_t to)
{
	if(total == 1)
	{
		ans.push_back({start, to});
		return;
	}
	for(size_t i = 1; i <= 3; i++)if(start != i && to != i)solve(total-1, start, i);
	ans.push_back({start, to});
	for(size_t i = 1; i <= 3; i++)if(start != i && to != i)solve(total-1, i, to);
	return;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

	size_t n;
	cin >> n;
	solve(n, 1, 3);
	cout << ans.size() << '\n';
	for(auto &i : ans) cout << i.first << ' ' << i.second << '\n';
}
CSES-Tower_of_Hanoi
