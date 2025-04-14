#include<bits/stdc++.h>
#include "lib0114.h"
using namespace std;

typedef pair<size_t, size_t> pos;
#define x first
#define y second

void f(pos key, vector<vector<pos>> &ans, pos now, size_t N)
{
    if (N == 1)return;
    size_t mid = N/2;
    pos nk = {now.x+mid, now.y+mid};
    vector<pos> nans;
    //右下
    if(nk.x <= key.x && nk.y <= key.y) f(key, ans, {nk.x, nk.y}, mid);
    else
    {
        nans.push_back({nk.x, nk.y});
        f({nk.x, nk.y}, ans, {nk.x, nk.y}, mid);
    }
    //右上
    if(nk.x <= key.x && key.y < nk.y) f(key, ans, {nk.x, now.y}, mid);
    else
    {
        nans.push_back({nk.x, nk.y-1});
        f({nk.x, nk.y-1}, ans, {nk.x, now.y}, mid);
    }
    //左下
    if(key.x < nk.x && nk.y <= key.y) f(key, ans, {now.x, nk.y}, mid);
    else
    {
        nans.push_back({nk.x-1, nk.y});
        f({nk.x-1, nk.y}, ans, {now.x, nk.y}, mid);
    }
    //左上
    if(key.x < nk.x && key.y < nk.y) f(key, ans, {now.x, now.y}, mid);
    else
    {
        nans.push_back({nk.x-1, nk.y-1});
        f({nk.x-1, nk.y-1}, ans, {now.x, now.y}, mid);
    }
    ans.push_back(nans);
    return;
}
void solve(int N, int X, int Y)
{
    vector<vector<pos>> ans;
    f({X, Y}, ans, {1, 1}, N);
    for(auto &i : ans) Report(i[0].x, i[0].y, i[1].x, i[1].y, i[2].x, i[2].y);
}
