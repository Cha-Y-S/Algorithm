#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

vector<vector<int>> place;
vector<pii> dirs;
pii loc;
int N, M, dir, answer;

int activate_robot();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  place = vector<vector<int>>(N, vector<int>(M));
  dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  cin >> loc.first >> loc.second >> dir;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++)
      cin >> place[i][j];
  }

  answer = activate_robot();

  cout << answer << endl;

  return 0;
}

int activate_robot() {
  int cleaned = 0;
  queue<pair<pii, int>> q;

  q.push({loc, dir});

  while (!q.empty()) {
    bool flag = false;
    int cx = q.front().first.first;
    int cy = q.front().first.second;
    int cd = q.front().second;

    q.pop();

    // 1. Cleaning the current location
    if (place[cx][cy] == 0) {
      place[cx][cy] = 2;
      cleaned++;
    }

    // 2. Searching the adjacent cells
    for (int i = 0; i < 4; i++) {
      int ld = cd == 0 ? 3 : cd - 1;
      int nx = cx + dirs[ld].first;
      int ny = cy + dirs[ld].second;
      if ((0 <= nx && nx < N) && (0 <= ny && ny < M)) {
        // 2-a. if there is the place where is not cleaned at the left direction
        if (place[nx][ny] == 0) {
          q.push({{nx, ny}, ld});
          flag = true;
          break;
        }
      }
      // 2-b. if there is no place where is not cleaned
      cd = ld;
    }
    // Return to 1.
    if (flag) continue;

    // 2-c. Go back one space keeping the direction
    int nx = cx - dirs[cd].first;
    int ny = cy - dirs[cd].second;

    // 2-d. Deacivate robot, if back space is wall
    if (place[nx][ny] == 1) break;

    q.push({{nx, ny}, cd});
  }

  return cleaned;
}