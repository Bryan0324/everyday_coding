#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;


const ull MOD = 1e9+7;

class fac: vector<ull>
{
    public:
        fac()
        {
            this->resize(1);
            this->at(0) = 1;
        }
        ull operator[](int a)
        {
            while(this->size() <= a)this->push_back(this->back()*this->size() % MOD);
            return this->at(a);
        }
};

ull power(ull a, ull b)
{
    ull ans = 1;
    while(b != 0)
    {
        if(b & 1)
        {
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        a %= MOD;
        b >>= 1;
    }
    return ans;
}

ull rev(int x)
{
    return power(x, MOD-2);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    int a, b;
    fac f;
    while(n--)
    {
        cin >> a >> b;
        cout << f[a]*rev(f[b]*f[a-b] %MOD) %MOD << '\n';
    }
}