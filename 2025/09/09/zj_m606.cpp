#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;

typedef pair<int, int> Pos;
#define x first
#define y second

Pos operator-(Pos a, Pos b)
{
    return {a.x-b.x, a.y-b.y};
}
int operator^(Pos a, Pos b)
{
    return a.x*b.y - a.y*b.x;
}
int triangle_area(Pos p, Pos a, Pos b)
{
    return (a - p) ^ (b - p);
}


void solve()
{
    cin.tie(0)->sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<Pos> p(n);
    for(auto &i : p)cin >> i.x >> i.y;
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            vector<char> ans(n, 'B');
            ans[i] = ans[j] = 'A';
            for (int k = j+1; k < n; k++)
            {
                if(triangle_area(p[i], p[j], p[k]) == 0)ans[k] = 'A';
            }
            vector<int> hull;
            for(int k = 0; k < n; k++)
            {
                if(ans[k] == 'A')continue;

                if(hull.size() < 2)hull.push_back(k);
                else
                {
                    if(triangle_area(p[hull[0]], p[hull[1]], p[k]) != 0)
                    {
                        ans[0] = '\\';
                    }
                }
            }
            if(ans[0] != '\\')
            {
                for(auto &i : ans)cout << i << '\n';
                return;
            }
        }
    }
    for(int j = 0; j < n; j++)
    {
        vector<char> ans(n, 'B');
        ans[j] = 'A';
        vector<int> hull;
        for(int k = 0; k < n; k++)
        {
            if(ans[k] == 'A')continue;

            if(hull.size() < 2)hull.push_back(k);
            else
            {
                if(triangle_area(p[hull[0]], p[hull[1]], p[k]) != 0)
                {
                    ans[0] = '\\';
                }
            }
        }
        if(ans[0] != '\\')
        {
            for(auto &i : ans)cout << i << '\n';
            return;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    solve();

}