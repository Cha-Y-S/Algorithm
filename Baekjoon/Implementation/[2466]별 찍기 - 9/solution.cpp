#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<char>> star;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      cout << " ";
    }
    for (int j = 0; j < 2 * (N - i) - 1; j++) {
      cout << "*";
    }
    cout << endl;
  }

  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N - i - 2; j++) {
      cout << " ";
    }
    for (int j = 0; j < 2 * i + 3; j++) {
      cout << "*";
    }
    cout << endl;
  }

  return 0;
}