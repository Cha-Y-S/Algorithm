#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<int>> grade;
int K, N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> K;

  grade = vector<vector<int>>(K);

  for (int i = 0; i < K; i++) {
    cin >> N;

    grade[i] = vector<int>(N);

    cout << "Class " << i + 1 << endl;

    for (int j = 0; j < N; j++) {
      cin >> grade[i][j];
    }

    sort(grade[i].begin(), grade[i].end());

    cout << "Max " << grade[i][N - 1] << ", ";
    cout << "Min " << grade[i][0] << ", ";

    int gap = 0;

    for (int j = 1; j < N; j++) {
      gap = gap < grade[i][j] - grade[i][j - 1] ? grade[i][j] - grade[i][j - 1] : gap;
    }

    cout << "Largest gap " << gap << endl;
  }

  return 0;
}