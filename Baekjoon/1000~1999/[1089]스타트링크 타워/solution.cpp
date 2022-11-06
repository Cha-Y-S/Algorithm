#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<long long, int> pli;

void fastIO();
void initData();
double getCandidatesAvg();
bool checkCandidate(int targetIdx, int targetNum);

vector<vector<string>> numbers;
vector<vector<string>> info;
int N;

int main() {
  fastIO();

  initData();

  cout << getCandidatesAvg() << endl;

  return 0;
}

void fastIO() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

void initData() {
  numbers = {
      {"###", "..#", "###", "###", "#.#", "###", "###", "###", "###", "###"},
      {"#.#", "..#", "..#", "..#", "#.#", "#..", "#..", "..#", "#.#", "#.#"},
      {"#.#", "..#", "###", "###", "###", "###", "###", "..#", "###", "###"},
      {"#.#", "..#", "#..", "..#", "..#", "..#", "#.#", "..#", "#.#", "..#"},
      {"###", "..#", "###", "###", "..#", "###", "###", "..#", "###", "###"}};

  cin >> N;

  info = vector<vector<string>>(5, vector<string>(N));

  for (int i = 0; i < 5; i++) {
    string row;

    cin >> row;

    row = "." + row;

    for (int j = 0; j < N; j++) {
      string tmp = row.substr(1, 3);

      row = row.substr(4);

      info[i][j] = tmp;
    }
  }
}

double getCandidatesAvg() {
  double result = 0;
  double totalCase = 1;
  vector<pli> candidates(N, {0, 0});

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 10; j++) {
      if (checkCandidate(i, j)) {
        candidates[i].first += j * pow(10, N - i - 1);
        candidates[i].second++;
      }
    }
    totalCase *= candidates[i].second;
  }

  if (totalCase == 0) return -1;

  for (int i = 0; i < N; i++) {
    result += candidates[i].first * (totalCase / candidates[i].second);
  }

  result /= totalCase;

  return result;
}

bool checkCandidate(int targetIdx, int targetNum) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      if (numbers[i][targetNum][j] == '.' && info[i][targetIdx][j] == '#') {
        return false;
      }
    }
  }
  return true;
}
