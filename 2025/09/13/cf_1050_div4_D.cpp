#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
typedef pair<int, int> Pos;
#define x first
#define y second
ull solve()
{
    int n, tmp;
    cin >> n;
    vector<int> odd;
    ull even = 0;
    ull ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if(tmp & 1)odd.push_back(tmp);
        else even += tmp;
    }
    if(odd.size() == 0)return 0;
    sort(odd.begin(), odd.end());
    int end = 0;
    for (int i = odd.size()-1; i >= end; i--, end++)
    {
        ans += odd[i];
    }
    return ans + even;
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