
#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<int> adj[N];
double ans = 0.0;

void dfs(int node, int parent, double prob, int dist) {

    int childCount = 0;

    for (int child : adj[node]) {
        if (child != parent)
            childCount++;
    }


    if (childCount == 0) {
        ans += prob * dist;
        return;
    }

    for (int child : adj[node]) {

        if (child == parent)
            continue;

        dfs(child, node, prob / childCount, dist + 1);
    }
}

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {

        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 1.0, 0);

    cout << fixed << setprecision(15) << ans << endl;

    return 0;
}
