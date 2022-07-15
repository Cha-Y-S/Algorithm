#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> ranking;
int N, target, P;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> target >> P;
  ranking = vector<int>(N);

  for (int i = 0; i < N; i++)
    cin >> ranking[i];

  int my_rank = 1;
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (target < ranking[i])
      my_rank += 1;
    else if (target > ranking[i])
      continue;
    cnt++;
  }

  if (cnt == P) my_rank = -1;
  if (N == 0) my_rank = 1;

  cout << my_rank << endl;

  return 0;
}