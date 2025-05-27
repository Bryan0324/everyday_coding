#include <bits/stdc++.h>
using namespace std;

#define ssize_t long long
#define size_t unsigned long long

#define weight first
#define to second.second
#define from second.first
typedef pair<size_t, pair<size_t, size_t>> edge;

const int MAXN = 100005;
vector<pair<size_t, size_t>> tree[MAXN];
int depth[MAXN];
size_t up[MAXN][20], maxW[MAXN][20];
int parent[MAXN];

size_t find(int x) {
    if (parent[x] != x) return parent[x] = find(parent[x]);
    return x;
}

void dfs(size_t u, size_t p, size_t w) {
    up[u][0] = p;
    maxW[u][0] = w;
    for (auto &[v, wt] : tree[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u, wt);
    }
}

size_t query(size_t u, size_t v) {
    if (depth[u] < depth[v]) swap(u, v);
    size_t res = 0;
    for (int i = 19; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) {
            res = max(res, maxW[u][i]);
            u = up[u][i];
        }
    }
    if (u == v) return res;
    for (int i = 19; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            res = max({res, maxW[u][i], maxW[v][i]});
            u = up[u][i];
            v = up[v][i];
        }
    }
    return max({res, maxW[u][0], maxW[v][0]});
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    size_t n, m;
    cin >> n >> m;
    vector<edge> edges(m);
    for (size_t i = 0; i < m; i++) {
        size_t a, b, w;
        cin >> a >> b >> w;
        --a, --b;
        edges[i] = {w, {a, b}};
    }

    // Step 1: Kruskal «Ø¥ß MST
    iota(parent, parent + n, 0);
    sort(edges.begin(), edges.end());
    vector<bool> in_mst(m, false);
    vector<edge> mst_edges;
    for (size_t i = 0; i < m; i++) {
        size_t u = edges[i].from, v = edges[i].to, w = edges[i].weight;
        size_t ru = find(u), rv = find(v);
        if (ru != rv) {
            parent[ru] = rv;
            mst_edges.push_back(edges[i]);
            tree[u].emplace_back(v, w);
            tree[v].emplace_back(u, w);
            in_mst[i] = true;
        }
    }
    dfs(0, 0, 0);
    for (int k = 1; k < 20; k++) {
        for (size_t i = 0; i < n; i++) {
            up[i][k] = up[up[i][k - 1]][k - 1];
            maxW[i][k] = max(maxW[i][k - 1], maxW[up[i][k - 1]][k - 1]);
        }
    }
    size_t ans = 0;
    for (size_t i = 0; i < m; i++) {
        if (in_mst[i]) continue;
        size_t u = edges[i].from, v = edges[i].to, w = edges[i].weight;
        size_t max_in_path = query(u, v);
        if (max_in_path == w) ans++;
    }

    cout << ans << "\n";
}
