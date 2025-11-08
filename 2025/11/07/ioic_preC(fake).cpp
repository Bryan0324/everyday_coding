#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

typedef pair<int, int> point;
#define lr first
#define in second

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(auto &i : a)cin >> i;
    int k, l, r;
    while(q--)
    {
        bitset<(int)1e5 + 10> s;
        cin >> k;
        int ans = 0;
        vector<point> quest(k*2);
        for(int i = 0; i < k*2; i += 2)
        {
            cin >> quest[i].lr >> quest[i+1].lr;
            quest[i].in = -1;
            quest[i+1].in = 1;
        }
        sort(quest.begin(), quest.end());
        int now_p = 0, get = 0;
        for(auto &i : quest)
        {
            if(get == 0)now_p = i.lr;
            get -= i.in;
            if(get == 0)
            {
                for(int j = now_p-1; j < i.lr; j++)
                {
                    if(s[a[j]])ans++;
                    s[a[j]].flip();
                }
            }
        }
        cout << ans << '\n';
    }
}