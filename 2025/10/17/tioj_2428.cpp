#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, c;
    cin >> n >> c;
    string tmp;
    unordered_map<int, int> horse_t;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        int t = 0;
        for (int i = tmp.size()-1; i >= 0; i--)
        {
            if(tmp[i] == '1')t += (1 << (tmp.size()-i-1));
        }
        horse_t[t]++;
        cout << horse_t.size() << ' ' << horse_t[t] << '\n';
    }
    
}