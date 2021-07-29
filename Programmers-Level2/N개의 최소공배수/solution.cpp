#include <iostream>
#include <string>
#include <vector>

using namespace std;

int euclidean(int a, int b) {
  if (a % b == 0)
    return b;
  else
    return euclidean(b, a % b);
}

int solution(vector<int> arr) {
  int answer = 0;

  if (arr.size() == 1) {
    answer = arr[0];
  } else {
    int gcd = euclidean(arr[0], arr[1]);
    int lcm = arr[0] * arr[1] / gcd;
    for (int i = 2; i < arr.size(); i++) {
      gcd = euclidean(lcm, arr[i]);
      lcm = lcm * arr[i] / gcd;
    }

    answer = lcm;
  }

  return answer;
}