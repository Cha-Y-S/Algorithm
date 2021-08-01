#include <iostream>

using namespace std;

long long euclidean(int x, int y);

long long solution(int w, int h) {
  long long answer = 1;
  long long gcd = w > h ? euclidean(w, h) : euclidean(h, w);

  answer = ((long long)w * (long long)h) - (w + h - gcd);

  return answer;
}

long long euclidean(int x, int y) {
  if (x % y == 0) {
    return y;
  } else {
    return euclidean(y, x % y);
  }
}