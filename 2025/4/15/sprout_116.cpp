#include <bits/stdc++.h>
#include "lib0116.h"
using namespace std;
#pragma GCC optimize("O3")
typedef pair<size_t, size_t> pos;
#define x first
#define y second

void s(pos n, pos lim, vector<size_t> &ans)
{
    if(n.first == n.second)
    {
        //cerr << "mid: self" << '\n';
        ans[n.first-1] = lim.first;
        if(lim.first == lim.second)
        {
            //cerr << n.first << ":" << ans[n.first-1] << '\n';
            return;
        }
        size_t now = GetVal(n.first, lim.first), tmp;
        for (size_t i = lim.first+1; i <= lim.second; i++)
        {
            tmp = GetVal(n.first, i);
            if(now < tmp)
            {
                now = tmp;
                ans[n.first-1] = i;
            }
        }
        //cerr << n.first << ":" << ans[n.first-1] << '\n';
        return;
    }
    size_t mid = (n.first+n.second)/2;
    size_t now = GetVal(mid, lim.first), tmp;
    ans[mid-1] = lim.first;
    for (size_t i = lim.first+1; i <= lim.second; i++)
    {
        tmp = GetVal(mid, i);
        if(now < tmp)
        {
            now = tmp;
            ans[mid-1] = i;
        }
    }
    if(mid != n.first)s({n.first, mid-1}, {lim.first, ans[mid-1]-1}, ans);
    if(mid != n.second)s({mid+1, n.second}, {ans[mid-1]+1, lim.second}, ans);
}

void solve(int N, int M)
{
    vector<size_t> ans(N);
    s({1, N}, {1, M}, ans);
    for(auto &i : ans)Report(i);
}
/* 
vector<vector<size_t>> v = {
    {74, 59, 36, 28, 51},
    {36, 63, 15, 25, 17},
    {71, 64, 95, 43, 56},
    {72, 62, 30, 24, 74}
};
void Report(int val)
{
    cout << val << '\n';
    return;
}
int GetVal(int x, int y)
{
    cerr << "get:" << v[x-1][y-1] << "\ncontinue?";
    char c;
    cin >> c;
    return v[x-1][y-1];
}
int main()
{
    solve(4, 5);
}
 */


