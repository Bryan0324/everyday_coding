#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ssize_t long long
#define size_t unsigned long long

#define weight first
#define to second.second
#define from second.first
typedef pair<size_t, pair<size_t, size_t>> edge;

size_t ans = 0;

void merge_sort(vector<size_t>::iterator a, vector<size_t>::iterator b)
{
    if(b-a <= 1)return;
    auto mid = a+(b-a)/2;
    merge_sort(a, mid);
    merge_sort(mid, b);
    vector<size_t> ab(a, b);
    pair<size_t, size_t> p = {0, mid-a};
    auto ptr = a;
    while(p.first != mid-a && p.second != ab.size())
    {
        if(ab[p.first] > ab[p.second])
        {
            ans += mid-a-p.first;
            *ptr = ab[p.second];
            ++p.second;
            ++ptr;
        }else
        {
            *ptr = ab[p.first];
            ++p.first;
            ++ptr;
        }
    }
    while(p.first != mid-a)
    {
        *ptr = ab[p.first];
        ++p.first;
        ++ptr;
    }
    while(p.second != ab.size())
    {
        *ptr = ab[p.second];
        ++p.second;
        ++ptr;
    }
    return;
}
vector<size_t> A((int)1e6);
void solve()
{
    size_t n;
    cin >> n;
    for(size_t i = 0; i < n; i++)cin >> A[i];
    ans = 0;
    merge_sort(A.begin(), A.begin()+n);
    cout << ans << '\n';
    return;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    size_t t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}