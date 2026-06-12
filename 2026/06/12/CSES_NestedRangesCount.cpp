#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

typedef pair<pair<int, int>, int> range;

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<range> xy(n);
	for(int i = 0; i < n; i++)
	{
		cin >> xy[i].first.first >> xy[i].first.second;
		xy[i].second = i;
	}
	sort(xy.begin(), xy.end());
	vector<int> inner(n), outer(n);
	tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> back, front;
	for(auto &i : xy)back.insert(i.first.second);

	for(int i = 0; i < n; i++)
	{
		auto &[pos, idx] = xy[i];
		auto &[x, y] = pos;
		back.erase(back.find_by_order(back.order_of_key(y)));
		inner[idx] = back.order_of_key(y+1);
		outer[idx] = front.size() - front.order_of_key(y);

		inner[idx] += &*lower_bound(xy.begin(), xy.end(), range({{x, y}, n})) - &*lower_bound(xy.begin(), xy.end(), range({{x, 0}, 0})) -1;
		outer[idx] += &*lower_bound(xy.begin(), xy.end(), range({{x, 1e9+10}, n})) - &*lower_bound(xy.begin(), xy.end(), range({{x, y}, -1})) - 1;
		front.insert(y);
	}
	for(auto &i : inner)cout << i << ' ';
	cout << '\n';
	for(auto &i : outer)cout << i << ' ';
	cout << '\n';
}
