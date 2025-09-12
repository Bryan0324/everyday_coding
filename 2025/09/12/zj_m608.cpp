#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

struct Fraction
{
    ull top = 1, bottom = 1;
    Fraction(ull _top = 1, ull _bottom = 1):top(_top), bottom(_bottom) {};
    void flip()
    {
        swap(top, bottom);
    }
    ull split()
    {
        ull tmp = top / bottom;
        top %= bottom;
        flip();
        return tmp;
    }
};



int main()
{
    cin.tie(0)->sync_with_stdio(false);
    ull n;
    string s;
    cin >> n >> s;
    string in = to_string(n) + ';';
    Fraction f(0, 1);
    for (ull i = 1; i < s.size(); i++)
    {
        f.top *= 10;
        f.top += s[i] - '0';
        f.bottom *= 10;
    }
    f.flip();
    while(f.top != 0 && f.bottom != 0)
    {
        in += to_string(f.split()) + ',';
    }
    if(in.back() == ',' || in.back() == ';')in.pop_back();
    cout << in;
}