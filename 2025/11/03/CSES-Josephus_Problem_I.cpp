#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;



int main()
{
	cin.tie(0)->sync_with_stdio(false);
	
    int n, m = 2;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)v[i] = (i+1)%n;
    int idx = 0;
    for(int i = 0; i < n; i++)
    {
        cout << v[idx]+1 << ' ';
        v[idx] = v[v[idx]];
        idx = v[idx];
    }
    
}

/* 
(n + k)


1 2 3
*/

 