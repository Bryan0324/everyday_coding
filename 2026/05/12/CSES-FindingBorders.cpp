#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

const ull MOD = (1ull<<31)-1;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    int n, k;
    string s;
    cin >> s;
    n = s.size();

    vector<ull> rollings(n+1);
    vector<ll> d = {37};
    for(int i = 0; i < n; i++)
    {
        rollings[i+1] = rollings[i]*d[0]%MOD + s[i]-'a';
        rollings[i+1] %= MOD;
        d.push_back(d.back()*d[0]);
        d.back() %= MOD;
    }
    
    for(int i = 1; i < n; i++)
    {
        ull tmps = rollings[n-i]*d[i-1] %MOD;
        if(rollings[i] == (rollings[n]+MOD-tmps)%MOD)cout << i << ' ';
    }
}