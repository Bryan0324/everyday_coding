#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
#pragma GCC optimize("O3")
#define ssize_t long long
#define size_t unsigned long long


int solve()
{
    cin.tie(0)->sync_with_stdio(false);
    size_t n, m, tmp;
    cin >> n >> m;
    multiset<size_t> s;
    while(n--)
    {
        cin >> tmp;
        s.insert(tmp);
    }
    while(m--)
    {
        cin >> tmp;
        auto ub = s.upper_bound(tmp);
        if(ub == s.begin())
        {
            cout << "-1\n";
            continue;
        }
        ub--;
        cout << *ub << '\n';
        s.erase(ub);
    }
    return 0;
}

int main()
{
    solve();
}

/* 
2 3 7 9

*/