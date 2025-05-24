#include <bits/stdc++.h>
using namespace std;
/* #pragma GCC optimize("O3")
const int MOD = 1e9 + 7; */
#define ssize_t long long
#define size_t unsigned long long

struct pos : pair<ssize_t, ssize_t>
{
    ssize_t &x = first, &y = second;
    pos(pair<ssize_t, ssize_t> p = {0ll, 0ll})
    {
        x = p.first;
        y = p.second;
    }
};


bool equal(const double a, const double b)
{
    return abs(a-b) < 1e-5;
}


size_t solve()
{
    size_t n;
    cin >> n;
    vector<pos> p(n);
    for(auto &i : p)cin >> i.x >> i.y;
    size_t line = 0;
    unordered_map<size_t, size_t> lines;
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = i+1; j < n; j++)
        {
            line = 0;
            auto &x1 = p[i].x;
            auto &y1 = p[i].y;
            auto &x2 = p[j].x;
            auto &y2 = p[j].y;
            double a = (y1*x2 - y2*x1);
            if(x1 == x2)continue;
            a /= (double)x2*x1*(x1 - x2);
            if( a >= 0. )continue;
            double b = (y1 - a*x1*x1);
            b /= (double)x1;
            for(size_t k = 0; k < n; k++)
            {
                if( equal(p[k].x*p[k].x*a + p[k].x*b, p[k].y) )
                {
                    line |= 1ull << k;
                }
            }
            lines[line];
        }
    }
    vector<size_t> dp(1ull << n, LLONG_MAX);
    dp[0] = 0;
    for(auto &l : lines)
    {
        for (size_t k = 0; k < 1; k++)
        {
            if(dp[k] == LLONG_MAX)continue;
            dp[k | l.first] = min(dp[k | l.first], dp[k]+1);
        }
    }
    for(auto &l : lines)
    {
        for (size_t k = l.first+1; k < (1ull << n); k++)
        {
            if(dp[k] == LLONG_MAX)continue;
            dp[k | l.first] = min(dp[k | l.first], dp[k]+1);
        }
    }
    if(dp.back() != LLONG_MAX)return dp.back();
    for (size_t k = 0; k < (1ull << n); k++)
    {
        if(dp.back() <= dp[k])continue;
        for(size_t i = 1; i < 1ull<<n; i<<=1)if((k & i) == 0)++dp[k];
        if(dp.back() > dp[k])dp.back() = dp[k];
    }
    return dp.back();
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    size_t t;
    cin >> t;
    while(t--)cout << solve() << '\n';

}
/* 

2
7
1 3
2 4
3 3
2 6
4 8
1 1
1 2
6
1 8
2 12
3 12
4 4
5 5
6 6
*/
