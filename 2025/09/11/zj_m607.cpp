#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

typedef pair<int, int> Pos;

#define x first
#define y second

Pos operator-(Pos &a, Pos &b)
{
	return {a.x-b.x, a.y-b.y};
}
int direction(Pos &a, Pos &b)
{
	auto tmp = b-a;	
	if(tmp.x > 0)return 0; // right 
	if(tmp.x < 0)return 1; // left
	if(tmp.y > 0)return 2; // up
	if(tmp.y < 0)return 3; // down
	return -1;
}
int solve()
{
	ull n;
	cin >> n;
	Pos before, now;
    cin >> before.x >> before.y;
	map<int, Pos> dnu;
	map<int, Pos> lnr;
	
	/* constructer */
	cin >> now.x >> now.y; 
	int lest = direction(before, now);
	switch(lest)
	{
		case 0:
			lnr[before.y] = {before.x, now.x};
            break;
		case 1:
			lnr[before.y] = {now.x, before.x};
            break;
		case 2:
			dnu[before.x] = {before.y, now.y};
            break;
		case 3:
			dnu[before.x] = {now.y, before.y};
            break;
	}
	before = now;
    n -= 2;
	while(n--)
	{
		cin >> now.x >> now.y;
		if(now.x == before.x && now.y == before.y)continue;
		int nlest = direction(before, now);
		switch(nlest)
		{
			case 0:
				if(lnr.find(now.y) == lnr.end())lnr[now.y] = {before.x, now.x};
				else 
                {
                    lnr[now.y].first = min(lnr[now.y].first, before.x);
                    lnr[now.y].second = max(lnr[now.y].second, now.x);
                }
				break;
			case 1:
				if(lnr.find(now.y) == lnr.end())lnr[now.y] = {now.x, before.x};
				else 
                {
                    lnr[now.y].first = min(lnr[now.y].first, now.x);
                    lnr[now.y].second = max(lnr[now.y].second, before.x);
                }
				break;
			case 2:
				if(dnu.find(now.x) == dnu.end())dnu[now.x] = {before.y, now.y};
				else 
                {
                    dnu[now.x].second = max(dnu[now.x].second, now.y);
                    dnu[now.x].first = min(dnu[now.x].first, before.y);
                }
				break;
			case 3:
				if(dnu.find(now.x) == dnu.end())dnu[now.x] = {now.y, before.y};
				else 
                {
                    dnu[now.x].first = min(dnu[now.x].first, now.y);
                    dnu[now.x].second = max(dnu[now.x].second, before.y);
                }
				break;
		}
		before = now;
		lest = nlest;
	}

    if(lnr.size() == 2 && dnu.size() == 2)return 0;
    if(lnr.size() == 0 && dnu.size() == 1)return 1;

    if(lnr.size() == 3 && dnu.size() == 1)return 3;
    auto ldnu = dnu.begin();
    auto rdnu = next(ldnu);
    
    if(lnr.size() == 1)
    {
        if(rdnu->second.first < lnr.begin()->first && lnr.begin()->first < rdnu->second.second)return 4;
        return 7;
    }
    bool right_mid = rdnu->second.first < next(lnr.begin())->first && next(lnr.begin())->first < rdnu->second.second;
    bool left_mid = ldnu->second.first < next(lnr.begin())->first && next(lnr.begin())->first < ldnu->second.second;
    if(left_mid && right_mid)return 8;
    if(left_mid)return 6;
    if(right_mid)return 9;
    
    if(next(lnr.begin())->first >= ldnu->second.second)return 2;
    return 5;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cout << solve();
}
