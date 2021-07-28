#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
  vector<long long> answer;

  for (int i = 0; i < numbers.size(); i++) {
    for (int j = numbers[i] + 1;; j++) {
      bitset<50> bit(numbers[i] ^ j);

      int cnt = 0;
      for (int k = 0; k < bit.size(); k++) {
        if (bit[k]) cnt++;
      }

      if (cnt > 0 && cnt <= 2) {
        answer.push_back(j);
        break;
      }
    }
  }

  return answer;
}