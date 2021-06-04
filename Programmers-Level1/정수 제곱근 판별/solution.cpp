#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
  long long answer = 0;

  answer = pow((int)sqrt(n), 2) == n ? pow((int)sqrt(n) + 1, 2) : -1;

  return answer;
}