#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> ds;
vector<int> path;
int N, M, connected;

void union_set(int a, int b);
int find_set(int a);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  ds = vector<int>(N);
  path = vector<int>(M);

  for (int i = 0; i < N; i++)
    ds[i] = i;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> connected;

      if (connected == 1)
        union_set(i, j);
    }
  }

  for (int i = 0; i < M; i++) {
    cin >> path[i];
    path[i]--;
  }

  bool flag = true;
  int start = find_set(path[0]);

  for (int i = 1; i < M; i++) {
    int dest = find_set(path[i]);

    if (start != dest) {
      flag = false;
      break;
    }
  }

  cout << (flag ? "YES" : "NO") << endl;

  return 0;
}

void union_set(int a, int b) {
  int sa = find_set(a);
  int sb = find_set(b);

  if (sa == sb) return;

  ds[sb] = sa;
}

int find_set(int a) {
  if (ds[a] == a) return a;
  return ds[a] = find_set(ds[a]);
}
