#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
 
struct DP : vector<int>
{
    int n;
    vector<int> h;
    vector<vector<int>> backward, forward;
    DP(int _n, vector<int> &_h):n(_n), h(_h), backward(_n), forward(_n)
    {
        this->resize(_n);
        stack<int> _forward;
        for (int i = _n-1; i >= 0; i--)
        {
            while(!_forward.empty())
            {
                if(h[_forward.top()] >= h[i])break;
                forward[i].push_back((_forward.top()));
                _forward.pop();
            }
            _forward.push(i);
        }
        stack<int> _backward;
        for (int i = 0; i < _n; i++)
        {
            while(!_backward.empty())
            {
                if(h[_backward.top()] >= h[i])break;
                backward[i].push_back((_backward.top()));
                _backward.pop();
            }
            _backward.push(i);
        }
    };
    int &operator[](int k)
    {
        if(this->at(k) != 0)return this->at(k);
        int ret = 0;
        
        for(auto &i : backward[k])
        {
            if(h[i] >= h[k])break;
            ret = max(ret, (*this)[i]);
        }
        for(auto &i : forward[k])
        {
            if(h[i] >= h[k])break;
            ret = max(ret, (*this)[i]);
        }
        this->at(k) = ret+1;
        return this->at(k);
    }
};
 
 
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> h(n);
    for(auto &i : h)cin >> i;
    DP dp(n, h);
    int ans = 0;
    for(int i = 0; i < n; i++)ans = max(ans, dp[i]);
    cout << ans;
}
