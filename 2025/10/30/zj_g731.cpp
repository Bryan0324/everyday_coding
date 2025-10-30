#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

typedef pair<int, int> Pos;
#define x first
#define y second

struct fac
{
    ull top, bottom;
    fac(ull _top, ull _bottom): top(_top), bottom(_bottom) {}
    void operator+=(const fac &a)
    {
        ull b = __gcd(bottom, a.bottom);
        top = top * a.bottom/b  +  a.top * bottom/b;
        bottom = bottom/b*a.bottom;
        b = __gcd(top, bottom);
        top /= b;
        bottom /= b;
    }
    
};

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    string s;
    cin >> s;
    vector<int> v(1, 0);
    for(auto &i : s)
    {
        if(i < '0' || i > '9')v.push_back(0);
        else 
        {
            v.back() *= 10;
            v.back() += i - '0';
        }
    }
    vector<fac> facs;
    for (int i = 0; i < v.size(); i+=2)
    {
        facs.push_back(fac(v[i], v[i+1]));
    }

    for(int i = 1; i < facs.size(); i++)
    {
        facs[i] += facs[i-1];
        cout << '=' << facs[i].top << '/' << facs[i].bottom;
        for(int j = i+1; j < facs.size(); j++)cout << '+' << facs[j].top << '/' << facs[j].bottom;
        cout << '\n';
    }
}