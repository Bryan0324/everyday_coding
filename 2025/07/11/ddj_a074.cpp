#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ssize_t long long
#define size_t unsigned long long

const int MOD = 1e9+7;


int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &i : a)cin >> i;

    int sum = 0, ans = 0;
    for(int i = 0, j = 0; j < n; j++)
    {
        sum += a[j];
        if(sum == k)ans++;
        while(sum >= k)
        {
            sum -= a[i];
            if(sum == k)ans++;
            i++;
        }
    }
    cout << ans;
}