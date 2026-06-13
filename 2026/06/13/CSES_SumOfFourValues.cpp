#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int count(vector<int>::iterator a, vector<int>::iterator b, int f)
{
	return upper_bound(a, b, f)-lower_bound(a, b, f);
};

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	
	int n, x;
	cin >> n >> x;
	
	vector<int> a(n);
	for(auto &i : a)cin >> i;
	
	vector<unordered_map<int, int>> cnt(n);
	vector<int> s;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			s.push_back(a[j]+a[i]);
			cnt[i][a[j]+a[i]]++;
			cnt[j][a[j]+a[i]]++;
		}
	}
	vector<int> ss(s);
	sort(ss.begin(), ss.end());
	int idx = 0;
	vector<int> ans;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < i; j++, idx++)
		{
			if(x-s[idx] < 0)continue;
			int c = count(ss.begin(), ss.end(), x-s[idx]);
			c -= cnt[i][x-s[idx]];
			c -= cnt[j][x-s[idx]];
			if(s[idx] == x-s[idx])c++;
			if(c > 0)
			{
				ans.push_back(i);
				ans.push_back(j);
				break;
			}
		}
		if(ans.size() == 2)break;
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(x-s[idx] == a[i]+a[j]
			 && ans[0] != i && ans[0] != j
			 && ans[1] != i && ans[1] != j)
			{
				ans.push_back(i);
				ans.push_back(j);
				break;
			}
		}
		if(ans.size() == 4)break;
	}
	if(ans.size() != 4)cout << "IMPOSSIBLE";
	else for(auto &i : ans)cout << i+1 << ' ';
}
