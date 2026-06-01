#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> task;
#define dl first
#define c second

bool checker(vector<task> &tasks, ll f)
{
    
    ll time = 0;
    for(auto &i : tasks)
    {
        time += i.c;
        if((__int128)i.dl*f < time)return false;
    }
    return true;
};
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<task> tasks(n);
    for(auto &i : tasks)
    {
        cin >> i.dl >> i.c;
    }
    sort(tasks.begin(), tasks.end());
    ll l = 1, r = 1e15;
    while(r>l){
        ll mid = (l + r) >> 1;
        if(checker(tasks, mid)) r = mid;
        else l = mid+1;
    }
    cout << r << '\n';
}