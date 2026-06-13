#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	
	ull n;
	cin >> n;
	
	vector<ll> t(n);
	for(auto &i : t)cin >> i;

	sort(t.begin(), t.end(), greater<int>());
	ull others = 0;
	for(int i = 1; i < n; i++)others += t[i];

	if(others < t[0])cout << others+t[0]+(t[0]-others);
	else cout << t[0]+others;
}
