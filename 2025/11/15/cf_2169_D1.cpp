#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
using ll = long long;

ll f(ll p, ull y, ull x)
{
	while(x--)p -= p/y;
	return p;
}
const ull INF = 1e12+1;
void solve()
{
   ull x, y, k;
   cin >> x >> y >> k;
   ull l = 0;
   for(ull r = INF; l < r;)
   {
		ull mid = (l+r)/2;
		if(f(mid, y, x) < k)l = mid+1;
		else r = mid;
   }
   if(l != INF)cout << l << '\n';
   else cout << "-1\n";
}
/* 
OOOOXXXOOXOOOXXXX  O (X是被刪除的元素
12344445667899999 10 (剩餘個數 ((有單調性
*/
int main()
{
    cin.tie(0)->sync_with_stdio(false);
 
    int t;
    cin >> t;
    while(t--)solve();
}