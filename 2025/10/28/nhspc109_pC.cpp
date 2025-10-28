#include <bits/stdc++.h>

using namespace std;


vector<int> s;
void in(int &a)
{
	string s;
	cin >> s;
	a = 0;
	for(auto &i : s) a |= 1<<(i-'a');
	return; 
}

bool test(int x)
{
	int cnt = 0;
	for(auto &i : s)
	{
		if(i == x)continue; 
		if((i & x) == 0)continue;
		if((i & x) == x)continue;
		else if((i & x) == i)continue;
		else 
		{
			cnt++;
			break;
		}
	}
	return cnt == 0;
}

int dfs(int x, int x1 = 0, int x2 = 0, int cnt = 0)
{
	if(x == 0)
	{
		if(test(x1) && test(x2))return 1;
		else return 0;
	}
	if(x & 1)return dfs(x>>1, x1 + (1<<cnt), x2, cnt+1) + dfs(x>>1, x1, x2 + (1<<cnt), cnt+1);
	return dfs(x>>1, x1, x2, cnt+1);
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	int n;
	cin >> n;
	int x; in(x);
	s = vector<int>(n);
	for(auto &i : s)in(i);
	int p[5];
	for(auto &i : s)
	{
		if(i == x)continue; 
		if((i & x) == 0)p[0]++;
		else if((i & x) == x)p[1]++;
		else if((i & x) == i)p[2]++;
		else p[3]++;
	}
	p[4] = dfs(x);
	for(int i = 0; i < 5; i++)cout << p[i] << ' ';
}
 