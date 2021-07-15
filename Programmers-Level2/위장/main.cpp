#include "solution.h"

int main() {
  vector<vector<string>> clothes;

  cout << solution(clothes = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}}) << endl;

  cout << solution(clothes = {{"crowmask", "face"}, {"bluesunglasses", "face"}, {"smoky_makeup", "face"}}) << endl;

  return 0;
}