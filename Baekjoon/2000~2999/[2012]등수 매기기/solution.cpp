#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef long long ll;

vector<int> grade;
ll res;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  grade = vector<int>(N);
  res = 0;

  for (int i = 0; i < N; i++) {
    cin >> grade[i];
  }

  sort(grade.begin(), grade.end());

  for (int i = 0; i < N; i++) {
    res += abs(grade[i] - (i + 1));
  }

  cout << res << endl;

  return 0;
}