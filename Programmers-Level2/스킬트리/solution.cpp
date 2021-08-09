#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isInside(string skill, char cur);

int solution(string skill, vector<string> skill_trees) {
  int answer = 0;

  for (int i = 0; i < skill_trees.size(); i++) {
    int skill_seq = 0;
    for (int j = 0; j < skill_trees[i].size(); j++) {
      // If skill_trees is inside of skill and has same skill sequence with skill, check next skill sequence
      if (isInside(skill, skill_trees[i][j]) && skill[skill_seq] == skill_trees[i][j]) {
        skill_seq++;
      }
      // If skill_trees is inside of skill and has not same sequece with skill, set skill_seq = -1;
      else if (isInside(skill, skill_trees[i][j]) && skill[skill_seq] != skill_trees[i][j]) {
        skill_seq = -1;
        break;
      }
    }

    // Check skill_trees has right sequence
    answer = skill_seq != -1 ? answer + 1 : answer;
  }

  return answer;
}

bool isInside(string skill, char cur) {
  bool result = false;
  for (int i = 0; i < skill.size(); i++) {
    if (skill[i] == cur) {
      result = true;
      break;
    }
  }
  return result;
}