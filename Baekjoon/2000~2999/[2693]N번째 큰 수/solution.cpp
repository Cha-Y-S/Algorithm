#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> A;
int T;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> T;

  for (; T > 0; T--) {
    A = vector<int>(10);

    for (int i = 0; i < 10; i++)
      cin >> A[i];

    sort(A.begin(), A.end(), greater<>());

    cout << A[2] << endl;
  }

  return 0;
}