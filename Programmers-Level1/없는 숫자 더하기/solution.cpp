#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
  int answer = 0;
  vector<bool> check(10, false);

  for (int i = 0; i < numbers.size(); i++)
    check[numbers[i]] = true;

  for (int i = 0; i < check.size(); i++) {
    if (!check[i]) answer += i;
  }

  return answer;
}