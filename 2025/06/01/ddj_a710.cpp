#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ssize_t long long
#define size_t unsigned long long

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    size_t n, q, tmp;
    cin >> n >> q;
    tmp = floor(sqrt(n));
    vector<vector<size_t>> blocks(tmp, vector<size_t>(tmp));
    for(auto &i : blocks)for(auto &j : i)cin >> j;
    if(blocks[0].size()*blocks.size() < n)
    {
        blocks.push_back({});
        for(size_t i = 0; i < n-blocks[0].size()*(blocks.size()-1); i++)
        {
            cin >> tmp;
            blocks.back().push_back(tmp);
        }
    }
    vector<size_t> bsize(blocks.size(), blocks[0].size());
    bsize.back() = blocks.back().size();
    size_t d, k;
    while(q--)
    {
        cin >> d >> k;
        size_t now = 0;
        size_t i = 0;
        size_t s[2] = {min(d, k), max(d, k)};
        for(auto &sh : s)
        {
            for(;now < sh; i++)
            {
                now+=bsize[i];
                //cerr << '{' << bsize[i] << '}';
            }
            if(now != 0 && i != 0)now -= bsize[--i];
            //cerr << '[' << now << "]\n";
            for(size_t j = 0, cnt = 0;; j++)
            {
                if(blocks[i][j] != 0)cnt++;
                if(now+cnt == sh)
                {
                    if(sh == d && sh == k)
                    {
                        if(&s[0] == &sh)
                        {
                            blocks[i][j] = 0;
                            bsize[i]--;
                        }else cout << blocks[i][j] << '\n';
                    }
                    else if(sh == d)
                    {
                        blocks[i][j] = 0;
                        bsize[i]--;
                    }else cout << blocks[i][j] << '\n';
                    break;
                }
            }
        }
        //for(auto &i : blocks)for(auto &j : i)cerr << j << ' ';
        //cerr << "\n\n\n";
    }
}