#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
typedef pair<size_t, size_t> pos;
#define x first
#define y second

void re(vector<size_t> &now, vector<size_t> &ans, size_t start = 0)
{
    if(now.size() == 0)return;
    if(now.size() == 1)
    {
        ans[start] = now[0];
        return;
    }
    vector<size_t> odd, even;
    for (size_t i = 0; i < now.size(); i++)
    {
        if((i & 1) == 1)odd.push_back(now[i]);
        else even.push_back(now[i]);
    }
    re(even, ans, start);
    re(odd, ans, start+even.size());
    return;
}

int main()
{
    size_t n;
    cin >> n;
    vector<size_t> v(n), ans(n);
    for(auto &i : v)i = &i - &v[0]+1;
    re(v, ans);
    for(auto &i : ans)cout << i << ' ';
}
/* 

1 2 3 4 5 6
2 4 6 1 3 5
2 6 4 1 5 3
6 4 2 5 3 1

*/

