#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ALL(x) x.begin(),x.end()
#define SIZE(x) (signed)(x.size())

const int MN = 2e5 + 5;

const int MOD = 1e9 + 7;

struct fenw{int t[MN];
    void init(){for(int i = 0; i < MN; i++) t[i] = 0;}

void u(int i, int val){
    for(i; i < MN ; i+=(i & -i)) t[i] = (t[i] + val)%MOD;
}

int q(int i){
    int ret = 0;
    for(i; i > 0; i -= (i & -i)) ret = (ret + t[i])%MOD;
    return ret;
}}bit[2];

int brute(vector<int> v){
    int n;
    //cin >> n;
    n = SIZE(v);
    int ans = 0;
    for(int i = 0; i < (1 << n); i++){
        bitset<10> b = i;
        vector<int> a;
        for(int j = 0; j < n; j++){
            if(b[j]) a.push_back(v[j]);
        }
        if(i == 0) continue;
        bool ok = 1;
        if(SIZE(a) == 1){
            ans++;
            continue;
        }
        bool up = (a[0] < a[1]);
        if(a[0] == a[1]) continue;
        for(int i = 2; i < SIZE(a); i++){
            up ^= 1;
            if(up && a[i - 1] >= a[i]) ok = 0;
            if(!up && a[i - 1] <= a[i]) ok = 0;
        }
        ans += ok;
    }
    return ans;
}

void sol(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &it : v) cin >> it;
    //n = (signed)(v.size());
    vector<int> lisan;
    lisan = v;
    sort(ALL(lisan));
    lisan.resize(unique(ALL(lisan)) - lisan.begin());
    for(int i = 0; i < n; i++){
        v[i] = (lower_bound(ALL(lisan), v[i]) - lisan.begin()) + 1;
    }
    vector<vector<int>> dp(n, vector<int>(2, 1));
    dp[0][0] = dp[0][1] = 1;
    bit[0].u(v[0], 1), bit[1].u(v[0], 1);
    for(int i = 1; i < n; i++){
        dp[i][1] = (dp[i][1] + bit[0].q(MN - 1) - bit[0].q(v[i]) + MOD)%MOD;
        dp[i][0] = (dp[i][0] + bit[1].q(v[i] - 1) + MOD)%MOD;
        //cout << dp[i][0] << ' ' << dp[i][1] << '\n';
        bit[0].u(v[i], dp[i][0]), bit[1].u(v[i], dp[i][1]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = (ans + dp[i][0] + dp[i][1] + MOD - 1)%MOD;
    }
    cout << ans << '\n';
    //return ans;
}

int soll(vector<int> v){
    int n;
    //cin >> n;
    //vector<int> v(n);
    //for(int &it : v) cin >> it;
    bit[0].init(), bit[1].init();
    n = (signed)(v.size());
    vector<int> lisan;
    lisan = v;
    sort(ALL(lisan));
    lisan.resize(unique(ALL(lisan)) - lisan.begin());
    for(int i = 0; i < n; i++){
        v[i] = (lower_bound(ALL(lisan), v[i]) - lisan.begin()) + 1;
    }
    vector<vector<int>> dp(n, vector<int>(2, 1));
    dp[0][0] = dp[0][1] = 1;
    bit[0].u(v[0], 1), bit[1].u(v[0], 1);
    for(int i = 1; i < n; i++){
        dp[i][1] = (dp[i][1] + bit[0].q(MN - 1) - bit[0].q(v[i]) + MOD)%MOD;
        dp[i][0] = (dp[i][0] + bit[1].q(v[i] - 1))%MOD;
        //cout << dp[i][0] << ' ' << dp[i][1] << '\n';
        bit[0].u(v[i], dp[i][0]), bit[1].u(v[i], dp[i][1]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = (ans + dp[i][0] + dp[i][1] + MOD - 1)%MOD;
    }
    //cout << ans << '\n';
    return ans;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    //srand(time(0));
    /*while(1){
        int n = rand()%15 + 1;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            v[i] = rand()%((signed)(10)) + 1;
        }
        if(soll(v) != brute(v)){
            cout << n << '\n';
            for(int it : v) cout << it << ' ';
            cout << '\n';
            cout << soll(v) << '\n' << brute(v) << '\n';
            break;
        }
    }*/
   sol();
}