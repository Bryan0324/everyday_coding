#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ssize_t long long
#define size_t unsigned long long

struct point {
    ssize_t x, y;
    point(ssize_t _x = 0, ssize_t _y = 0) : x(_x), y(_y) {}
    point operator-(const point &b) const
    {
        return point(x - b.x, y - b.y);
    }
    ssize_t operator*(const point &b) const
    {
        return x * b.x + y * b.y;
    }
    ssize_t operator^(const point &b) const
    {
        return x * b.y - y * b.x;
    }
};


int main()
{
    cin.tie(0)->sync_with_stdio(false);
    ssize_t n;
    point b, p;
    cin >> n;
    cin >> b.x >> b.y;
    vector<point> v(n-1);
    for(size_t i = 0; i < n-1; i++)
    {
        cin >> p.x >> p.y;
        v[i] = p-b;
        //cerr << v[i].x << ' ' << v[i].y << "]\n";
        b = p;
    }
    size_t head = 0, left = 0, right = 0;
    for(size_t i = 1; i < n-1; i++)
    {
        if((v[i-1]^v[i]) > 0)left++;
        else if((v[i-1]^v[i]) < 0)right++;
        else if(v[i-1]*v[i] < 0)head++;
    }
    cout << left << ' ' << right << ' ' << head << '\n';
}
