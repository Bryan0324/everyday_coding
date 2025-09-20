#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
using ull = unsigned long long;
using ll = long long;
 
bool solve()
{
    int n;
    cin >> n;
    deque<char> s(n);
    for(auto &i : s)cin >> i;
    s.push_front('0');
    s.push_back('1');
    vector<vector<int>> simple = {{}};
    for(int i = 1; i < n+1; i++)
    {
        if(s[i] == '1' && s[i+1] == '1')
        {
            if(simple.back().size() != 0)simple.push_back({});
        }
        else if(s[i] == '0')
        {
            if(s[i+1] == '1')
            {
                if(i == n)simple.back() = {2};
                else if(s[i-1] == '0')simple.back() = {2};
                else 
                {
                    if(simple.back().empty())simple.back().push_back(1);
                    else if(simple.back().back() != 2)simple.back().push_back(1);
                }
            }
        }
    }
    
    for(auto &i : simple)
    {
        if(i.size() == 0)continue;
        if(i.back() == 2)continue;
        if(i.size() & 1)return false;
    }
    return true;
}
 
int main()
{
    cin.tie(0)->sync_with_stdio(false);
 
    int t;
    cin >> t;
    while(t--)
    {
        if(solve())cout << "YES\n";
        else cout << "NO\n";
    }
}