#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s += '0';
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'W')if(s[i+1] != 'A')return false;
    }
    return true;
};
int main()
{
    if(solve())cout << "yes";
    else cout << "no";
}