#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> dp;
string A, B;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> A >> B;

  dp = vector<int>(A.size() + B.size());

  for (int i = 0; i < A.size(); i++)
    dp[i * 2] = A[i] - '0';

  for (int i = 0; i < B.size(); i++)
    dp[i * 2 + 1] = B[i] - '0';

  while (dp.size() > 2) {
    vector<int> temp(dp.size() - 1);

    for (int i = 0; i < temp.size(); i++)
      temp[i] = (dp[i] + dp[i + 1]) % 10;

    dp = temp;
  }

  cout << dp[0] << dp[1] << endl;

  return 0;
}