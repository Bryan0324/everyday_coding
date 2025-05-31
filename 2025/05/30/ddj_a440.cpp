#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ssize_t long long
#define size_t unsigned long long

vector<size_t> _tenpow = {1};
size_t tenpow(size_t n)
{
    while (_tenpow.size() <= n)
    {
        _tenpow.push_back(_tenpow.back()*10);
    }
    return _tenpow[n];
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    pair<size_t, size_t> num, ans;
    size_t t;
    bool neg;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        neg = false;
        size_t i = 0;
        num = {0, 0};
        string s, cnt;
        getline(cin, s, ' ');
        getline(cin, cnt, '\n');
        for (; i < s.size() && s[i] != '.'; i++)
        {
            if(s[i] == '-')
            {
                neg = true;
                continue;
            }
            num.first *= 10;
            num.first += s[i]-'0';
        }
        ++i;
        size_t tmp = i;
        for (; i < s.size(); i++)
        {
            if(s[i] == '-')neg = true;
            num.second *= 10;
            num.second += s[i]-'0';
        }
        tmp = i-tmp;
        ans.first = num.second;
        //cerr << tmp;
        ans.second = tenpow(tmp)-tenpow(tmp-cnt.size());
        //cerr << ans.first << ' ' << ans.second;
        ans.first -= (ans.first / tenpow(cnt.size()));
        tmp = __gcd(ans.first, ans.second);
        ans.first /= tmp;
        ans.second /= tmp;
        ans.first += ans.second*num.first;
        if(neg)cout << '-';
        cout << ans.first << " / " << ans.second << '\n';
    }
}