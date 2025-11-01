#include <bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
using ll = long long;
 
typedef pair<int, int> tl;
#define day first
#define idx second

int main()
{
    
    cin.tie(0)->sync_with_stdio(false);
 
    int n, a, b;
    cin >> n;
    vector<tl> timelime(n*2);
    vector<int> user(n);
    for (int i = 0; i < n*2; i += 2)
    {
        cin >> a >> b;
        timelime[i] = {a, -(i/2 + 1)};
        timelime[i+1] = {b, (i/2 + 1)};
    }
    int room = 0;
    unordered_set<int> empty;
    sort(timelime.begin(), timelime.end());

    for(auto &i : timelime)
    {
        if(i.idx > 0)empty.insert(user[i.idx - 1]);
        else 
        {
            if(empty.empty())user[-i.idx - 1] = ++room;
            else
            {
                user[-i.idx - 1] = *empty.begin();
                empty.erase(empty.begin());
            }
        }
    }
    cout << room << '\n';
    for(auto &i : user)cout << i << ' ';
}