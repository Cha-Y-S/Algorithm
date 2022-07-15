#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<int>> party;
vector<int> truth;
vector<int> ds;
int N, M, F, res;

void union_set(int a, int b);
int find_set(int a);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M >> F;

  party = vector<vector<int>>(M);
  truth = vector<int>(F);
  ds = vector<int>(N);
  res = M;

  for (int i = 0; i < N; i++)
    ds[i] = i;

  for (int i = 0; i < F; i++) {
    cin >> truth[i];
    truth[i]--;
  }

  for (int i = 0; i < M; i++) {
    int size;

    cin >> size;

    party[i] = vector<int>(size);

    for (int j = 0; j < size; j++) {
      cin >> party[i][j];

      party[i][j]--;
    }
  }

  for (int i = 0; i < M; i++) {
    for (int j = 1; j < party[i].size(); j++)
      union_set(party[i][0], party[i][j]);
  }

  for (int i = 0; i < M; i++) {
    bool flag = true;
    for (int j = 0; j < party[i].size(); j++) {
      if (!flag) break;
      for (int k = 0; k < truth.size(); k++) {
        if (find_set(party[i][j]) == find_set(truth[k])) {
          flag = false;
          break;
        }
      }
    }
    if (!flag) res--;
  }

  cout << res << endl;

  return 0;
}

void union_set(int a, int b) {
  int sa = find_set(a);
  int sb = find_set(b);

  if (sa == sb) return;

  ds[sb] = sa;
}

int find_set(int a) {
  if (a == ds[a]) return a;
  return ds[a] = find_set(ds[a]);
}