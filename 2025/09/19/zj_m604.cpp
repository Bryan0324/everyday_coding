#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;
using ll = long long;

int solve()
{
    cin.tie(0)->sync_with_stdio(false);

    
    ull m, k;
    ull total = 0;
    cin >> m;
    vector<deque<int>> seg(m);
    for(auto &i : seg)
    {
        cin >> k;
        i = deque<int>(k);
        total += k;
    }
    for(auto &i : seg)for(auto &j : i)cin >> j;
    ull cnt = 1;
    while(cnt*(cnt+1) / 2 < total)cnt++;
    if(cnt*(cnt+1) / 2 != total)return -1;
    vector<deque<int>> left;
    vector<vector<int>> ans(cnt);
    cout << cnt << '\n';
    for(cnt; cnt >= 1; cnt--)
    {
        int tmp = 0;
        for(int i = 0; i < left.size(); i++)if(left[i].size() > left[tmp].size())tmp = i;
        if(!left.empty())if(left[tmp].size() >= cnt)
        {
            for(int t = 0; t < cnt; t++)
            {
                ans[cnt-1].push_back(left[tmp].back());
                left[tmp].pop_back();
            }
            continue;
        }

        tmp = 0;
        for(int i = 0; i < seg.size(); i++)if(seg[i].size() > seg[tmp].size())tmp = i;
        if(seg[tmp].size() >= cnt)
        {
            for(int t = 0; t < cnt; t++)
            {
                ans[cnt-1].push_back(seg[tmp].back());
                seg[tmp].pop_back();
            }
            continue;
        }

        int s_tmp = 0;
        for(int i = 0; i < seg.size(); i++)
        {
            if(s_tmp == tmp)s_tmp = i;
            if(i != tmp)if(seg[i].size() > seg[s_tmp].size())s_tmp = i;
        }
        for(int t = 0; !seg[tmp].empty(); t++)
        {
            ans[cnt-1].push_back(seg[tmp].back());
            seg[tmp].pop_back();
        }
        left.push_back({});
        for(auto &i : seg[s_tmp])
        {
            if(ans[cnt-1].size() == cnt)left.back().push_back(i);
            else ans[cnt-1].push_back(i);
        }
        seg[s_tmp] = deque<int>();
        if(left.back().size() == 0)left.pop_back();
    }
    for(auto &i : ans)
    {
        for(auto &j : i)cout << j << ' ';
        cout << '\n';
    }
    return 0;

}

int main()
{
    if(solve() == -1)cout << "-1";
}