#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
using ll = long long;

ll solve()
{
    ll n, tmp, ori_n;
    cin >> n;
    ori_n = n;
    ll sym = 0, cnt = 0;
    set<ll, greater<>> left;
    while(n--)
    {
        cin >> tmp;
        if(left.count(tmp))
        {
            left.erase(tmp);
            sym += tmp;
            cnt++;
        }else left.insert(tmp);
    }
    if(ori_n == 3)
    {
        if(*(left.begin()) >= sym*2)return 0;
        else return *(left.begin()) + sym*2;
    }
    ll before = LONG_LONG_MAX/4;
    left.insert(0);
    for(auto &i : left)
    {
        if(before-i < sym*2)return before+i+sym*2;
        before = i;
    }
    if(cnt == 1)return 0;
    return sym*2;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    

    ll t;
    cin >> t;
    while(t--)
    {
        cout << solve() << '\n';
    }
}

/* 
1 3 4

*/