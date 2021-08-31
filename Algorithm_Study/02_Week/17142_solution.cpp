#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

int bfs(vector<vector<int>> lab, vector<pair<int, int>> v, int e_cnt);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;

  cin >> n >> m;

  vector<vector<int>> lab(n);
  vector<pair<int, int>> dv;
  int empty_cnt = 0;

  for (int i = 0; i < n; i++) {
    vector<int> input(n);

    for (int j = 0; j < n; j++) {
      cin >> input[j];
      if (input[j] == 1)
        input[j] = -1;
      else if (input[j] == 2) {
        dv.push_back({i, j});
        input[j] = 0;
      } else {
        input[j] = -2;
        empty_cnt++;
      }
    }

    lab[i] = input;
  }

  vector<bool> comb(dv.size() - m, false);
  comb.insert(comb.end(), m, true);
  int min = INT_MAX;

  do {
    vector<pair<int, int>> av;
    for (int i = 0; i < comb.size(); i++) {
      if (!comb[i]) {
        lab[dv[i].first][dv[i].second] = -3;
      } else {
        av.push_back(dv[i]);
      }
    }
    int temp = bfs(lab, av, empty_cnt);

    if (min == INT_MAX) {
      min = temp;
    } else if (min >= 0) {
      if (temp != -1)
        min = min > temp ? temp : min;
    } else {
      if (temp != -1)
        min = temp;
    }

    for (int i = 0; i < comb.size(); i++) {
      if (!comb[i]) lab[dv[i].first][dv[i].second] = 0;
    }
  } while (next_permutation(comb.begin(), comb.end()));

  cout << min << endl;

  return 0;
}

int bfs(vector<vector<int>> lab, vector<pair<int, int>> v, int e_cnt) {
  int result = 0;
  queue<pair<int, int>> q;
  vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  int infect = 0;

  for (int i = 0; i < v.size(); i++) {
    q.push(v[i]);
  }

  while (!q.empty()) {
    int cx = q.front().first;
    int cy = q.front().second;

    q.pop();

    for (int i = 0; i < dir.size(); i++) {
      int nx = cx + dir[i].first;
      int ny = cy + dir[i].second;

      if ((0 <= nx && nx < lab.size()) && (0 <= ny && ny < lab[nx].size())) {
        if (lab[nx][ny] == -2 || lab[nx][ny] == -3) {
          bool isRoad = lab[nx][ny] == -2 ? true : false;
          lab[nx][ny] = lab[cx][cy] + 1;
          if (isRoad) {
            infect++;
            result = result < lab[nx][ny] ? lab[nx][ny] : result;
          }
          q.push({nx, ny});
        }
      }
    }
  }

  if (infect != e_cnt) {
    result = -1;
  }

  return result;
}