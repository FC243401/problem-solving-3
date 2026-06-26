#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        // Start or destination is blocked
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        // 8 directions
        int dr[] = {-1,-1,-1,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,1,-1,0,1};

        queue<pair<int,int>> q;

        // Distance array
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        dist[0][0] = 1;
        q.push({0,0});

        while (!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // Destination reached
            if (r == n - 1 && c == n - 1)
                return dist[r][c];

            for (int i = 0; i < 8; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    grid[nr][nc] == 0 &&
                    dist[nr][nc] == INT_MAX) {

                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return -1;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> grid = {
        {0,1},
        {1,0}
    };

    cout << obj.shortestPathBinaryMatrix(grid);

    return 0;
}
