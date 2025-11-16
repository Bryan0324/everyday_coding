//https://codeforces.com/contest/2169/problem/C
#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
using ll = long long;
 
void solve()
{
   ll n;
   cin >> n;
   vector<ll> a(n);
   for(auto &i : a)cin >> i;
   vector<ll> presum(n+1);
   for (ll i = 1; i <= n; i++)
   {
        presum[i] += presum[i-1] + a[i-1];
   }
   ll ans = 0, dl = INT_MIN, dr = INT_MIN;
   for(ll r = 1; r <= n; r++)
   {
		ll l = r;
		dl = max(dl, presum[l-1] - l*l + l);
		dr = r*r + r - presum[r];
    	ans = max(ans, dl+dr); 
   }
   cout << presum[n]+ans << '\n';
}
/* 
r^2 - l^2 + l + r
*/
int main()
{
    cin.tie(0)->sync_with_stdio(false);
 
    int t;
    cin >> t;
    while(t--)solve();
}