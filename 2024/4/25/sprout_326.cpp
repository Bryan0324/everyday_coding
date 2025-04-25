#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define long long ssize_t
#define unsigned long long size_t
typedef pair<ssize_t, ssize_t> spell;
#define p first
#define c second
ssize_t n, M, m, r;

ssize_t persent()
{
    return ( (m*100-1) /M) + 1;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> M >> r;
    size_t time = 0;
    m = M;
    vector<spell> spells(n);
    for(auto &i : spells)cin >> i.p >> i.c;
    spells.push_back({-1000, -100});
    sort(spells.begin(), spells.end());
    priority_queue<ssize_t> avas;
    while(m > 0)
    {
        while(spells.back().p == 0 || spells.back().c == 0)spells.pop_back();
        while(persent() <= spells.back().p)
        {
            if(spells.back().c > 0)avas.push(spells.back().c);
            spells.pop_back();
        }
        time++;
        if(!avas.empty())
        {
            r -= avas.top();
            avas.pop();
        }else if(r >= 0)
        {
            cout << -1;
            return 0;
        }
        if(r < 0)m += r;
    }
    cout << time;
}


/* 

*/
