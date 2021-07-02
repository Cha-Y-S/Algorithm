#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<string> words) {
  vector<int> answer;
  vector<int> turn;
  bool failure = false;
  unordered_set<string> word;

  // Initialize vector turn
  for (int i = 0; i < n; i++)
    turn.push_back(0);

  // First Word
  string prevWord = words[0];
  word.insert(prevWord);
  turn[0]++;

  for (int i = 1; i < words.size(); i++) {
    turn[i % n]++;

    // Check prev word's last character && current word's first character
    // Check is current word in set
    if (prevWord.back() != words[i].front() || word.find(words[i]) != word.end()) {
      answer.push_back((i % n) + 1);
      answer.push_back(turn[i % n]);
      failure = true;
      break;
    }
    prevWord = words[i];    // Set prev word
    word.insert(prevWord);  // Insert current word into set
  }

  // If game is normally done
  if (!failure) {
    answer = {0, 0};
  }

  return answer;
}