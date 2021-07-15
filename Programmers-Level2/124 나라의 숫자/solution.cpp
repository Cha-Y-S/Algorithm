#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
  string answer = "";

  while (n != 0) {
    int remain = n % 3;
    n /= 3;
    if (!remain) {
      answer = "4" + answer;
      n--;
    } else {
      answer = to_string(remain) + answer;
    }
  }

  return answer;
}