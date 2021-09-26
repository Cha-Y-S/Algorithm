#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int comp(string a, string b) {
  return a + b > b + a;
}

string solution(vector<int> numbers) {
  string answer = "";
  vector<string> sNums;

  for (int i = 0; i < numbers.size(); i++) {
    sNums.push_back(to_string(numbers[i]));
  }

  sort(sNums.begin(), sNums.end(), comp);

  for (int i = 0; i < sNums.size(); i++)
    answer += sNums[i];

  answer = answer[0] == '0' ? "0" : answer;

  return answer;
}