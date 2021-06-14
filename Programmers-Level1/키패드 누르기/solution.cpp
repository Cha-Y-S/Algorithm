#include <cmath>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
  string answer = "";
  pair<int, int> lLoc(3, 0);
  pair<int, int> rLoc(3, 2);
  vector<int> pos = {3, 0, 0, 0, 1, 1, 1, 2, 2, 2};

  for (int i = 0; i < numbers.size(); i++) {
    switch (numbers[i]) {
      case 1:
      case 4:
      case 7:
        answer.push_back('L');
        lLoc.first = pos[numbers[i]];
        lLoc.second = 0;
        break;
      case 3:
      case 6:
      case 9:
        answer.push_back('R');
        rLoc.first = pos[numbers[i]];
        rLoc.second = 2;
        break;
      default:
        pair<int, int> dest(pos[numbers[i]], 1);
        int lDist = 0;
        int rDist = 0;
        lDist = abs(dest.first - lLoc.first) + abs(dest.second - lLoc.second);
        rDist = abs(dest.first - rLoc.first) + abs(dest.second - rLoc.second);
        if (lDist < rDist) {
          lLoc.first = pos[numbers[i]];
          lLoc.second = 1;
          answer.push_back('L');
        } else if (lDist > rDist) {
          rLoc.first = pos[numbers[i]];
          rLoc.second = 1;
          answer.push_back('R');
        } else {
          if (hand == "left") {
            lLoc.first = pos[numbers[i]];
            lLoc.second = 1;
            answer.push_back('L');
          } else {
            rLoc.first = pos[numbers[i]];
            rLoc.second = 1;
            answer.push_back('R');
          }
        }
        break;
    }
  }

  return answer;
}