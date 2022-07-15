#include <iostream>
#include <string>

using namespace std;

int solution(int n);
bool isHansu(int n);

int main() {
  int n;

  cin >> n;

  cout << solution(n) << endl;

  return 0;
}

int solution(int n) {
  int answer = 0;

  for (int i = 1; i <= n; i++) {
    if (isHansu(i)) answer++;
  }

  return answer;
}

bool isHansu(int n) {
  bool result = false;

  if (n < 100)
    result = true;
  else {
    string s = to_string(n);
    int diff = s[0] - s[1];
    for (int i = 1; i < s.size() - 1; i++) {
      if (diff == s[i] - s[i + 1]) result = true;
    }
  }

  return result;
}