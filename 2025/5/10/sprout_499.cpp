#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define ssize_t long long 
#define size_t unsigned long long

struct matrix : vector<vector<size_t>>
{
    matrix(vector<vector<size_t>> a = {})
    {
        this->assign(a.begin(), a.end());
        return;
    }
    matrix operator*(matrix b)
    {
        matrix &a = *this;
        matrix ans;
        for(size_t i = 0; i < a.size(); i++)
        {
            ans.push_back({});
            for(size_t j = 0; j < a[0].size(); j++)
            {
                ans[i].push_back(0);
                for(size_t k = 0; k < a[0].size(); k++)
                {
                    ans[i][j] += a[i][k]*b[k][j]%MOD;
                    ans[i][j] %= MOD;
                }
            }
        }
        return ans;
    }
	void operator*=(matrix b)
    {
		*this = (*this)*b;
        return;
    }
    size_t& operator() (pair<size_t, size_t> &a)
    {
        return (*this)[a.first][a.second];
    }
    void unit()
    {
        for(size_t i = 0; i < this->size() || i < (*this)[0].size(); i++)
        {
            (*this)[i][i] = 1;
        }
        return;
    }
};
int main()
{
    cin.tie(0)->sync_with_stdio(false);

    size_t n, m, l, x, y;
    cin >> n >> m >> l;
    vector<matrix> orgins(1, vector(n, vector(n, 0ull)));
    matrix ans = orgins[0];
    ans.unit();
	while(m--)
	{
		cin >> x >> y;
		x--; y--;
		orgins[0][x][y] = 1;
	}
	while(l != 0)
	{
		if((l & 1) != 0)ans *= orgins.back();
		orgins.push_back(orgins.back()*orgins.back());
		l >>= 1;
	}
	for(auto &i : ans)
	{
		for(auto &j : i)
		{
			cout << j << ' ';
		}
		cout << '\n';
	}
}
