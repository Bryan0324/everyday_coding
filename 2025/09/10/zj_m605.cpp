#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;


int main()
{
    cin.tie(0)->sync_with_stdio(false);

    ull n;
    cin >> n;
    vector<ull> primes = {2, 3};
    vector<ull> is_prime(n+2);
    is_prime[2] = 2;
    is_prime[3] = 3;
    is_prime[4] = 2;
    ull ptr = 1;
    while(primes[ptr-1]*primes[ptr-1] <= n)
    {
        ull begin = primes[ptr-1]*primes[ptr-1], end = primes[ptr]*primes[ptr];
        for (ull pi = 0; pi <= ptr; pi++)
        {
            auto &p = primes[pi];
            for(ull i = begin/p+1; i*p <= min(end, n); i++)
            {
                is_prime[i*p] = p;
            }
        }
        for(ull i = begin+1; i <= min(end, n); i++)
        {
            if(is_prime[i] == 0)
            {
                is_prime[i] = i;
                primes.push_back(i);
            }
        }
        ptr++;
    }
    vector<ull> ans(n+2);
    ull farthest = 0;
    for(ull i = 1; i <= n; i++)
    {
        for(ull j = i; j != 1; j /= is_prime[j])
        {
            ans[is_prime[j]]++;
            farthest = max(farthest, is_prime[j]);
        }
    }
    ull cnt = 0;
    for(ull i = 0; primes[i] < farthest; i++)
    {
        if(ans[primes[i]] == ans[primes[i + 1]])cnt++;
        else 
        {
            if(cnt == 0)cout << ans[primes[i]] << ' ';
            else cout << cnt+1 << '*' << ans[primes[i]] << ' ';
            cnt = 0;
        }
    }
    if(cnt == 0)cout << ans[farthest] << ' ';
    else cout << cnt+1 << '*' << ans[farthest] << ' ';
     
}