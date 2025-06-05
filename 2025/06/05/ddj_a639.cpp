#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ssize_t long long
#define size_t unsigned long long
/*
噢，你在看我的程式碼嗎，我剛剛被程設班github的二步驟驗證搞了一個多小時，
沒用好，心態炸裂
*/


void solve()
{
    string now;
    cin >> now;
    vector<vector<pair<char, size_t>>> suffix(now.size()+1);
    for (size_t i = 0; i < suffix.size(); i++)
    {
        unordered_set<char> have;
        for (size_t j = i; j < now.size(); j++)if(have.find(now[j]) == have.end())
        {
            suffix[i].push_back({now[j], j});
            have.insert(now[j]);
        }
        sort(suffix[i].begin(), suffix[i].end());
    }
    
    queue<pair<string, ssize_t>> bfs;
    bfs.push({"", -1});
    while(!bfs.empty())
    {
        for(auto &i : suffix[bfs.front().second+1])
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