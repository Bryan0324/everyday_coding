#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
typedef pair<size_t, size_t> pos;
#define x first
#define y second
const int MOD = 1e7+19;
void cnt(vector<size_t>::iterator vl, vector<size_t>::iterator vr, size_t &sum)
{
    if(vl+1 == vr)return;
    vector<size_t>::iterator mid = vl + (vr-vl)/2;
    cnt(vl, mid, sum);
    cnt(mid, vr, sum);
    vector<size_t> tmp(vl, vr);
    size_t c = 0;
    for (size_t i = 0, j = tmp.size()/2, k = 0; k < tmp.size();k++)
    {
        if(i == tmp.size()/2) *(vl+k) = tmp[j++];
        else if(j == tmp.size())
        {
            sum += (tmp[i]%MOD *c%MOD)%MOD;
            sum %= MOD;
            *(vl+k) = tmp[i++];
        }
        else if(tmp[i] <= tmp[j])
        {
            sum += (tmp[i]%MOD *c%MOD)%MOD;
            sum %= MOD;
            *(vl+k) = tmp[i++];
        }
        else
        {
            *(vl+k) = tmp[j];
            sum += (tmp[j]%MOD*(tmp.size()/2-i)) %MOD;
            sum %= MOD;
            j++;
            c++;
        }
    }
}

int main()
{
    size_t n;
    cin >> n;
    vector<size_t> v(n);
    for(auto &i : v)cin >> i;
    size_t ans = 0;
    cnt(v.begin(), v.end(), ans);
    cout << ans;
}
