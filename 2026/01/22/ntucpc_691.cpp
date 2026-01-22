#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

struct Pos
{
    int x = 0, y = 0, n = 0;
    Pos(int _x, int _y, int _n): x(_x), y(_y), n(_n) {};
    void operator++(int a)
    {
        y++;
        if(y == n)
        {
            y = 0;
            x++;
        }
    }
};

struct checker: vector<vector<bool>>
{
    int n;
    checker(int _n): n(_n)
    {
        this->resize(3);
        (*this)[0].resize(n);
        (*this)[1].resize(n*2);
        (*this)[2].resize(n*2);
    }
    bool check(const Pos a)
    {
        return (*this)[0][a.y] || (*this)[1][a.x+a.y] || (*this)[2][n+a.x-a.y];
    }
    void modify(const Pos a, bool v)
    {
        (*this)[0][a.y] = (*this)[1][a.x+a.y] = (*this)[2][n+a.x-a.y] = v;
    }
};

void dfs(int left, checker &c, vector<string> &board, Pos now)
{
    if(left == 0)
    {
        for(auto &i : board)cout << i << '\n';
        cout << '\n';
        return;
    }
    if(now.x == board.size())return;
    for(now.y = 0; now.y < board.size(); now.y++)
    {
        if(!c.check(now))
        {
            c.modify(now, true);
            board[now.x][now.y] = 'Q';
            dfs(left-1, c, board, {now.x+1, 0, (int)board.size()});
            board[now.x][now.y] = '*';
            c.modify(now, false);
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> board(n, string(n, '*'));
    checker c(n);
    dfs(n, c, board, {0, 0, n});
}

