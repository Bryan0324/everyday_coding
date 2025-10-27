#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
using ll = long long;

typedef pair<ull, int> pq_unit;
#define val first
#define idx second
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    vector<int> fruits(n);
    vector<vector<pq_unit>> bags(m);
    for(auto &i : fruits)cin >> i;
    int k;
    priority_queue<pq_unit, vector<pq_unit>, greater<>> pq;
    for(int i = 0; i < m; i++)
    {
        cin >> k;
        bags[i].resize(k);
        for(auto &j : bags[i])
        {
            cin >> j.idx;
            j.idx--;
            j.val = fruits[j.idx];
        }
        pq.push({0, i});
        sort(bags[i].begin(), bags[i].end(), greater<>());
    }
    vector<int> ans;

    while(!pq.empty())
    {
        auto top = pq.top();
        if(bags[top.idx].size() == 0)break;
        ans.push_back(bags[top.idx].back().idx+1);
        pq.push({top.val + bags[top.idx].back().val, top.idx});

        pq.pop();
        bags[top.idx].pop_back();
    }
    if(ans.size() != n)cout << "-1";
    else for(auto &i : ans)cout << i << ' ';
}