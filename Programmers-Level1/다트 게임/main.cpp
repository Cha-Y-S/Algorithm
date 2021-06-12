#include "solution.h"

int main() {
  string dartResult;

  cout << solution(dartResult = "1S2D*3T") << endl;

  cout << solution(dartResult = "1D2S#10S") << endl;

  cout << solution(dartResult = "1D2S0T") << endl;

  cout << solution(dartResult = "1S*2T*3S") << endl;

  cout << solution(dartResult = "1D#2S*3S") << endl;

  cout << solution(dartResult = "1T2D3D#") << endl;

  cout << solution(dartResult = "1D2S3T*") << endl;

  return 0;
}