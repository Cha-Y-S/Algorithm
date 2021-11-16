#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  int answer = 0;
  int i = 2;

  while (true) {
    if (n % i == 1) {
      answer = i;
      break;
    }
    i++;
  }

  return answer;
}