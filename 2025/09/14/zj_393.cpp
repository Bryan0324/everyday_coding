#include<bits/stdc++.h>
using namespace std;

#define gcd __gcd

using ull = unsigned long long;
using ll = long long;

string one_ans(ll q, ll p)
{
    ll g = gcd(abs(q), abs(p));
    string ret;
    ret += to_string(q/g);
    if(p/g != 1)ret += '/' + to_string(p/g);
    return ret;
}
 
 
void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll q = -b, p = 2*a;
    ll s = b*b - 4*a*c, r = 1;
    if(s == 0)
    {
        cout << "x=" << one_ans(q, p);
        return;
    }
    bool is_negative = false;
    if(s < 0)
    {
        is_negative = true;
        s *= -1;
    }
    
    unordered_map<ll, ll> m;
    for(int i = 2; s != 1; i++)
    {
        while(s % i == 0)
        {
            m[i]++;
            s /= i;
        }
    }
    for(auto &i : m)
    {
        if((i.second&1) == 1)s *= i.first;
        i.second >>= 1;
        for(; i.second > 0; i.second--)
        {
            r *= i.first;
        }
    }
    ll g = abs(gcd(gcd(q, r), p));
    q /= g;
    r /= g;
    p /= g;
    
    /* if(!is_negative && s == 1)
    {
        cout << "x1=" << one_ans(q+r, p) << '\n';
        cout << "x2=" << one_ans(q-r, p) << '\n';
        return;
    } */
    string tokens[2];
    if(p != 1)tokens[0] += "[";
    tokens[0] +=to_string(q);
    if(r != 1)tokens[1] += to_string(r);
    if(s != 1)
    {
        tokens[1] += "\\sqrt{";
        tokens[1] += to_string(s);
        tokens[1] += "}";
    }
    if(is_negative)tokens[1] += "i";
    if(p != 1)
    {
        tokens[1] += "]/";
        tokens[1] += to_string(p);
    }
    cout << "x1=" << tokens[0] << '+' << tokens[1] << '\n';
    cout << "x2=" << tokens[0] << '-' << tokens[1] << '\n';
    return;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
}