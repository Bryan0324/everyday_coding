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

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> ans(n);
    vector<Pos> point(n);
    for(auto &i : point)cin >> i.x >> i.y;
    for(int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                if(triangle_area(point[i], point[j], point[k]) != 0)
                {
                    ans[i]++; ans[j]++; ans[k]++;
                }
            }
        }
    }
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        if(ans[m] < ans[i])m = i;
    }
    if(ans[m] == 0)cout << "-1 -1";
    else cout << point[m].x << ' ' << point[m].y;
}