#include<bits/stdc++.h>
using namespace std;

double eps = 1e-10;

struct double_fixed
{
    double _in;
    double_fixed(double a = 0):_in(a) {};
    bool operator==(double_fixed a)
    {
        return abs(_in - a._in) < eps;
    };
    double_fixed operator+(const double_fixed a)
    {
        return double_fixed(_in + a._in);
    };
};

istream &operator>>(istream &in, double_fixed &a)
{
    in >> a._in;
    return in;
};
int main()
{
    size_t n, ans = 0;
    cin >> n;
    vector<double_fixed> v(n);

    for(auto &i : v)cin >> i;
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            for(size_t k = 0; k < n; k++)
            {
                if(v[i]+v[j] == v[k])ans++;
            }
        }
    }
    cout << ans;
}
