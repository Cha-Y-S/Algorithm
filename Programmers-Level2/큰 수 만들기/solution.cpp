#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
  string answer = "";

  int left = number.size() - k;
  int start = 0;

  while (left > 0) {
    start = max_element(number.begin() + start, number.end() - (left - 1)) - number.begin();
    answer.push_back(number[start++]);
    left--;
  }

  return answer;
}