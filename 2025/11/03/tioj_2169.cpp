#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;



int main()
{
	cin.tie(0)->sync_with_stdio(false);
	
    int n, k;
    cin >> n >> k;
    for(int m = 2; m <= 30000; m++)
    {
        int idx = 0;
        for(int i = 2; i <= n; i++)
        {
            idx = (idx + m)%i;
        }
        if(idx+1 == k)
        {
            cout << m;
            return 0;
        }
    }
    cout << 0;
}

/* 
(n + k)


1 2 3
*/

 