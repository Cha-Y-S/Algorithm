#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

vector<bool> broken;
int N, M, res;

bool check_move(int n);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  broken = vector<bool>(10, false);
  res = abs(N - 100);

  for (int i = 0; i < M; i++) {
    int button;

    cin >> button;

    broken[button] = true;
  }

  string num = to_string(N);

  for (int i = 0; i <= 1000000; i++) {
    if (check_move(i)) {
      int temp = abs(N - i) + to_string(i).size();
      res = res < temp ? res : temp;
    }
  }

  cout << res << endl;

  return 0;
}

bool check_move(int n) {
  string s = to_string(n);
  for (int i = 0; i < s.size(); i++) {
    if (broken[s[i] - '0'])
      return false;
  }

  return true;
}