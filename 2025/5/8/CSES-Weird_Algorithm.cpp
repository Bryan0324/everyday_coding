#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define ssize_t long long 
#define size_t unsigned long long
 
 
int main()
{
	cin.tie(0)->sync_with_stdio(false);
	size_t n;
	cin >> n;
	cout << n;
	while(n != 1)
	{
		if((n & 1) == 0)n/=2;
		else n = n*3 + 1;
		cout << ' ' << n;
	}
	
 
}
