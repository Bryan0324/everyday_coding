#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
typedef pair<int, int> Pos;
#define x first
#define y second
int solve()
{
    int n, m;
    cin >> n >> m;
    Pos target;
    cin >> target.x >> target.y;
    vector<int> ys(n), xs(m);
    for(auto &i : ys)cin >> i;
    for(auto &i : xs)cin >> i;
    return lower_bound(ys.begin(), ys.end(), target.y)-ys.begin() + 
            lower_bound(xs.begin(), xs.end(), target.x)-xs.begin();
}
 
 
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)
    {
        cout << solve() << '\n';
    }
}