#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<pair<int, pii>> grade;
map<int, int> m;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  grade = vector<pair<int, pii>>(N, {0, {0, 0}});

  for (int i = 0; i < N; i++) {
    int nation, student, point;

    cin >> nation >> student >> point;

    grade[i] = {point, {nation, student}};
  }

  sort(grade.begin(), grade.end(), greater<>());

  int i, cnt;
  i = cnt = 0;
  while (cnt < 3) {
    if (m[grade[i].second.first] == 2) {
      i++;
      continue;
    }
    m[grade[i].second.first]++;
    cnt++;
    cout << grade[i].second.first << " " << grade[i].second.second << endl;
    i++;
  }

  return 0;
}
