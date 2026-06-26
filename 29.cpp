
#include <bits/stdc++.h>
using namespace std;

vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {

    // Adjacency List
    vector<pair<int,int>> adj[n + 1];

    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});


    vector<int> dist(n + 1, INT_MAX);
    dist[s] = 0;

    priority_queue<e}
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    pq.push({0, s});

    while (!pq.empty()) {

        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Ignore outdated entries
        if (d > dist[node])
            continue;

        for (auto it : adj[node]) {

            int next = it.first;
            int weight = it.second;

            if (dist[node] + weight < dist[next]) {

                dist[next] = dist[node] + weight;
                pq.push({dist[next], next});
            }
        }
    }

    vector<int> ans;

    for (int i = 1; i <= n; i++) {

        if (i == s)
            continue;

        if (dist[i] == INT_MAX)
            ans.push_back(-1);
        else
            ans.push_back(dist[i]);
    }

    return ans;
}

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        vector<vector<int>> edges;

        for (int i = 0; i < m; i++) {

            int u, v, w;
            cin >> u >> v >> w;

            edges.push_back({u, v, w});
        }

        int s;
        cin >> s;

        vector<int> result = shortestReach(n, edges, s);

        for (int x : result)
            cout << x << " ";

        cout << endl;
    }

    return 0;
}
