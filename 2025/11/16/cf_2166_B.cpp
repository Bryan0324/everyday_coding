//https://codeforces.com/contest/2166/problem/B
#include<bits/stdc++.h>
using namespace std;
 
using ull = unsigned long long;
using ll = long long;

struct Div
{
	ull top, bottom;
	Div(ull _top, ull _bottom): top(_top), bottom(_bottom) 
	{
		ull g = __gcd(top, bottom);
		top /= g;
		bottom /= g;
	}
	bool operator<=(const Div &b)
	{
		return top*b.bottom <= b.top*bottom;
	}
	bool operator==(const Div &b)
	{
		return top == b.top && bottom == b.bottom;
	}
};


void solve()
{
	int a, b, n;
	cin >> a >> b >> n;
	if(Div(b, 1) <= Div(a, n) || b == a)cout << 1 << '\n';
	else cout << 2 << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
 
    int t;
    cin >> t;
    while(t--)solve();
}