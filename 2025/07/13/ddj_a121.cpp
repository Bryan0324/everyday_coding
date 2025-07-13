#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ssize_t long long
#define size_t unsigned long long

const int MOD = 1e9+7;


int main()
{
    cin.tie(0)->sync_with_stdio(false);

    size_t n, k;
    cin >> n >> k;
    k = n*(n+1)/2 - k + 1;
    vector<size_t> a(n);
    for(auto &i : a)cin >> i;
    pair<size_t, size_t> areas = {0, (1e16+1)};
    while(areas.first+1 < areas.second)
    {
        size_t now = 0, cnt = 0;
        size_t mid = (areas.first+areas.second)/2;
        for(size_t i = 0, j = 0; j < n; j++)
        {
            now += a[j];
            while(now >= mid+a[i])
            {
                now -= a[i];
                i++;
            }
            if(now >= mid)cnt += i+1;
        }
        //cerr << mid << ' ' << cnt << '\n';
        if(k <= cnt)
        {
            areas.first = mid;
        }else if(k > cnt)
        {
            areas.second = mid;
        }
    }
    cout << areas.first;


}