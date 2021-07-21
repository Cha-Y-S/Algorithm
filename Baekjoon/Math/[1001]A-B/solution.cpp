#include <iostream>

using namespace std;

int solution(int A, int B);

int main() {
  int A, B;

  cin >> A >> B;

  cout << solution(A, B) << endl;
}

int solution(int A, int B) {
  return A - B;
}