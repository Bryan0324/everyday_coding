#include<bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;

const ull MOD = 1e9+7;

struct BIT 
{
	ull n;
	vector<ull> node;
	BIT(ull _n): n(_n), node(n, 0) {};

	void modify(ull idx, ull val)
	{
		idx++;
		for(;idx <= n; idx += idx & (-idx))
		{
			node[idx-1] += val;
			node[idx-1] %= MOD;
		}
	}

	ull query(ull idx)
	{
		ull ret = 0;
		for(; idx > 0; idx -= idx & (-idx))
		{
			ret += node[idx-1];
			ret %= MOD;
		}
		return ret;
	}
};

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    ull n;
	cin >> n;
	vector<ull> dp(n), x(n);
	for(auto &i : x)cin >> i;
	vector<ull> sx = x;
	sort(sx.begin(), sx.end());
	auto un_end = unique(sx.begin(), sx.end()) - sx.begin();
	unordered_map<ull, ull> get_idx;
	for(int i = 0; i < un_end; i++)
	{
		get_idx[sx[i]] = i;
	}

	for(auto &i : x)i = get_idx[i];

	BIT bit(n);
	for(int i = 0; i < n; i++)
	{
		dp[i] = 1+bit.query(x[i]);
		bit.modify(x[i], dp[i]);
	}
	ull ans = 0;
	for(auto &i : dp)
	{
		ans += i;
		ans %= MOD;
	}
	cout << ans;
}