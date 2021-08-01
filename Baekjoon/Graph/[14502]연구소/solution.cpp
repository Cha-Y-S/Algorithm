#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> lab;
vector<vector<int>> lCopy;
int safe = INT_MIN;

void makeWall(int cnt);
void bfs();

int main() {
  // ios::sync_with_stdio(0);
  // cin.tie(0);

  int n, m;

  cin >> n >> m;

  // Initialize matrix
  for (int i = 0; i < n; i++) {
    vector<int> input(m, -1);
    for (int j = 0; j < m; j++) {
      cin >> input[j];
    }
    lab.push_back(input);
  }

  lCopy = lab;

  // Set 3 of wall, spread virus(es) so that can get maximum value of safe area
  for (int i = 0; i < lCopy.size(); i++) {
    for (int j = 0; j < lCopy[i].size(); j++) {
      if (!lCopy[i][j]) {
        lCopy[i][j] = 1;
        makeWall(1);
        lCopy[i][j] = 0;
      }
    }
  }

  cout << safe << "\n";

  return 0;
}

void bfs() {
  int answer = 0;
  vector<vector<int>> virus(lCopy);
  queue<pair<int, int>> q;
  vector<pair<int, int>> dir = {make_pair(-1, 0), make_pair(0, 1), make_pair(1, 0), make_pair(0, -1)};

  // Initialize virus matrix
  for (int i = 0; i < virus.size(); i++) {
    for (int j = 0; j < virus[i].size(); j++) {
      if (virus[i][j] == 2) {
        q.push(make_pair(i, j));
      }
    }
  }

  // Spread virus(es)
  while (!q.empty()) {
    // Get virus's current location
    int cx = q.front().first;
    int cy = q.front().second;

    q.pop();

    for (int i = 0; i < dir.size(); i++) {
      // Set new location of virus that will be spreaded
      int nx = cx + dir[i].first;
      int ny = cy + dir[i].second;

      if ((0 <= nx && nx < virus.size()) && (0 <= ny && ny < virus[nx].size())) {
        if (!virus[nx][ny]) {
          virus[nx][ny] = 2;
          q.push(make_pair(nx, ny));
        }
      }
    }
  }

  // Get safe area
  for (int i = 0; i < virus.size(); i++) {
    for (int j = 0; j < virus[i].size(); j++) {
      if (!virus[i][j]) answer++;
    }
  }

  // Get maximum value of safe area
  safe = max(safe, answer);
}

void makeWall(int cnt) {
  if (cnt == 3) {
    bfs();
    return;
  }

  for (int i = 0; i < lCopy.size(); i++) {
    for (int j = 0; j < lCopy[i].size(); j++) {
      if (!lCopy[i][j]) {
        lCopy[i][j] = 1;
        makeWall(cnt + 1);
        lCopy[i][j] = 0;
      }
    }
  }
}