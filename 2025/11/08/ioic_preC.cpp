#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

typedef pair<int, int> point;
#define lr first
#define in second

const int MAX_N = 1e5;
int pre_v[MAX_N/25 + 2] = {};
bitset<(int)1e5 + 10> pre_bs[MAX_N/25 + 2];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
	 int BLOCK_SIZE = max(25, (int)(n/sqrt(q*64)));
    for(auto &i : a)cin >> i;
    bitset<(int)1e5 + 10> s;
    for(int i = 0, bid = 0; i < n; i++)
    {
        if(i % BLOCK_SIZE == 0)
        {
            bid++;
            pre_bs[bid] = pre_bs[bid-1];
            pre_v[bid] = pre_v[bid-1];
        }
        if(pre_bs[bid][a[i]])pre_v[bid]++;
        pre_bs[bid][a[i]].flip();
    }
    int k, l, r;
    while(q--)
    {
        s.reset();
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
                now_p--;
                for(int &j = now_p; j < i.lr && j % BLOCK_SIZE; j++)
                {
                    if(s[a[j]])ans++;
                    s[a[j]].flip();
                }
                if(now_p / BLOCK_SIZE < i.lr / BLOCK_SIZE)
                {
                    ans += pre_v[i.lr / BLOCK_SIZE + 1 - 1] - pre_v[now_p / BLOCK_SIZE + 1 - 1];
                    pre_bs[i.lr / BLOCK_SIZE].flip();
                    ans -= (pre_bs[now_p / BLOCK_SIZE] & (pre_bs[i.lr / BLOCK_SIZE])).count();
                    pre_bs[i.lr / BLOCK_SIZE].flip();
                    ans += (s & (pre_bs[now_p / BLOCK_SIZE] ^ (pre_bs[i.lr / BLOCK_SIZE]))).count();
                    s ^= (pre_bs[now_p / BLOCK_SIZE] ^ (pre_bs[i.lr / BLOCK_SIZE]));
                    now_p = (i.lr / BLOCK_SIZE) * BLOCK_SIZE;
                }
                
                for(int &j = now_p; j < i.lr; j++)
                {
                    if(s[a[j]])ans++;
                    s[a[j]].flip();
                }
            }
        }
        cout << ans << '\n';
    }
}