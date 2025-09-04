#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    ull n, q;
    cin >> n >> q;
    char c;
    vector<vector<ll>> sum(n+1, vector<ll>(n+1));
    for (ull i = 1; i <= n; i++)
    {
        for (ull j = 1; j <= n; j++)
        {
            cin >> c;
            sum[i][j] = (c == '*' ? 1 : 0);
            sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }
    ull x1, y1, x2, y2;
    while(q--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2)swap(x1, x2);
        if(y1 > y2)swap(y1, y2);
        cout << 
            sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1]
        << '\n';
    }
}
