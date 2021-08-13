#include "solution.h"

int main() {
  vector<string> board;

  cout << solution(4, 5, board = {"CCBDE", "AAADE", "AAABF", "CCBBF"}) << endl;

  cout << solution(6, 6, board = {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"}) << endl;

  return 0;
}