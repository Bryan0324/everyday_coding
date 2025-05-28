#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

#define ssize_t long long
#define size_t unsigned long long

struct trie
{
    trie *children[26] = {0};
    size_t pass = 0;
};
trie trie_pool[(int)1e6];
size_t pool_ptr = 0;
void reset_pool()
{
    pool_ptr = 0;
}
trie *new_trie()
{
    trie_pool[pool_ptr].pass = 0;
    memset(trie_pool[pool_ptr].children, 0, sizeof(trie_pool[pool_ptr].children));
    return &trie_pool[pool_ptr++];
}

void add(trie* now, const string &s, size_t ptr = 0)
{
    now->pass++;
    if(ptr == s.size())return;
    else 
    {
        if(now->children[(int)s[ptr]] == 0)now->children[(int)s[ptr]] = new_trie();
        add(now->children[(int)s[ptr]], s, ptr+1);
    }
}
size_t find(trie* now, const string &s, size_t ptr = 0)
{
    if(ptr == s.size())return ptr;
    if(now->pass == 1)return (ptr == 0 ? 1 : ptr);
    else return find(now->children[(int)s[ptr]], s, ptr+1);
}

size_t solve()
{
    reset_pool();
    trie *tree = new_trie();
    size_t n, ans = 0;
    cin >> n;
    string s;
    while(n--)
    {
        cin >> s;
        for(auto &i : s)i -= 'a';
        add(tree, s);
        ans += find(tree, s);
    }
    return ans;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    size_t t;
    cin >> t;
    for (size_t i = 1; i <= t; i++)
    {
        cout << "Case #"<<i<<": " << solve() << '\n';
    }
    
}