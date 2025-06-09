#include<bits/stdc++.h>
using namespace std;

long double eps = 1e-20;


struct point : pair<long long, long long>
{
    long long &x = first;
    long long &y = second;
    point(long long a = 0, long long b = 0)
    {
        x = a;
        y = b;
    };
    long long operator()()
    {
        return x*x+y*y;
    }
    long long operator|(const point b)
    {
        return (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y);
    }
};
int main()
{
    size_t n, ans = 0;
    unordered_map<long long, size_t> lens;
    cin >> n;
    vector<point> p(n);
    for(auto &i : p)cin >> i.x >> i.y;
    for(size_t i = 0; i < n-1; i++)
    {
        for(size_t j = i+1; j < n; j++)
        {
            long long l = p[i]|p[j];
            ans += lens[l];
            lens[l]++;
        }
    }
    cout << ans;
}
