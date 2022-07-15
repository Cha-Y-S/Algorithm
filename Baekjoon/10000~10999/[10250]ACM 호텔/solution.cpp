#include <iostream>
#include <string>

using namespace std;

string solution(int h, int w, int n);

int main() {
  int tCase, h, w, n;

  cin >> tCase;

  for (int i = 0; i < tCase; i++) {
    cin >> h >> w >> n;
    cout << solution(h, w, n) << endl;
  }

  return 0;
}

string solution(int h, int w, int n) {
  string answer = "";

  if (n % h == 0) {
    answer += to_string(h);
    answer += (n / h < 10 ? "0" + to_string(n / h) : to_string(n / h));
  } else {
    answer += to_string(n % h);
    answer += (n / h + 1 < 10 ? "0" + to_string(n / h + 1) : to_string(n / h + 1));
  }

  return answer;
}