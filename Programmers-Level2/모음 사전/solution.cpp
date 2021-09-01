#include <map>
#include <string>
#include <vector>

using namespace std;

int solution(string word) {
  int answer = 0;

  map<char, int> alpha = {{'A', 0}, {'E', 1}, {'I', 2}, {'O', 3}, {'U', 4}};
  vector<int> cases = {781, 156, 31, 6, 1};

  for (int i = 0; i < word.size(); i++)
    answer += alpha[word[i]] * cases[i];

  answer += word.size();

  return answer;
}