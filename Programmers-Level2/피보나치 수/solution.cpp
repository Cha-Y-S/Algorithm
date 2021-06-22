#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  int *answer = new int[n + 1];
  answer[0] = 0;
  answer[1] = 1;
  answer[2] = 1;

  // Property of Modular arithmetic
  // (A + B) % C = (A % C) + (B % C) % C

  for (int i = 3; i <= n; i++) {
    answer[i] = answer[i - 1] % 1234567 + answer[i - 2] % 1234567;
  }

  return answer[n] % 1234567;
}