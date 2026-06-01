#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ALL(x) x.begin(), x.end()
#define SIZE(x) (signed)x.size()
const int MN = 1e5 + 5;
struct fenw{int t[MN];
    void init(){for(int i = 0; i < MN; i++) t[i] = 0;}

void u(int i, int val){
    for(i; i < MN ; i+=(i & -i)) t[i] = (t[i] + val);
}

int q(int i){
    int ret = 0;
    for(i; i > 0; i -= (i & -i)) ret = (ret + t[i]);
    return ret;
}}bit;

void solve(){
    int n,q,t;cin>>n>>q>>t;
    vector<array<int,2>> worker;
    vector<int> lisan;
    for(int i = 0; i < n; i++){
        int l, r;cin >> l >> r;
        if(r - l >= t) worker.push_back({l, r}), lisan.push_back(l), lisan.push_back(r);
    }
    sort(ALL(worker));
    vector<array<int,4>> qe;
    vector<bool> ans(q, 0);
    for(int i = 0; i < q; i++){
        int l, r, x;cin >> l >> r >> x;
        if(r - l +1< t) continue;
        int A=r-t+1,B=l+t-1;
        qe.push_back({A, B, x, i});
        lisan.push_back(A), lisan.push_back(B);
    }
    sort(ALL(lisan));
    lisan.resize(unique(ALL(lisan)) - lisan.begin());
    for(int i = 0; i < SIZE(worker); i++){
        worker[i][0] = (lower_bound(ALL(lisan), worker[i][0]) - lisan.begin()) + 1;
        worker[i][1] = (lower_bound(ALL(lisan), worker[i][1]) - lisan.begin()) + 1;
    }
    sort(ALL(qe));
    for(int i = 0; i < SIZE(qe); i++){
        qe[i][0] = (lower_bound(ALL(lisan), qe[i][0]) - lisan.begin()) + 1;
        qe[i][1] = (lower_bound(ALL(lisan), qe[i][1]) - lisan.begin()) + 1;
    }
    int ptr = 0;
    for(auto [r, l, x, i] : qe){
        while(ptr < n && worker[ptr][0] <= (lower_bound(ALL(lisan), r - t) - lisan.begin()) + 1){
            cout << "push " << worker[ptr][1] << '\n';
            bit.u(worker[ptr][1], 1);
            ptr++;
        }
        //cout << bit.q(MN - 1) - bit.q(lower_bound(ALL(lisan), l + t - 1) - lisan.begin()) << ' ' << i << '\n';
        //cout << lower_bound(ALL(lisan), l + t - 1) - lisan.begin() << '\n';
        ans[i] = (bit.q(MN - 1) - bit.q(lower_bound(ALL(lisan), l + t - 1) - lisan.begin()) >= x);
    }
    for(int i = 0; i < q; i++) cout << (ans[i] ? "Yes\n" : "No\n");
}
signed main(){
    solve();
}