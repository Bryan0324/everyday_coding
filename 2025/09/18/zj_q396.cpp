#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
const ull MOD = 1000000;
vector<vector<int>> pillar(3);

int pfind(int n)
{
	for(int i = 0; i < 3; i++)if(!pillar[i].empty())if(pillar[i].back() == n)return i;
	return -1;
}
int not_in_three(int a, int b)
{
	if(a > b)swap(a, b);
	if(a == 0 && b == 1)return 2;
	if(a == 0 && b == 2)return 1;
	if(a == 1 && b == 2)return 0;
	return -1;
}
int main()
{
	cin.tie(0)->sync_with_stdio(false);
	int n, m;
	ull ans = 0;
	cin >> n;
	if(n == 1)
	{
		cout << "0";
		return 0;
	}
	for(auto &i : pillar)
	{
		cin >> m;
		i.resize(m);
		for(auto &j : i)cin >> j;
	}
	vector<ull> sum(n+1);
	for(int i = 0; i < n; i++)
	{
		sum[i+1] = sum[i]*2 + 1;
		sum[i+1] %= MOD;
	}
	int top = pfind(n--);
	pillar[top].pop_back();
	while(n != 0)
	{
		auto next = pfind(n--);
		if(next == top)
		{
			pillar[top].pop_back();
		}else
		{
			ans += sum[n]+1;
			ans %= MOD;
			top = not_in_three(top, next);
			pillar[next].pop_back();
		}
	}
	cout << ans;
}