#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
using ll = long long;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
 
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(auto &i : a)cin >> i;
    a.push_back(0);
    sort(a.begin(), a.end());
    int x, y;
    while(q--)
    {
        cin >> x >> y;
        auto start = lower_bound(a.begin(), a.end(), x) - a.begin() - 1;
        int mid = start;
        for(int s = start, e = n+1; s+1 < e;)
        {
            mid = (s+e)/2;
            if((a[mid]-x+1)-(mid-start) < y)s = mid;
            else e = mid;
            mid = s;
        }
        int cnt = (y - ((a[mid]-x+1)-(mid-start)));
        cout << a[mid]+cnt << '\n';
    }
}