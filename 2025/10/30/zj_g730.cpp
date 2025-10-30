#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

typedef pair<int, int> Pos;
#define x first
#define y second

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    pair<Pos, Pos> rag1, rag2;
    Pos p1;
    cin >> rag1.first.x >> rag1.first.y
        >> rag1.second.x >> rag1.second.y
        >> rag2.first.x >> rag2.first.y
        >> rag2.second.x >> rag2.second.y
        >> p1.x >> p1.y;
    if(rag1.first.x > rag1.second.x)swap(rag1.first.x, rag1.second.x);
    if(rag1.first.y > rag1.second.y)swap(rag1.first.y, rag1.second.y);
    if(rag2.first.x > rag2.second.x)swap(rag2.first.x, rag2.second.x);
    if(rag2.first.y > rag2.second.y)swap(rag2.first.y, rag2.second.y);
    int ans = 2;
    if(rag1.first.x < p1.x && p1.x < rag1.second.x &&
        rag1.first.y < p1.y && p1.y < rag1.second.y)ans--;
    if(rag2.first.x < p1.x && p1.x < rag2.second.x &&
        rag2.first.y < p1.y && p1.y < rag2.second.y)ans--;
    cout << ans;
}