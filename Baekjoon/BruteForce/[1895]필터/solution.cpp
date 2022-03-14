#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<int>> img;
vector<vector<int>> filtered;
int R, C, T, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> R >> C;

  img = vector<vector<int>>(R, vector<int>(C));
  res = 0;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> img[i][j];
    }
  }

  cin >> T;

  for (int i = 0; i < R - 2; i++) {
    for (int j = 0; j < C - 2; j++) {
      vector<int> tmp;

      for (int ti = 0; ti < 3; ti++) {
        for (int tj = 0; tj < 3; tj++) {
          tmp.push_back(img[i + ti][j + tj]);
        }
      }

      sort(tmp.begin(), tmp.end());

      if (tmp[4] >= T) res++;
    }
  }

  cout << res << endl;

  return 0;
}