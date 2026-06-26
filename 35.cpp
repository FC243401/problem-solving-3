
#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<int> adj[N];
int cat[N];
int n, m;
int ans = 0;

void dfs(int node, int parent, int consecutiveCats) {


    if (cat[node] == 1)
        consecutiveCats++;
    else
        consecutiveCats = 0;


    if (consecutiveCats > m)
        return;

    bool isLeaf = true;

    for (int child : adj[node]) {

        if (child == parent)
            continue;

        isLeaf = false;
        dfs(child, node, consecutiveCats);
    }


    if (isLeaf)
        ans++;
}

int main() {

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> cat[i];

    for (int i = 0; i < n - 1; i++) {

        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 0);

    cout << ans << endl;

    return 0;
}
