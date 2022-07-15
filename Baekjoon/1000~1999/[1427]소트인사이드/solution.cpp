#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int solution(int num);

int main() {
  int num;

  cin >> num;

  cout << solution(num) << endl;

  return 0;
}

int solution(int num) {
  int answer = 0;

  string temp = to_string(num);

  sort(temp.begin(), temp.end(), greater<>());

  answer = stoi(temp);

  return answer;
}