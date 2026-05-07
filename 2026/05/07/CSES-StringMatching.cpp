#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    string s, t;
    cin >> s >> t;

    vector<int> failure(t.size());
    for(int i = 1, j = 0; i < failure.size(); i++)
    {
        while(j > 0 && t[i] != t[j])j = failure[j - 1];

        if(t[i] == t[j])j++;

        failure[i] = j;
    }

    int ans = 0;
    for(int i = 0, j = 0; i < s.size(); i++)
    {
        if(s[i] == t[j])
        {
            if(++j == t.size())
            {
                ans++;
                j = failure[j-1];
            }
        }else
        {
            if(j != 0)i--;
            j = j == 0? 0 : failure[j-1];
        }
    }
    cout << ans;
}