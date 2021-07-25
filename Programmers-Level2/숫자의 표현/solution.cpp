#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  int answer = 0;
  int sum = 0;

  for (int i = 1; i <= n / 2; i++) {
    sum += i;
    for (int j = i + 1; j <= n / 2 + 1; j++) {
      sum += j;
      if (sum > n) {
        sum = 0;
        break;
      } else if (sum == n) {
        sum = 0;
        answer++;
        break;
      }
    }
  }

  return ++answer;
}