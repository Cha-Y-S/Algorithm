#include <string>
#include <vector>

#define max(X, Y) ((X) > (Y) ? (X) : Y)

using namespace std;

int solution(vector<vector<int>> triangle) {
  int answer = 0;
  vector<int> dp = triangle[triangle.size() - 1];

  // Solve the problem as bottom-up
  for (int i = triangle.size() - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      int left = dp[j];
      int right = dp[j + 1];
      int target = triangle[i - 1][j];

      dp[j] = max(left + target, right + target);
    }
    // Remove last element
    dp.erase(dp.end() - 1);
  }

  answer = dp[0];

  return answer;
}