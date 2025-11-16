//https://codeforces.com/contest/2166/problem/A
#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
using ll = long long;

void solve()
{
	int arr[26] = {};
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(auto &i : s)arr[i-'a']++;
	cout << n-arr[s.back()-'a'] << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
 
    int t;
    cin >> t;
    while(t--)solve();
}