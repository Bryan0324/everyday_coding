#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
typedef pair<ssize_t, ssize_t> pos;
#define x first
#define y second
template<class T1>
auto muti(T1 a)
{
    return a*a;
}
istream &operator>>(istream &in, pos &b)
{
    in >> b.x >> b.y;
    return in;
}

size_t operator*(const pos &a, const pos &b)
{
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
bool cmp(pos &a, pos &b)
{
    return a.y < b.y;
}
size_t re(vector<pos> &v, size_t l, size_t r)
{
    if(l+2 == r)return v[l]*v[l+1];
    if(l+3 == r)return max(max(v[l]*v[l+1], v[l+1]*v[l+2]), v[l]*v[l+2]);
    size_t mid = (l+r)/2;
    size_t ans = re(v, l, mid);
    ans = min(ans, re(v, mid, r));
    vector<pos> s = {};
    for (size_t i = l; i < r; i++)
    {
        if(muti(abs(v[mid].x - v[i].x)) < ans)s.push_back(v[i]);
    }
    sort(s.begin(), s.end(), cmp);
    for (size_t i = 0; i < s.size(); i++)
    {
        for (size_t j = i+1; j < s.size(); j++)
        {
            if(muti(abs(s[i].y - s[j].y)) >= ans)break;
            ans = min(ans, s[i]*s[j]);
        }
    }
    
    return ans;
}

int main()
{
    size_t n;
    cin >> n;
    vector<pos> v(n);
    for(auto &i : v)cin >> i;
    sort(v.begin(), v.end());
    cout << re(v, 0, n);
}
/* 
4
-4 9
1 3
2 -5
7 5
*/
