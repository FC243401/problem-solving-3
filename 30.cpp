
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {


        vector<pair<int, int>> graph[n];

        for (auto &flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int price = flight[2];

            graph[u].push_back({v, price});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        while (!q.empty()) {

            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();

            if (stops > k)
                continue;

            for (auto &neighbor : graph[node]) {

                int nextNode = neighbor.first;
                int nextCost = neighbor.second;

                if (cost + nextCost < dist[nextNode]) {

                    dist[nextNode] = cost + nextCost;
                    q.push({stops + 1, {nextNode, dist[nextNode]}});
                }
            }
        }

        if (dist[dst] == INT_MAX)
            return -1;

        return dist[dst];
    }
};

int main() {

    Solution obj;

    int n = 4;

    vector<vector<int>> flights = {
        {0,1,100},
        {1,2,100},
        {2,0,100},
        {1,3,600},
        {2,3,200}
    };

    int src = 0;
    int dst = 3;
    int k = 1;

    int ans = obj.findCheapestPrice(n, flights, src, dst, k);

    cout << "Cheapest Price = " << ans << endl;

    return 0;
}
