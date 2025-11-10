#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

typedef pair<int, int> Pos;
#define x first
#define y second
Pos operator+(Pos &a, Pos &b)
{
    return {a.x+b.x, a.y+b.y};
}


vector<pair<char, Pos>> faces = {
    {'R', {0, 1}},
    {'D', {1, 0}},
    {'L', {0, -1}},
    {'U', {-1, 0}},
};
struct Value
{
    int now, lim;
    Value(int _lim = 0): now(_lim), lim(_lim) {};
    bool modify(int d)
    {
        now += d;
        now = min(now, lim);
        if(now > 0)return true;
        now = 0;
        return false;
    }
    bool to_zero()
    {
        return now <= 0;
    }
};

struct Player
{
    int facing = 1;
    Pos standing = {0, 0};
    Value hp, st, vc, sa;
    Player(int _hp, int _st, int _vc, int _sa): hp(_hp), st(_st), vc(_vc), sa(_sa) {};
    void turn(int d)
    {
        facing += 4+d;
        facing %= 4;
    }
    char toward()
    {
        return faces[facing].first;
    }
    Pos next()
    {
        return standing + faces[facing].second;
    }
    void move()
    {
        standing = standing + faces[facing].second;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    int N, M, _hp, _st, _vc, _sa;
    cin >> N >> M >> _hp >> _st >> _vc >> _sa;
    int t, m, h, n, p, f, wi, wo, si, so, s, v, K;
    cin >> t >> m >> h >> n >> p >> f >> wi >> wo >> si >> so >> s >> v;
    vector<string> graph(N);
    Player player(_hp, _st, _vc, _sa);
    for(auto &i : graph)cin >> i;
    bool fighting = false, drowning = false, starving = false;
    
    cin >> K;
    string ops;
    cin >> ops;
    for(auto &op : ops)
    {
        if(op == 'R')player.turn(1);
        else if(op == 'L')player.turn(-1);
        else
        {
            switch (graph[player.next().x][player.next().y])
            {
            case 'T':
                if(player.st.now >= t)
                {
                    player.move();
                    player.st.modify(-t);
                }
                break;
            case 'M':
                if(player.st.now >= m)
                {
                    player.move();
                    player.st.modify(-m);
                }else 
                {
                    player.hp.modify(-h);
                    fighting = true;
                }
                break;
            case 'N':
                player.move();
                player.hp.modify(n);
                break;
            case 'P':
                player.move();
                player.st.modify(p);
                break;
            case 'F':
                player.move();
                player.sa.modify(f);
                break;
            default:
                player.move();
                break;
            }
        }
        if(graph[player.standing.x][player.standing.y] != 'W')
        {
            graph[player.standing.x][player.standing.y] = '_';
            player.vc.modify(wo);
            player.sa.modify(-so);
        }else 
        {
            player.vc.modify(-wi);
            player.sa.modify(-si);
        }
        if(player.vc.now == 0)
        {
            player.hp.modify(-v);
            drowning = player.hp.now == 0;
        }
        if(player.sa.now == 0)
        {
            player.hp.modify(-s);
            starving = player.hp.now == 0;
        }

        cout << "pos: (" << player.standing.x << ", " << player.standing.y << "), ";
        cout << "HP: " << player.hp.now << ", ";
        cout << "ST: " << player.st.now << ", ";
        cout << "VC: " << player.vc.now << ", ";
        cout << "SA: " << player.sa.now << ", ";
        cout << "Face: " << player.toward() << '\n';

        vector<string> ret;
        if(fighting && player.hp.to_zero())ret.push_back(" fighting");
        if(drowning)ret.push_back(" drowning");
        if(starving)ret.push_back(" starving");
        fighting = false;
        if(ret.size() == 0)continue;
        cout << "Died from";
        for(int i = 0; i < ret.size(); i++)
        {
            cout << ret[i];
            if(i != ret.size()-1)cout << " and";
        }
        return 0;
    }
    return 0;
}