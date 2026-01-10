#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

void solve()
{
    int n, w;
    cin >> n >> w;
    vector<ull> c(n);
    for(auto &i : c)cin >> i;
    vector<ull> cnt(w*2);
    for(int i = 1; i <= n; i++)cnt[i%(2*w)] += c[i-1];

    ull ans = LLONG_MAX;
    queue<int> window;
    ull now = 0;
    for(int i = 0; i < w; i++)
    {
        window.push(i);
        now += cnt[i];
    }
    for(int i = w; i < w*2*2; i++)
    {
        ans = min(ans, now);

        window.push(i%(2*w));
        now += cnt[i%(2*w)];
        now -= cnt[window.front()];
        window.pop();
    }
    ans = min(ans, now);
    cout << ans << '\n';

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
1   1
10  10
10  10
1   1

*/