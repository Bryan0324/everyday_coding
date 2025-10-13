#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

const int MOD = 1e9 + 7;
void solve() 
{

    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i+1; 
    }
    sort(a.begin(), a.end());

    vector<int> sorted(n);
    for (int i = 0; i < n; i++)sorted[i] = a[i].first;

    for(int i = 0; i < n-2; i++)
    {
        for(int l = i+1, r = n-1; l != r;)
        {
            if(sorted[l] + sorted[r] == x - sorted[i])
            {
                cout << a[i].second << ' ' << a[l].second << ' ' << a[r].second;
                return;
            }
            if(sorted[l] + sorted[r] < x - sorted[i])l++;
            else r--;
        }
    }
    cout << "IMPOSSIBLE";
    return;
}


/*  n^2 log(n)
void solve() 
{

    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i+1; 
    }
    sort(a.begin(), a.end());

    vector<int> sorted(n);
    for (int i = 0; i < n; i++)sorted[i] = a[i].first;

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            auto it = lower_bound(sorted.begin()+j+1, sorted.end(), x-sorted[i]-sorted[j]);
            if(it != sorted.end())if(*it == x-sorted[i]-sorted[j])
            {
                cout << a[i].second << ' ' << a[j].second << ' ' << a[it - sorted.begin()].second;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return;
}
 */
int main()
{
    
    cin.tie(0)->sync_with_stdio(false);
    solve();
}