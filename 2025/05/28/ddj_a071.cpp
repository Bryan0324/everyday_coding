#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ssize_t long long
#define size_t unsigned long long

#define weight first
#define to second.second
#define from second.first
typedef pair<size_t, pair<size_t, size_t>> edge;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    size_t n;
    while(cin >> n)
    {
        vector<size_t> t(n);
        for(auto &i : t)cin >> i;
        sort(t.begin(), t.end());
        size_t ans = 0;
        for(size_t i = 0; i < n; i++)
        {
            ans += t[i]*(n-i);
        }
        cout << ans << '\n';
    }
}