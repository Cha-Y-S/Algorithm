#include <bitset>
#include <iostream>

using namespace std;

int solution(int n) {
  int ans = 0;
  bitset<32> bit(n);

  for (int i = 0; i < bit.size(); i++) {
    if (bit[i]) ans++;
  }

  return ans;
}