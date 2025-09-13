#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
typedef pair<int, int> Pos;
#define x first
#define y second
ull solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> m(n+2);
    vector<int> a(n);
    for(auto &i : a)
    {
        cin >> i;
        m[i]++;
    }
    for(auto &i : m)
    {
        if(i % k != 0)return 0;
        i /= k;
    }
    a.push_back(n+1);
    ull ans = 0;
    for(int i = 0; i <= n; i++)
    {
        for(int front = i; i <= n; i++)
        {
            if(m[a[i]] == 0)
            {
                if(a[i] == a[front])
                {
                    front++;
                }else
                {
                    for(; front < i; front++)
                    {
                        if(a[front] == a[i])break;
                        m[a[front]]++;
                    }
                    if(front == i)break;
                    front++;
                }
            }else m[a[i]]--;
            ans += i-front+1;
        }
    }
    return ans;
}
 
 
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)
    {
        cout << solve() << '\n';
    }
}