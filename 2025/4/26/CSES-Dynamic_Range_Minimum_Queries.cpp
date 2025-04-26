/*
(好久沒刻線段樹了
(提問：為什麼我這題的解答有區間換值和懶標
(答：沒在看題目 >_<
*/
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define long long ssize_t
#define unsigned long long size_t
typedef vector<size_t> vs;
 
struct node
{
    node *l = nullptr, *r = nullptr;
    size_t num = ULLONG_MAX, lt = ULLONG_MAX;
    node(vs::iterator vl, vs::iterator vr)
    {
        if(vl+1 == vr)num = *vl;
        else
        {
            l = new node(vl, vl+(vr-vl)/2);
            r = new node(vl+(vr-vl)/2, vr);
            num = min(l->num, r->num);
        }
    }
    void push_lt()
    {
        if(l != nullptr)
        {
            l->num = min(lt, l->num);
            l->lt = min(lt, l->lt);
        }
        if(r != nullptr)
        {
            r->num = min(lt, r->num);
            r->lt = min(lt, r->lt);
        }
        lt = ULLONG_MAX;
    }
    void update(size_t n, size_t point, size_t vl, size_t vr)
    {
        //cerr << '[' << vl << ',' << vr << ")\n";
        if(vl == point && vl+1 == vr)
        {
            num = n;
            return;
        }
        //push_lt();
        if(point < (vl+vr)/2)l->update(n, point, vl, (vl+vr)/2);
        if((vl+vr)/2 <= point)r->update(n, point, (vl+vr)/2, vr);
        num = min(l->num, r->num);
        return;
    }
    void modify(size_t n, size_t ml, size_t mr, size_t vl, size_t vr)
    {
        if(ml <= vl && vr <= mr)
        {
            lt = min(lt, n);
            num = min(num, lt);
            return;
        }
        push_lt();
        if(ml < (vl+vr)/2)l->modify(n, ml, mr, vl, (vl+vr)/2);
        if((vl+vr)/2 < mr)r->modify(n, ml, mr, (vl+vr)/2, vr);
        num = min(l->num, r->num);
        return;
    }
    size_t query(size_t ql, size_t qr, size_t vl, size_t vr)
    {
        //cerr << '[' << vl << ',' << vr << ")\n";
        if(ql <= vl && vr <= qr)
        {
            return num;
        }
        //push_lt();
        if(ql >= (vl+vr)/2) return r->query(ql, qr, (vl+vr)/2, vr);
        if((vl+vr)/2 >= qr) return l->query(ql, qr, vl, (vl+vr)/2);
        return min(l->query(ql, qr, vl, (vl+vr)/2), r->query(ql, qr, (vl+vr)/2, vr));
    }
};
struct Segtree
{
    vector<size_t> in;
    node *root = nullptr;
    void bulid()
    {
        root = new node(in.begin(), in.end());
        return;
    }
    void modify(size_t n, size_t ml, size_t mr)
    {
        root->modify(n, ml, mr, 0, in.size());
        return;
    }
    size_t query(size_t ql, size_t qr)
    {
        return root->query(ql, qr, 0, in.size());
    }
    void update(size_t n, size_t point)
    {
        root->update(n, point, 0, in.size());
        return;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    size_t n, q, t, k, u;
    cin >> n >> q;
    Segtree st;
    st.in = vector<size_t>(n);
    for(auto &i : st.in)cin >> i;
    st.bulid();
    while(q--)
    {
        cin >> t >> k >> u;
        if(t == 1)
        {
            st.update(u, k-1);
        }else 
        {
            cout << st.query(k-1, u) << '\n';
        }
    }
}
