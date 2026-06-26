#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<string> names(n);

    for (int i = 0; i < n; i++)
        cin >> names[i];

    vector<int> indegree(26, 0);
    vector<vector<int>> adj(26);
    vector<vector<bool>> edge(26, vector<bool>(26, false));

    for (int i = 0; i < n - 1; i++) {

        string a = names[i];
        string b = names[i + 1];

        int len = min(a.size(), b.size());
        bool found = false;

        for (int j = 0; j < len; j++) {

            if (a[j] != b[j]) {

                int u = a[j] - 'a';
                int v = b[j] - 'a';

                if (!edge[u][v]) {
                    edge[u][v] = true;
                    adj[u].push_back(v);
                    indegree[v]++;
                }

                found = true;
                break;
            }
        }

        // Invalid prefix case
        if (!found && a.size() > b.size()) {
            cout << "Impossible";
            return 0;
        }
    }

    queue<int> q;

    for (int i = 0; i < 26; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    string ans;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        ans += char(node + 'a');

        for (int next : adj[node]) {
            indegree[next]--;

            if (indegree[next] == 0)
                q.push(next);
        }
    }

    if (ans.size() != 26) {
        cout << "Impossible";
        return 0;
    }

    cout << ans;

    return 0;
}
