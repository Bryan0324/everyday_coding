#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

struct node
{
    node *l_ptr = nullptr, *r_ptr = nullptr;
    ull lazy_tag = 0;
    ull val = 0;
    node(vector<ull> &ori, ull l, ull r)
    {
        if(l + 1 == r)
        {
            val = ori[l];
            return;
        }
        l_ptr = new node(ori, l, (l+r)/2);
        r_ptr = new node(ori, (l+r)/2, r);
        val = l_ptr->val + r_ptr->val;
        return;
    }
    void push(ull l, ull r)
    {
        ull mid = (l+r)/2;
        if(l_ptr != nullptr)
        {
            l_ptr->val += lazy_tag*(mid - l);
            l_ptr->lazy_tag += lazy_tag;
        }
        if(r_ptr != nullptr)
        {
            r_ptr->val += lazy_tag*(r - mid);
            r_ptr->lazy_tag += lazy_tag;
        }
        lazy_tag = 0;
    }
    ull query(ull l, ull r, ull ql, ull qr)
    {
        if(ql <= l && r <= qr)return val;
        push(l, r);
        ull mid = (l+r)/2, ans = 0;
        if(ql < mid)ans += l_ptr->query(l, mid, ql, qr);
        if(mid < qr)ans += r_ptr->query(mid, r, ql, qr);
        return ans;
    }
    void add(ull l, ull r, ull ql, ull qr, ull u)
    {
        if(ql <= l && r <= qr)
        {
            val += u*(r-l);
            lazy_tag += u;
            return;
        }
        push(l, r);
        ull mid = (l+r)/2;
        if(ql < mid)l_ptr->add(l, mid, ql, qr, u);
        if(mid < qr)r_ptr->add(mid, r, ql, qr, u);
        val = l_ptr->val+r_ptr->val;
        return;
    }
};

struct SegTree
{
    vector<ull> inner;
    node *root = nullptr;
    SegTree(vector<ull> &a):inner(a)
    {
        root = new node(inner, 0, inner.size());
    }
    ull query(ull ql, ull qr)
    {
        return root->query(0, inner.size(), ql, qr);
    }
    void add(ull ql, ull qr, ull u)
    {
        root->add(0, inner.size(), ql, qr, u);
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    ull n, q, op, a, b, u;
    cin >> n >> q;
    vector<ull> x(n);
    for(auto &i : x)cin >> i;
    SegTree st(x);
    while(q--)
    {
        cin >> op;
        if(op == 1)
        {
            cin >> a >> b >> u;
            st.add(a-1, b, u);
        }else
        {
            cin >> a;
            cout << st.query(a-1, a) << '\n';
        }
    }
}
