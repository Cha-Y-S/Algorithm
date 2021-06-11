#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  int answer = 0;
  int bit = 0;
  string base3number;

  while (pow(3, bit) <= n) {
    bit++;
  }

  while (bit-- != 0) {
    int base = pow(3, bit);
    base3number.push_back((n / base) + '0');
    n = n % base;
  }

  for (int i = 0; i < base3number.size(); i++) {
    answer += (base3number[i] - '0') * pow(3, i);
  }

  return answer;
}