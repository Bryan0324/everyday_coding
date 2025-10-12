#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

const int MOD = 1e9 + 7;


vector<int> totals;
void mim(int f, int e, int x, vector<int> &t, ull &total, int sum = 0)
{
    if(sum > x)return;

    for (f; f < e; f++)
    {
        mim(f+1, e, x, t, total, sum+t[f]);
    }

    
    if(e != t.size())totals.push_back(sum);
    else total += upper_bound(totals.begin(), totals.end(), x-sum) - 
                lower_bound(totals.begin(), totals.end(), x-sum);
    return;
}

int main() 
{
    cin.tie(0)->sync_with_stdio(false);

    int n, x;
    cin >> n >> x;
    vector<int> t(n);
    for(auto &i : t)cin >> i;
    ull total = 0;
    mim(0, t.size()/2, x, t, total);
    sort(totals.begin(), totals.end());
    mim(t.size()/2, t.size(), x, t, total);
    cout << total;
}