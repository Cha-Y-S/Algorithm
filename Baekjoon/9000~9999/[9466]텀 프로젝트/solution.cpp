#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

void fastIO();
void initData();
int getNoTeamStudent();
void checkTeam(int cv);

vector<int> target;
vector<bool> finish;
vector<bool> visited;
int T, N, res;

int main() {
  fastIO();

  cin >> T;

  while (T--) {
    initData();

    cout << getNoTeamStudent() << endl;
  }

  return 0;
}

void fastIO() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

void initData() {
  cin >> N;

  target = vector<int>(N);
  finish = vector<bool>(N, false);
  visited = vector<bool>(N, false);

  for (int i = 0; i < N; i++) {
    cin >> target[i];

    target[i]--;
  }
}

int getNoTeamStudent() {
  res = N;

  for (int i = 0; i < N; i++) {
    if (!visited[i]) checkTeam(i);
  }

  return res;
}

void checkTeam(int cv) {
  visited[cv] = true;
  int nv = target[cv];

  if (!visited[nv]) {
    checkTeam(nv);
  } else if (!finish[nv]) {
    for (int i = nv; i != cv; i = target[i]) {
      res--;
    }
    res--;
  }
  finish[cv] = true;
}
