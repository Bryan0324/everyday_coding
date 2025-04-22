#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define x first
#define y second
typedef pair<ssize_t, ssize_t> pos;
 
char &at(vector<vector<char>> &space, pos a)
{
    if(a.x < 0 || a.x >= space.size() || a.y < 0 || a.y >= space[0].size())return *(new char('#'));
    return space[a.x][a.y];
}
 
 
istream &operator>>(istream &in, pos a)
{
    in >> a.x >> a.y;
    return in;
}
 
int main()
{
	size_t n , m;
    cin.tie(0)->sync_with_stdio(false);
	cin >> n >> m;
	vector<vector<char>> space(n, vector(m, '\a'));
 
    queue<pos> q;
    pos start, end;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cin >> space[i][j];
            if(space[i][j] == 'A')start = {i, j};
            if(space[i][j] == 'B')end = {i, j};
        }
    }
    q.push(start);
    space[start.x][start.y] = '.';
    space[end.x][end.y] = '.';
    while(q.size() != 0)
    {
        auto now = q.front();
        if(now == end)break;
 
        if(at(space, {now.x+1, now.y}) == '.')
        {
            at(space, {now.x+1, now.y}) = 'D';
            q.push( {now.x+1, now.y} );
        }
 
        if(at(space, {now.x-1, now.y}) == '.')
        {
            at(space, {now.x-1, now.y}) = 'U';
            q.push( {now.x-1, now.y} );
        }
 
        if(at(space, {now.x, now.y+1}) == '.')
        {
            at(space, {now.x, now.y+1}) = 'R';
            q.push( {now.x, now.y+1} );
        }
 
        if(at(space, {now.x, now.y-1}) == '.')
        {
            at(space, {now.x, now.y-1}) = 'L';
            q.push( {now.x, now.y-1} );
        }
        q.pop();
    }
    if(q.size() == 0)cout << "NO";
    else
    {
        cout << "YES\n";
        string s;
        while(end != start)
        {
            s.push_back(space[end.x][end.y]);
            switch (space[end.x][end.y])
            {
            case 'L':
                end = {end.x, end.y+1};
                break;
            case 'R':
                end = {end.x, end.y-1};
                break;
            case 'U':
                end = {end.x+1, end.y};
                break;
            case 'D':
                end = {end.x-1, end.y};
                break;
            }
        }
        reverse(s.begin(), s.end());
        cout << s.size() << '\n';
        cout << s;
    }
}
/* 
 
*/
