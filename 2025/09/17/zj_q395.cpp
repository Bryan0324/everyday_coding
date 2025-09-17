#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(auto &i : a)cin >> i;
    for(auto &i : b)cin >> i;

    int cnt_b = 0, ptr = 0;
    for(auto &i : b)
    {
        if(ptr == n)break;
        if(a[ptr] <= i)
        {
            ptr++;
            cnt_b++;
        }
    }
    int cnt_a = 0;
    ptr = 0;
    for(auto &i : a)
    {
        if(ptr == n)break;
        if(b[ptr] <= i)
        {
            ptr++;
            cnt_a++;
        }
    }
    if(cnt_a > n/2 && cnt_b > n/2)cout << "X";
    else if(cnt_a > n/2)cout << "A";
    else cout << "B";
}