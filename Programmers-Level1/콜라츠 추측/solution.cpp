#include <string>
#include <vector>

using namespace std;

int solution(int num) {
  int answer = 0;
  long long temp = num;

  while ((answer != 500) && (temp != 1)) {
    if (temp % 2 == 0) {
      temp /= 2;
    } else {
      temp *= 3;
      temp++;
    }
    answer++;
  }

  answer = answer == 500 ? -1 : answer;

  return answer;
}