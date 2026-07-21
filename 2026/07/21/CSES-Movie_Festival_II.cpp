#include<bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    int n, k;
	cin >> n >> k;

	vector<pair<int, int>> timeline(n);
	for(auto &i : timeline)cin >> i.first >> i.second;

	sort(timeline.begin(), timeline.end(), [](auto a, auto b){
		return a.second < b.second;
	});

	multiset<int> s;
	while(k--)s.insert(0);

	int ans = 0;
	
	for(auto &i : timeline)
	{
		auto it = s.upper_bound(i.first);
		if(it == s.begin())continue;
		ans++;
		it--;
		s.erase(it);
		s.insert(i.second);
	}
	cout << ans;
}