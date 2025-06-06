#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ssize_t long long
#define size_t unsigned long long


void solve()
{
    string now;
    cin >> now;
    vector<set<pair<char, size_t>>> suffix(now.size()+2);
    unordered_map<char, size_t> have;
    for (ssize_t i = now.size(); i >= 0; i--)
    {
        suffix[i] = suffix[i+1];
        if(have.find(now[i]) == have.end())
        {
            suffix[i].insert({now[i], i});
            have[now[i]] = i;
        }else
        {
            suffix[i].erase({now[i], have[now[i]]});
            suffix[i].insert({now[i], i});
            have[now[i]] = i;
        }
    }
    queue<pair<string, ssize_t>> bfs;
    bfs.push({"", -1});
    while(!bfs.empty())
    {
        for(auto &i : suffix[bfs.front().second+1])if(i.first != 0)
        {
            bfs.push({bfs.front().first+i.first, i.second});
        }
        cout << bfs.front().first << '\n';
        bfs.pop();
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    size_t t;
    cin >> t;
    while(t--)solve();
}