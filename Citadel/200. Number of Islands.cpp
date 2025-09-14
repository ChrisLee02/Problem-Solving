#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};
  inline bool isValidXY(int x, int y, int boundary_x, int boundary_y) {
    return x >= 0 && x < boundary_x && y >= 0 && y < boundary_y;
  }

 public:
  int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid.front().size();

    bool visited[301][301];
    memset(visited, 0, sizeof(visited));

    int ans = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1' && !visited[i][j]) {
          ans++;
          queue<pair<int, int>> Q;
          visited[i][j] = true;
          Q.push({i, j});

          while (!Q.empty()) {
            auto [x, y] = Q.front();
            Q.pop();

            for (int k = 0; k < 4; k++) {
              int nx = x + dx[k];
              int ny = y + dy[k];
              if (isValidXY(nx, ny, m, n) && grid[nx][ny] == '1' &&
                  !visited[nx][ny]) {
                visited[nx][ny] = true;
                Q.push({nx, ny});
              }
            }
          }
        }
      }
    }

    return ans;
  }
};