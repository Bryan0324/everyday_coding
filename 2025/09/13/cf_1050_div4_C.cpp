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
    int point = 0;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)cin >> a[i] >> b[i];
    int now_time = 0, now_pos = 0;
    for (int i = 0; i < n; i++)
    {
        if(((a[i] - now_time) & 1) != abs(b[i]-now_pos))point--;
        now_pos = b[i];
        now_time = a[i];
    }
    return point + m;
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