#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ssize_t long long
#define size_t unsigned long long


#define x first
#define y second

// debug
// #define cerr //

void solve(size_t &n)
{
    vector<pair<size_t, ssize_t>> tl(n*2);
    for(size_t i = 0; i < n*2; i+=2)
    {
        cin >> tl[i].first >> tl[i+1].first >> tl[i].second;
        tl[i+1].second = -tl[i].second;
        tl[i+1].first++;
    }
    sort(tl.begin(), tl.end());

    size_t ans = 0;
    size_t now = 0;
    for(size_t i = 0; i < n*2;)
    {
        now += tl[i].second;
        for(++i;i < n*2 && tl[i-1].first == tl[i].first; i++)
        {
            now += tl[i].second;
        }
        if(now > ans)ans = now;
    }
    cout << ans << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    size_t n;
    while(cin >> n)solve(n);
}