#include <bits/stdc++.h>
#include "lib0117.h"
using namespace std;
#pragma GCC optimize("O3")
typedef pair<size_t, size_t> pos;
#define ff first
#define ss second
void re(vector<vector<size_t>> &v, pos np, size_t size, size_t offset)
{
    if(size == 2)
    {
        v[np.ff][np.ss] = 3+offset;
        v[np.ff][np.ss+1] = 2+offset;
        v[np.ff+1][np.ss] = 1+offset;
        v[np.ff+1][np.ss+1] = 3+offset;
        return;
    }
    re(v, np, size/2, offset);
    re(v, {np.ff, np.ss+size/2}, size/2, offset+size);
    re(v, {np.ff+size/2, np.ss}, size/2, offset+size);
    re(v, {np.ff+size/2, np.ss+size/2}, size/2, offset);
    pos tmp = {np.ff+size/2, np.ss};
    for (size_t i = 0; i < size/2; i++)
    {
        v[tmp.ff+i][tmp.ss+i] -= 3;
    }
    return;
}
void solve(int N)
{
    vector<vector<size_t>> v(N, vector<size_t>(N));
    re(v, {0, 0}, N, 0);
    for(auto &i : v)
    {
        for(auto &j : i)Report(j);
    }
}


/* 
4
-4 9
1 3
2 -5
7 5
*/

/* 
7 4 3
6 5 2 1

3 2 3 2 
1 3 1 3
3 2 3 2 
1 3 1 3

3 2 7 6 3 2 7 6 
1 3 5 7 1 3 5 7 
4 6 3 2 4 6 3 2 
5 4 1 3 5 4 1 3 
3 2 7 6 3 2 7 6 
1 3 5 7 1 3 5 7 
4 6 3 2 4 6 3 2 
5 4 1 3 5 4 1 3 
*/
