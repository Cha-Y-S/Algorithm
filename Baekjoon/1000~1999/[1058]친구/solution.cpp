#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"
#define INF 987'654'321

vector<vector<int>> relation;
string person;
int N, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  relation = vector<vector<int>>(N, vector<int>(N, 0));
  res = 0;

  for (int i = 0; i < N; i++) {
    cin >> person;

    for (int j = 0; j < person.size(); j++) {
      if (i == j) continue;
      relation[i][j] = person[j] == 'Y' ? 1 : INF;
    }
  }

  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (i == j || j == k || k == i) continue;

        if (relation[i][j] > relation[i][k] + relation[k][j])
          relation[i][j] = relation[i][k] + relation[k][j];
      }
    }
  }

  for (int i = 0; i < N; i++) {
    int temp = 0;

    for (int j = 0; j < N; j++) {
      if (i == j) continue;

      temp = relation[i][j] <= 2 ? temp + 1 : temp;
    }

    res = res > temp ? res : temp;
  }

  cout << res << endl;

  return 0;
}