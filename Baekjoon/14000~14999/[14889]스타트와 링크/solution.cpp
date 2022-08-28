#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<int>> S;
vector<bool> visited;
vector<int> team_start, team_link;
int N, res;

void fast_io();
void configuration_team_start(int idx, int count);
void configuration_team_link();
void calculate_team_ability_diff();
int calculate_team_ability(vector<int>& team);

int main() {
  fast_io();

  cin >> N;

  S = vector<vector<int>>(N, vector<int>(N));
  visited = vector<bool>(N, false);
  team_start = vector<int>(N / 2);
  team_link = vector<int>(N / 2);
  res = 101;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> S[i][j];
    }
  }

  configuration_team_start(0, 0);

  cout << res << endl;

  return 0;
}

void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

void configuration_team_start(int idx, int count) {
  if (count == (N / 2)) {
    configuration_team_link();
    calculate_team_ability_diff();
    return;
  }

  for (int i = idx; i < N; i++) {
    if (visited[i]) continue;
    visited[i] = true;
    team_start[count] = i;
    configuration_team_start(i + 1, count + 1);
    visited[i] = false;
  }
}

void configuration_team_link() {
  int idx = 0;
  for (int i = 0; i < N; i++) {
    if (!visited[i]) {
      team_link[idx++] = i;
    }
  }
}

void calculate_team_ability_diff() {
  int team_start_ability = calculate_team_ability(team_start);
  int team_link_ability = calculate_team_ability(team_link);

  int diff = abs(team_start_ability - team_link_ability);

  res = diff < res ? diff : res;
}

int calculate_team_ability(vector<int>& team) {
  int ability = 0;
  for (int i = 0; i < team.size(); i++) {
    for (int j = 0; j < team.size(); j++) {
      ability += S[team[i]][team[j]];
    }
  }
  return ability;
}