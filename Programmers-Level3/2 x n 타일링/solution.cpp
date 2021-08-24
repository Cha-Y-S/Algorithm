#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  int answer = 0;
  vector<int> dp;

  dp.push_back(1);
  dp.push_back(2);

  for (int i = 2; i < n; i++)
    dp.push_back((dp[i - 1] % 1000000007 + dp[i - 2] % 1000000007) % 1000000007);

  answer = dp[n - 1];

  return answer;
}