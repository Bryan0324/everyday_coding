#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
#pragma GCC optimize("O3")
#define ssize_t long long
#define size_t unsigned long long


int main()
{
    cin.tie(0)->sync_with_stdio(false);
    size_t n, x, cnt = 0;
    cin >> n >> x;
    vector<size_t> p(n);
    for(auto &i : p)cin >> i;
    sort(p.begin(), p.end());
    auto end = p.end();
    for (auto it = p.begin(); it < p.end(); it++)
    {
        if(*it > x)continue;
        else if(x-*it < *it)
        {
            cnt++;
            continue;
        }
        end = upper_bound(it+1, end, x-*it)-1;
        *end = LLONG_MAX;
        cnt++;
    }
    cout << cnt;
    
}

/* 
2 3 7 9

*/