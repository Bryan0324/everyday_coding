#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

int solve()
{
    int n;
    cin >> n;
    if(n == 1)return 1;
    if(n == 2)return 9;
    
    return max((n*(n-1)-1)*5, (n*n-1)*4-n);
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

