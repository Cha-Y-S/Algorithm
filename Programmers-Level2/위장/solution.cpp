#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
  int answer = 1;
  unordered_map<string, int> h;

  // Count by clothes type(headgears, glasses, ...)
  for (vector<string> item : clothes)
    h[item[1]]++;

  // Caculate number of all cases including that each type of clothes is not weared
  for (pair<string, int> item : h)
    answer *= (item.second + 1);

  // Subtract the case that wear nothing
  return --answer;
}