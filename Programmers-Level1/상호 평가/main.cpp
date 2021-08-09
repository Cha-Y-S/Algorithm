#include "solution.h"

int main() {
  vector<vector<int>> scores;

  cout << solution(scores = {{100, 90, 98, 88, 65}, {50, 45, 99, 85, 77}, {47, 88, 95, 80, 67}, {61, 57, 100, 80, 65}, {24, 90, 94, 75, 65}}) << endl;

  cout << solution(scores = {{50, 90}, {50, 87}}) << endl;

  cout << solution({{70, 49, 90}, {68, 50, 38}, {73, 31, 100}}) << endl;

  return 0;
}