#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ssize_t long long
#define size_t unsigned long long

#define weight first
#define to second.second
#define from second.first
typedef pair<size_t, pair<size_t, size_t>> edge;

bool solve()
{
    string cmp, s;
    cin >> cmp >> s;
    size_t ptr = 0;
    for(auto &i : s)
    {
        if(i == cmp[ptr])if(++ptr == cmp.size())return true;
    }
    return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    size_t t;
    cin >> t;
    while(t--)
    {
        if(solve())cout << "Yes\n";
        else cout << "No\n";
    }
}