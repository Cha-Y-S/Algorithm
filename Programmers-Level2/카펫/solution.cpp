#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
  vector<int> answer;
  int area = brown + yellow;

  for (int i = 1; i <= sqrt(area); i++) {
    if (area % i == 0) {
      int width = area / i;
      int height = i;
      if ((width + height) * 2 - 4 == brown) {
        answer = {width, height};
        break;
      }
    }
  }
  return answer;
}