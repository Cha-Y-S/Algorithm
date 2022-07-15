#include <iostream>
#include <string>

using namespace std;

int solution(int n);

int main() {
  int n;

  cin >> n;

  cout << solution(n) << endl;

  return 0;
}

int solution(int n) {
  int answer = 0;
  string sNum;

  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum = i;
    sNum = to_string(i);
    for (int j = 0; j < sNum.size(); j++) {
      sum += sNum[j] - '0';
    }
    if (sum == n) {
      answer = i;
      break;
    }
  }

  return answer;
}