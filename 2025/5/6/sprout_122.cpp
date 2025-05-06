#include <bits/stdc++.h>
#include "lib0122.h"
using namespace std;
#pragma GCC optimize("O3")
const int MOD = 1e9 + 7;
#define ssize_t long long 
#define size_t unsigned long long

void dfs(int ptr, int end, vector<size_t> &a, vector<pair<size_t, size_t>> &p, const size_t k, pair<size_t, size_t> now = {0, 0})
{
	if(now.first > k)return;
	if(ptr == end)
	{
		p.push_back(now);
		return;
	}
	dfs(ptr+1, end, a, p, k, now);
	now.first += a[ptr];
	now.second |= (1ull << ptr);
	dfs(ptr+1, end, a, p, k, now);
	return;
};
void solve(int N,long long K,long long A[])
{
    vector<size_t> a(A, A+N);
	vector<pair<size_t, size_t>> left, right;
	
	dfs(0, N/2, a, left, K);
	dfs(N/2, N, a, right, K);
	unordered_map<size_t, size_t> um;
	for(auto &i : right)um[i.first] = i.second;
	size_t ans = 0;
	for(auto &i : left)
	{
		if( um.find(K-i.first) != um.end() )
		{
			ans = um[K-i.first] | i.second;
			break;
		}
	}
	for (size_t i = 0; ans != 0; i++)
	{
		if((ans & (1ull << i)) != 0)
		{
			Report(i+1);
			ans ^= 1ull << i;
		}
	}
	Report(-1);
	return;
};
