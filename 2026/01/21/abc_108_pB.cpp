#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

typedef pair<int, int> Pos;
#define x first
#define y second

Pos operator-(const Pos a, const Pos b)
{
    return {a.x-b.x, a.y-b.y};
}
Pos operator+(const Pos a, const Pos b)
{
    return {a.x+b.x, a.y+b.y};
}
Pos operator!(const Pos a)
{
    return {a.y, -a.x};
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);

    Pos a, b;
    cin >> a.x >> a.y >> b.x >> b.y;

    Pos c = !(a-b) + b;
    Pos d = !(b-c) + c;
    cout << c.x << ' ' << c.y << ' ' << d.x << ' ' << d.y;
}

