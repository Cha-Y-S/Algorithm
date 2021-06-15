#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int getGrade(int correct);

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
  vector<int> answer;
  int correct = 0;
  int pCorrect = 0;
  int zCnt = 0;

  sort(lottos.begin(), lottos.end());
  sort(win_nums.begin(), win_nums.end());

  for (int i = 0; i < lottos.size(); i++) {
    if (lottos[i] == 0) {
      lottos.erase(lottos.begin() + i--);
      zCnt++;
    }
  }

  for (int i = 0; i < lottos.size(); i++) {
    for (int j = 0; j < win_nums.size(); j++) {
      if (lottos[i] == win_nums[j]) {
        correct++;
        win_nums.erase(win_nums.begin() + j);
        break;
      }
    }
  }

  pCorrect = correct + zCnt;

  answer.push_back(getGrade(pCorrect));
  answer.push_back(getGrade(correct));

  return answer;
}

int getGrade(int correct) {
  switch (correct) {
    case 6:
      return 1;
      break;
    case 5:
      return 2;
    case 4:
      return 3;
    case 3:
      return 4;
    case 2:
      return 5;
      break;
    default:
      return 6;
      break;
  }
}