#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ALL(x) x.begin(), x.end()
#define SIZE(x) (signed)x.size()

const int MN = 1e5 + 5;
const int MOD = 1e9 + 7;

vector<vector<int>> times(vector<vector<int>> &a, vector<vector<int>> &b){
    vector<vector<int>> ret(SIZE(a), vector<int>(SIZE(b[0]), 0));
    for(int i = 0; i < SIZE(a); i++) for(int j = 0; j < SIZE(a[0]); j++) for(int k = 0; k < SIZE(b[0]); k++){
        ret[i][k] = (ret[i][k] + a[i][j] * b[j][k]%MOD);
        if(ret[i][k] >= MOD) ret[i][k] -= MOD;
    }
    return ret;
}

void solve(){
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> now(1, vector<int>(2));
    now[0] = {1, 0};
    vector<vector<int>> tmp(2, vector<int>(2, 1));
    vector<vector<vector<int>>> tt(50);
    tt[0] = tmp;
    for(int i = 1; i < 50; i++) tt[i] = times(tt[i - 1], tt[i - 1]);
    /*for(int i = 1; i <= n; i++){
        now = times(now, tmp);
        cout << now[0][0] << ' ' << now[0][1] << '\n';
    }*/
    vector<array<int,2>> oper(m + 1);
    oper[0] = {0, 0};
    for(int i = 1; i <= m; i++) cin >> oper[i][0] >> oper[i][1];
    sort(ALL(oper));
    for(int i = 1; i <= m; i++){
        int len = oper[i][0] - oper[i - 1][0] - 1;
        bitset<50> bit = len;
        //auto tt = tmp;
        for(int j = 0; j < 50; j++){
            if(bit[j]){
                now = times(now, tt[j]);
            }
            //tt = times(tt, tt);
        }
        //cout << len << '\n';
        //cout << now[0][0] << ' ' << now[0][1] << '\n';
        if(oper[i][1] == -1) now[0] = {now[0][1], 0ll};
        else now[0] = {0ll, now[0][0]};
        //cout << now[0][0] << ' ' << now[0][1] << '\n';
    }
    int len = n - oper.back()[0];
    bitset<50> bit = len;
        //auto tt = tmp;
        for(int j = 0; j < 50; j++){
            if(bit[j]){
                now = times(now, tt[j]);
            }
           //tt = times(tt, tt);
        }
    cout << (now[0][0] + now[0][1])%MOD;
}
signed main(){
    solve();
}