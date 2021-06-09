#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
  int answer = 0;

  for (int i = left; i < right + 1; i++) {
    int cnt = 0;
    int j = 0;
    for (j = 1; j * j < i; j++) {
      if (i % j == 0) cnt += 2;
    }

    if (j * j == i) cnt++;

    answer += cnt % 2 == 0 ? i : -i;
  }

  return answer;
}