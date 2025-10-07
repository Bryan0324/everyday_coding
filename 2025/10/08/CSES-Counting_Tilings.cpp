#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

const int MOD = 1e9 + 7;

int main() 
{
    cin.tie(0)->sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    swap(n, m);
    vector<vector<int>> rolling(2, vector<int>(1 << m));
    auto now = &rolling[0];
    auto before = &rolling[1];
    (*now)[0] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            swap(now, before);
            fill(now->begin(), now->begin() + (1 << m), 0);
            for (int s = 0; s < (1 << m); s++)
            {
                if(j+1 != m && (s & (1 << j)) == 0 && (s & (1 << j+1)) == 0)
                {
                    (*now)[s ^ (1 << j+1)] += (*before)[s];
                }
                (*now)[s ^ (1 << j)] += (*before)[s];
                (*now)[s ^ (1 << j)] %= MOD;
            }
        }
    }
    cout << (*now)[0];
}