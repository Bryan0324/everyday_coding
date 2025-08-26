#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
#pragma GCC optimize("O3")

using ll = long long;
using ull = unsigned long long;

const int n = 8, P_END = n*n;
vector<bool> dag(n*2, true);
vector<bool> disdag(n*2, true);
vector<bool> x(n, true);
vector<bool> y(n, true);
vector<vector<char>> graph(n, vector<char>(n));

void print(int a, int b)
{
    for(int i = a; i <= b; i++)cout << i << ' ';
    return;
}

bool solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    if(a == 0 && b == 0)
    {
        cout << "YES\n";
        print(1, n);
        cout << '\n';
        print(1, n);
        cout << '\n';
        return true;
    }else if(a == 0 || b == 0 || a+b > n)return false;
    cout << "YES\n";
    print(1, n);
    cout << '\n';

    int top = n-a-b;
    print(1, top);
    top++;
    print(top+a, n);
    print(top, top+a-1);
    cout << '\n';
    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)if(!solve())cout << "NO\n";
}
/* 
1 2 3 4 5
3 4 5 1 2
*/