#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;



int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for(auto &i : v)cin >> i;
    vector<int> last(m, -1);
    vector<pair<int, int>> ret(m);

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        stack<int> mono;
        for(int j = 0; j < m; j++)
        {
            if(v[i][j] == '*')last[j] = i;
            
            while(!mono.empty())
            {
                if(i-last[mono.top()] < i-last[j])break;
                mono.pop();
            }
            ret[j].first = mono.empty() ? 0 : mono.top()+1;
            mono.push(j);
        }
        mono = stack<int>();
        for(int j = m-1; j >= 0; j--)
        {
            if(v[i][j] == '*')last[j] = i;
            
            while(!mono.empty())
            {
                if(i-last[mono.top()] < i-last[j])break;
                mono.pop();
            }
            ret[j].second = mono.empty() ? m-1 : mono.top()-1;
            mono.push(j);
        }
        for(int j = 0; j < m; j++)ans = max(ans, (ret[j].second - ret[j].first + 1)*(i-last[j]));
    }
    cout << ans;
}

