#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
using ll = long long;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
 
    int n;
    cin >> n;
    vector<int> x(n);
    for(auto &i : x)cin >> i;
    stack<int> stk;
    vector<int> ans(n);
    for(int i = 0; i < n; i++)
    {
        while(!stk.empty())
        {
            if(x[stk.top()] >= x[i])stk.pop();
            else break;
        }
        if(!stk.empty())
        {
            ans[i] = stk.top()+1;
        }
        stk.push(i);
    }
    for(auto &i : ans)cout << i << ' ';
}