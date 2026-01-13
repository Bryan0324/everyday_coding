#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

typedef pair<ll, ll> Pos;
#define x first
#define y second

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<Pos> a(n);
    ull ans = 0;
    for(auto &i : a)cin >> i.x >> i.y;
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            for(int k = j+1; k < n; k++)
            {
                if((a[i].y-a[j].y)*(a[k].x-a[j].x) != (a[k].y-a[j].y)*(a[i].x-a[j].x))ans++;
            }
        }
    }
    cout << ans;
}

