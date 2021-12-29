#include <iostream>
#include <vector>

using namespace std;

#define MAX(X, Y) (X > Y ? X : Y)
#define endl "\n"

vector<vector<int>> triangle;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  triangle = vector<vector<int>>(N);

  for (int i = 0; i < N; i++) {
    vector<int> temp(i + 1);
    for (int j = 0; j < i + 1; j++)
      cin >> temp[j];
    triangle[N - i - 1] = temp;
  }

  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < triangle[i].size() - 1; j++) {
      triangle[i + 1][j] = MAX(triangle[i][j] + triangle[i + 1][j], triangle[i][j + 1] + triangle[i + 1][j]);
    }
  }

  cout << triangle[N - 1][0] << endl;

  return 0;
}