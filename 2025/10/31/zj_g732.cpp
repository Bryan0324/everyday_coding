#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, s;
    int cnt[501] = {};
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        cnt[s]++;
    }
    for(int i = 1, c = 0; i <= 500; i++)
    {
        c += cnt[i];
        if(c > n/2)
        {
            cout << i;
            break;
        }
    }
}