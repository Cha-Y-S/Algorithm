#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<int>> city;
vector<pair<pii, bool>> visited;
vector<pii> chicken;
vector<pii> house;
int N, M, answer;

int get_chicken_distance();
void combination(int idx, int cnt);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  city = vector<vector<int>>(N, vector<int>(N));
  chicken = vector<pii>(M);
  answer = INT_MAX;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> city[i][j];
      if (city[i][j] == 1)
        house.push_back({i, j});
      else if (city[i][j] == 2)
        visited.push_back({{i, j}, false});
    }
  }

  combination(0, 0);

  cout << answer << endl;

  return 0;
}

int get_chicken_distance() {
  int distance = 0;
  for (int i = 0; i < house.size(); i++) {
    int d = N * 2;
    for (int j = 0; j < chicken.size(); j++) {
      int temp = abs(chicken[j].first - house[i].first) + abs(chicken[j].second - house[i].second);

      d = d < temp ? d : temp;
    }
    distance += d;
  }

  return distance;
}

void combination(int idx, int cnt) {
  if (cnt == M) {
    int result = get_chicken_distance();
    answer = answer < result ? answer : result;
    return;
  }
  for (int i = idx; i < visited.size(); i++) {
    if (visited[i].second) continue;
    visited[i].second = true;
    int cx = visited[i].first.first;
    int cy = visited[i].first.second;
    chicken[cnt] = {cx, cy};
    combination(i, cnt + 1);
    visited[i].second = false;
  }
}