#include <cmath>

using namespace std;

long long solution(int price, int money, int count) {
  long long answer = money;

  for (int i = 0; i < count; i++)
    answer -= price * (i + 1);

  answer = answer < 0 ? abs(answer) : 0;

  return answer;
}