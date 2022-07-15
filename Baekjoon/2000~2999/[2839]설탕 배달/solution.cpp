#include <iostream>

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
  int bag5 = 0;
  int bag3 = 0;

  bag5 = n / 5;
  n -= bag5 * 5;

  while (n > 0) {
    if (n % 3 == 0) {
      bag3 = n / 3;
      n -= bag3 * 3;
    } else {
      if (!bag5) {
        break;
      } else {
        bag5 -= 1;
        n += 5;
      }
    }
  }

  answer = n == 0 ? bag5 + bag3 : -1;

  return answer;
}