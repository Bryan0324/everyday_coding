#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
using ull = unsigned long long;
using ll = long long;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
 
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i : v)cin >> i;
    vector<int> arr;
    arr.push_back(v[0]);
    for(int i = 1; i < n; i++)
    {
        auto it = lower_bound(arr.begin(), arr.end(), v[i]);
        if(it == arr.end())arr.push_back(v[i]);
        else *it = v[i];
    }
    cout << arr.size();
}
/* 
10
3 46 77 16 59 32 22 41 87 89
*/