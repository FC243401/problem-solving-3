#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {


        vector<pair<int, int>> graph[n + 1];

        for (auto &edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            graph[u].push_back({v, w});
        }


        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;


        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        pq.push({0, k});

        while (!pq.empty()) {
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();


            if (time > dist[node])
                continue;


            for (auto &neighbor : graph[node]) {
                int nextNode = neighbor.first;
                int weight = neighbor.second;

                if (dist[node] + weight < dist[nextNode]) {
                    dist[nextNode] = dist[node] + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        int answer = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;

            answer = max(answer, dist[i]);
        }

        return answer;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> times = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}
    };

    int n = 4;
    int k = 2;

    cout << "Minimum Time: " << obj.networkDelayTime(times, n, k) << endl;

    return 0;
}
