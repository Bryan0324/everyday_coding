#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define ssize_t long long 
#define size_t unsigned long long
 


size_t sum = 0, ans = LLONG_MAX;

void dfs(vector<size_t> &apple, size_t now = 0, size_t ptr = 0)
{
    if(ptr == apple.size())
    {
        ans = min(ans, max(sum-now, now)-min(sum-now, now));
        return;
    }
    dfs(apple, now, ptr+1);
    dfs(apple, now+apple[ptr], ptr+1);
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    size_t n;
    cin >> n;
    vector<size_t> apple(n);
    for(auto &i : apple)cin >> i;
    for(auto &i : apple)sum += i;
    dfs(apple);
    cout << ans;
}
