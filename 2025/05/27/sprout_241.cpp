#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ssize_t long long
#define size_t unsigned long long

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    string s;
    cin >> s;
    size_t size = 1, ptr = 0;
    for(size_t i = 0; i < s.size(); i++)
    {
        if(s[ptr] != s[i])
        {
            size = i+1;
            ptr = i;
        }
        if(++ptr == size)ptr = 0;
    }
    if(s.size()%size == 0)cout << size;
    else cout << s.size();
}