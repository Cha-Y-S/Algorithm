#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  int answer = 0;
  bitset<32> nBit(n);
  int result = n;

  int nCount = 0;
  int rCount = -1;

  for (int i = 0; i < nBit.size(); i++) {
    if (nBit[i] == 1) {
      nCount++;
    }
  }

  while (nCount != rCount) {
    rCount = 0;
    bitset<32> rBit(++result);
    for (int i = 0; i < rBit.size(); i++) {
      if (rBit[i] == 1) {
        rCount++;
      }
    }
  }

  answer = result;

  return answer;
}