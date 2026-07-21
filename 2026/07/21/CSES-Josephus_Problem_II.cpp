#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

typedef unsigned long long ull;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    int n, k;
	cin >> n >> k;

	tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> tree;

	for(int i = 1; i <= n; i++)tree.insert(i);
	for(int idx = k; tree.size() != 0; idx += k)
	{
		idx %= tree.size();
		auto it = tree.find_by_order(idx);
		cout << *it << ' ';
		tree.erase(it);
	}
}