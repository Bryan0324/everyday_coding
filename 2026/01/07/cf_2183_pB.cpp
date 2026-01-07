#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &i : a)cin >> i;
    sort(a.begin(), a.end());
    int mex = 0;
    for(auto &i : a)
    {
        if(mex < i)break;
        mex = i+1;
    }
    cout << min(mex, k-1) << '\n';
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--)
    {
        solve();   
    }
}
/* 
0 1 2 3 0 0 0  

*/
