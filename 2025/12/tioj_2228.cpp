#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

struct SegTree
{
    vector<int> node, lazytag;
    int n, INF = 0;
    int combine(int a, int b)
    {
        return max(a, b);
    }
    SegTree(int size)
    {
        n = 1 << (__lg(size-1)+1);
        node = lazytag = vector<int>(n*2);
        for(int i = n-1; i >= 0; i--)node[i] = combine(node[i<<1], node[i<<1|1]);
    }
    int get(int l)
    {
        int ret = node[l] + lazytag[l];
        while(l != 1)
        {
            l>>=1;
            ret += lazytag[l];
        }
        return ret;
    }
    int query(int l, int r)
    {
        int ret = INF;
        for (l += n, r += n; l < r; l>>=1, r>>=1)
        {
            if(l&1)ret = combine(ret, get(l++));
            if(r&1)ret = combine(ret, get(--r));
        }
        return ret;
    }
    void push(int l)
    {
        while(l != 1)
        {
            node[l>>1] = combine(node[l^1]+lazytag[l^1], lazytag[l]+node[l]);
            l>>=1;
        }
    }
    void modify(int l, int r, int x)
    {
        int ret = INF;
        for (l += n, r += n; l < r; l>>=1, r>>=1)
        {
            if(l&1)
            {
                lazytag[l] += x;
                push(l);
                l++;
            }
            if(r&1)
            {
                r--;
                lazytag[r] += x;
                push(r);
            }
        }
    }
};

typedef pair<pair<int, int>, pair<int, int>> shop_unit;
#define x first.first
#define val first.second
#define y second.first
#define side second.second


int main()
{
	cin.tie(0)->sync_with_stdio(false);
    
	int n;
    cin >> n;
    vector<shop_unit> shop(n*2);
    map<int, int> mix;
    for(int idx = 0; idx < n*2; idx+=2)
    {
        auto &i = shop[idx];
        cin >> i.x >> i.y >> i.side >> i.val;
        i.x -= i.side;
        i.val *= -1;
        int tmp = i.x+i.y;
        i.x = i.x-i.y;
        i.y = tmp;
        i.side *= 2;
        mix[i.y] = 0;
        mix[i.y+i.side] = 0;
        shop[idx+1] = i;
        shop[idx+1].val = -i.val;
        shop[idx+1].x = i.x + i.side;
    }
    sort(shop.begin(), shop.end());
    int cnt = 0;
    for (auto &i : mix)
    {
        i.second = cnt++;
    }
    
    //vector<int> e(cnt);
    SegTree st(cnt);
    int ans = 0;
    for(auto &i : shop)
    {
        st.modify(mix[i.y], mix[i.y+i.side]+1, -i.val);
        if(i.val < 0)ans = max(ans, st.query(0, cnt));
    }
    cout << ans;
}

/* 

指標版線段樹 (TLE orz)
#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

struct node
{
    node *l = nullptr, *r = nullptr;
    int val = 0, lazytag = 0;
    int combine(const int a, const int b)
    {
        return max(a, b);
    }
    node(vector<int>::iterator rl, vector<int>::iterator rr)
    {
        if(rl+1 == rr)
        {
            val = *rl;
            return;
        }
        int mid = (rr-rl)/2;
        l = new node(rl, rl+mid);
        r = new node(rl+mid, rr);
        val = combine(l->val, r->val);
        return;
    }
    void pushlazy()
    {
        if(l != nullptr)
        {
            l->val += lazytag;
            r->val += lazytag;
            l->lazytag += lazytag;
            r->lazytag += lazytag;
        }
        lazytag = 0;
    }
    int query(int rl, int rr, int nl, int nr)
    {
        int mid = nl + (nr-nl)/2;
        if(rl <= nl && nr <= rr)return val;
        pushlazy();
        if(rr <= mid)return l->query(rl, rr, nl, mid);
        if(mid <= rl)return r->query(rl, rr, mid, nr);
        return combine(l->query(rl, rr, nl, mid), r->query(rl, rr, mid, nr));
    }
    void modify(int rl, int rr, int x, int nl, int nr)
    {
        if(rl <= nl && nr <= rr)
        {
            val += x;
            lazytag += x;
            return;
        }
        pushlazy();
        int mid = nl + (nr-nl)/2;
        if(rl < mid)l->modify(rl, rr, x, nl, mid);
        if(mid < rr)r->modify(rl, rr, x, mid, nr);
        val = combine(l->val, r->val);
        return;
    }
};

struct SegTree
{
    node *root = nullptr;
    int size = 0;
    SegTree(vector<int> &arr)
    {
        root = new node(arr.begin(), arr.end());
        size = arr.size();
    }
    int query(int l, int r)
    {
        return root->query(l, r, 0, size);
    }
    void modify(int l, int r, int x)
    {
        root->modify(l, r, x, 0, size);
    }
};

typedef pair<pair<int, int>, pair<int, int>> shop_unit;
#define x first.first
#define val first.second
#define y second.first
#define side second.second


int main()
{
	cin.tie(0)->sync_with_stdio(false);
    
	int n;
    cin >> n;
    vector<shop_unit> shop(n*2);
    map<int, int> mix;
    for(int idx = 0; idx < n*2; idx+=2)
    {
        auto &i = shop[idx];
        cin >> i.x >> i.y >> i.side >> i.val;
        i.x -= i.side;
        i.val *= -1;
        int tmp = i.x+i.y;
        i.x = i.x-i.y;
        i.y = tmp;
        i.side *= 2;
        mix[i.y] = 0;
        mix[i.y+i.side] = 0;
        shop[idx+1] = i;
        shop[idx+1].val = -i.val;
        shop[idx+1].x = i.x + i.side;
    }
    sort(shop.begin(), shop.end());
    int cnt = 0;
    for (auto &i : mix)
    {
        i.second = cnt++;
    }
    
    vector<int> e(cnt);
    SegTree st(e);
    int ans = 0;
    for(auto &i : shop)
    {
        st.modify(mix[i.y], mix[i.y+i.side]+1, -i.val);
        if(i.val < 0)ans = max(ans, st.query(0, cnt));
    }
    cout << ans;
}

 
*/