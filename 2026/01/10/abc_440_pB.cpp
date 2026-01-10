#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
using ll = long long;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
 
    int n;
    cin >> n;
    vector<pair<int, int>> t(n);
    for(int i = 0; i < n; i++)
    {
        cin >> t[i].first;
        t[i].second = i+1;
    }
    sort(t.begin(), t.end());
    cout << t[0].second << ' ' << t[1].second << ' ' << t[2].second;
}