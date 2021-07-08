#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<vector<int>> maps) {
  int answer = 0;
  vector<vector<int>> visited;
  queue<pair<int, int>> q;
  vector<pair<int, int>> dir = {make_pair(0, -1), make_pair(1, 0), make_pair(0, 1), make_pair(-1, 0)};

  int dx = maps.size() - 1;
  int dy = maps[dx].size() - 1;

  // Initialize visited matrix
  for (int i = 0; i < dx + 1; i++) {
    vector<int> temp(dy + 1, 0);
    visited.push_back(temp);
  }

  q.push(make_pair(0, 0));
  visited[0][0] = 1;

  while (!q.empty()) {
    // Current location
    int cx = q.front().first;
    int cy = q.front().second;
    q.pop();

    for (int i = 0; i < dir.size(); i++) {
      // Set new location
      int nx = cx + dir[i].first;
      int ny = cy + dir[i].second;

      if (((0 <= nx) && (nx <= dx)) && ((0 <= ny) && (ny <= dy))) {
        // New location is inside on maps
        if (!visited[nx][ny] && maps[nx][ny]) {
          // Current location can go next step
          // Store new location's total step from starting location
          q.push(make_pair(nx, ny));
          visited[nx][ny] = visited[cx][cy] + 1;
        }
      }
    }
  }

  answer = visited[dx][dy] ? visited[dx][dy] : -1;

  return answer;
}