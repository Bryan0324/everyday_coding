//https://codeforces.com/contest/2169/problem/B
#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

typedef pair<int, int> tl;
#define val first
#define p second
int solve()
{
   string s;
   cin >> s;
   if(s.size() == 1)return 1;
   for(int i = 0; i < s.size()-1; i++)
   {
        if(s[i] == '>' && '<' == s[i+1])return -1;
        if(s[i] == '*' && '<' == s[i+1])return -1;
        if(s[i] == '>' && '*' == s[i+1])return -1;
        if(s[i] == '*' && '*' == s[i+1])return -1;
   }
   int l = 0, r = 0;
   for(int i = 0; i < s.size(); i++)
   {
        if(s[i] == '>')break;
        l++;
   }
   for(int i = s.size()-1; i >= 0; i--)
   {
        if(s[i] == '<')break;
        r++;
   }
   return max(l, r);
}
/* 
*>
>< ---> -1
*< >* ---> -1
*/
int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--)cout << solve() << '\n';
}