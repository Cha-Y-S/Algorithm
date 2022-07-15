#include <iostream>

using namespace std;

#define endl "\n"

int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  cout << (N % 2 == 0 ? "SK" : "CY") << endl;

  return 0;
}