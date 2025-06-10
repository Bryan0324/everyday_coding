#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ssize_t long long
#define size_t unsigned long long

const double eps = 1e-10;

struct fixdb
{
    double _in = 0;
    fixdb(double n):_in(n){};
    bool operator==(const fixdb &b) const
    {
        return abs(_in-b._in) <= eps;
    }
    bool operator<=(const fixdb &b) const
    {
        return _in <= b._in+eps;
    }
    bool operator>=(const fixdb &b) const
    {
        return _in >= b._in-eps;
    }
    fixdb operator*(const fixdb &b) const
    {
        return fixdb(_in * b._in);
    }
    fixdb operator-(const fixdb &b) const
    {
        return fixdb(_in - b._in);
    }
    fixdb operator+(const fixdb &b) const
    {
        return fixdb(_in + b._in);
    }
    fixdb operator/(const fixdb &b) const
    {
        return fixdb(_in / b._in);
    }
    int operator()() const
    {
        if(abs(_in) <= eps) return 0;
        return _in > 0 ? 1 : 0;
    }
};
istream &operator>>(istream &in, fixdb &b)
{
    in >> b._in;
    return in;
}


template<class T>
struct point {
    T x, y;
    point(T _x = 0, T _y = 0) : x(_x), y(_y) {}
    point operator-(const point &b) const
    {
        return point(x - b.x, y - b.y);
    }
    T operator*(const point &b) const
    {
        return x * b.x + y * b.y;
    }
    T operator%(const point &b) const
    {
        return x * b.y - y * b.x;
    }
    int lmr(const point &p, const point &q) const
    {
        if(((p-*this)%(q-*this)) == 0)return 0;
        return ((p-*this)%(q-*this)) > 0 ? 1 : -1;
    }
    bool online(const point &p, const point &q) const
    {
        return lmr(p, q) == 0 && (p-*this)*(q-*this) <= 0;
    }
};

template<class T>
bool banana(const point<T> &p1, const point<T> &p2, const point<T> &q1, const point<T> &q2)
{
    if(p1.online(q1, q2) || p2.online(q1, q2) || q1.online(p1, p2) || q2.online(p1, p2))return true;
    return p1.lmr(q1, q2)*p2.lmr(q1, q2) < 0 && q1.lmr(p1, p2)*q2.lmr(p1, p2) < 0;
}
template<class T1>
istream &operator>>(istream &in, point<T1> &b)
{
    in >> b.x >> b.y;
    return in;
}

int main()
{
    
    cin.tie(0)->sync_with_stdio(false);
    size_t n;
    point<ssize_t> p1, p2, q1, q2;
    cin >> n;
    while(n--)
    {
        cin >> p1 >> p2 >> q1 >> q2;
        if(banana(p1, p2, q1, q2))cout << "Yes\n";
        else cout << "No\n";
    }
    
    
}
