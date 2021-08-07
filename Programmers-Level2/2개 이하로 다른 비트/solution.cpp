#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
  vector<long long> answer;

  for (int i = 0; i < numbers.size(); i++) {
    int digit = 0;
    long long number = numbers[i];

    while (number & (1LL << digit)) {
      digit++;
    }

    if (digit) {
      long long temp = 1LL << (digit - 1);
      number = number + (1LL << digit) - temp;
    } else {
      number += 1;
    }
    answer.push_back(number);
  }

  return answer;
}