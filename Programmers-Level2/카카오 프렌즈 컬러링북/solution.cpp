#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

vector<vector<bool>> visited;
vector<pii> dirs;

int bfs(int m, int n, int x, int y, int target, vector<vector<int>> &picture);

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
  vector<int> answer(2);
  int number_of_area = 0;
  int max_size_of_one_area = 0;

  vector<int> areas;
  visited = vector<vector<bool>>(m, vector<bool>(n, false));
  dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (!visited[i][j] && picture[i][j] != 0) {
        int tmp = bfs(m, n, i, j, picture[i][j], picture);

        max_size_of_one_area = tmp > max_size_of_one_area ? tmp : max_size_of_one_area;

        areas.push_back(tmp);
      }
    }
  }

  number_of_area = areas.size();

  answer[0] = number_of_area;
  answer[1] = max_size_of_one_area;

  return answer;
}

int bfs(int m, int n, int x, int y, int target, vector<vector<int>> &picture) {
  queue<pii> q;
  int result = 0;

  q.push({x, y});
  visited[x][y] = true;

  while (!q.empty()) {
    int cx = q.front().first;
    int cy = q.front().second;

    result++;

    q.pop();

    for (int i = 0; i < dirs.size(); i++) {
      int nx = cx + dirs[i].first;
      int ny = cy + dirs[i].second;

      if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

      if (!visited[nx][ny] && picture[nx][ny] == target) {
        q.push({nx, ny});
        visited[nx][ny] = true;
      }
    }
  }

  return result;
}