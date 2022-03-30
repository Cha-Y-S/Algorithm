#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<pii> info;
vector<int> point;
int N, M, id, grade;

int cmp(const pii a, const pii b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  point = vector<int>(N);
  info = vector<pii>(M);

  for (int i = 0; i < N; i++) {
    cin >> point[i];
  }

  for (int i = 0; i < M; i++) {
    char tmp;
    grade = 0;

    cin >> id;
    for (int j = 0; j < N; j++) {
      cin >> tmp;

      if (tmp == 'O') grade += point[j];
    }

    info[i] = {grade, id};
  }

  sort(info.begin(), info.end(), cmp);

  cout << info[0].second << " " << info[0].first << endl;

  return 0;
}

int cmp(const pii a, const pii b) {
  if (a.first != b.first) {
    return a.first > b.first;
  } else {
    return a.second < b.second;
  }
}