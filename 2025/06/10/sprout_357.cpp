#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ssize_t long long
#define size_t long long

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
    T lmr(const point &p, const point &q) const
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
template<class T1>
bool cmp(point<T1> a, point<T1> b)
{
    if(a.x == b.x)return a.y < b.y;
    return a.x < b.x;
}

void solve()
{
    size_t n;
    cin >> n;
    vector<point<size_t>> ps(n);
    for(auto &i : ps)cin >> i;
    sort(ps.begin(), ps.end(), cmp<size_t>);
    vector<point<size_t>> t_hull, b_hull;
    
    for(auto &i : ps)
    {
        while(t_hull.size() >= 2 && t_hull.back().lmr(t_hull.end()[-2], i) <= 0)t_hull.pop_back();
        t_hull.push_back(i);
    }
    for(auto i = ps.end(); i > ps.begin(); i--)
    {
        while(b_hull.size() >= 2 && b_hull.back().lmr(b_hull.end()[-2], *(i-1)) <= 0)b_hull.pop_back();
        b_hull.push_back(*(i-1));
    }
    size_t ans = 0;
    for(size_t i = 0; i < t_hull.size()-2; i++)
    {
        ans += abs((t_hull[i+1]-t_hull[i])%(t_hull.back()-t_hull[i]));
    }
    for(size_t i = 0; i < b_hull.size()-2; i++)
    {
        ans += abs((b_hull[i+1]-b_hull[i])%(b_hull.back()-b_hull[i]));
    }
    cout << ans/2;
    if(ans % 2 == 0)cout << ".0\n";
    else cout << ".5\n";
}

int main()
{
    
    cin.tie(0)->sync_with_stdio(false);
    
    
    size_t t;
    cin >> t;
    while(t--)solve();
}