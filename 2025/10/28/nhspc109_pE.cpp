#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
int main()
{
	cin.tie(0)->sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<bitset<2500>> people(n);
	int d, f;
	for(auto &i : people)
	{
		cin >> d;
		while(d--)
		{
			cin >> f;
			i[f] = 1;
		}
	}
	ull ans = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			if((people[i]&people[j]).any())ans++;
		}
	}
	cout << ans; 
}

 