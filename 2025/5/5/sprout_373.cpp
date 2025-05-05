#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
typedef unsigned long long ull;
size_t solve()
{
	ull n, m, tmp;
	cin >> n >> m;
	vector<ull> a;
	for(size_t i = 0; i < n; i++)
	{
		cin >> tmp;
		if(tmp<<1 >= m)a.push_back(tmp<<1);
		if(tmp >= m)a.push_back(tmp);
	}
    if(a.size() == 0)return 0;
	//for(auto &i : a)cout << i << ' ';
	//cout << '\n';
	vector<size_t> v = {a[0]};
    for (size_t i = 1; i < a.size(); i++)
    {
        auto it = upper_bound(v.begin(), v.end(), a[i]);
        if(it == v.end())v.push_back(a[i]);
        else *it = a[i];
    }
    return v.size();
}
int main()
{
	cin.tie(0)->sync_with_stdio(false);
	size_t t;
	cin >> t;
	while(t--)
	{
		cout << solve() << '\n';
	}
}
