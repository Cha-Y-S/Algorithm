#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
  string answer = "";

  // Step 1
  for (int i = 0; i < new_id.size(); i++) {
    if (new_id[i] >= 'A' && new_id[i] <= 'Z') new_id[i] = tolower(new_id[i]);
  }

  // Step 2
  for (int i = 0; i < new_id.size(); i++) {
    if (!((new_id[i] >= 'a' && new_id[i] <= 'z') || isdigit(new_id[i]) || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')) {
      new_id.erase(i--, 1);
    }
  }

  // Step 3
  bool isDot = false;
  for (int i = 0; i < new_id.size(); i++) {
    if (!isDot && new_id[i] == '.')
      isDot = true;
    else if (isDot && new_id[i] == '.')
      new_id.erase(i--, 1);
    else
      isDot = false;
  }

  // Step 4
  if (new_id[0] == '.') new_id.erase(0, 1);
  if (new_id[new_id.size() - 1] == '.') new_id.erase(new_id.size() - 1, 1);

  // Step 5
  if (new_id == "") new_id = "a";

  // Step 6
  if (new_id.size() >= 16) new_id.erase(new_id.begin() + 15, new_id.end());
  if (new_id[new_id.size() - 1] == '.') new_id.erase(new_id.size() - 1, 1);

  // Step 7
  if (new_id.size() <= 2) {
    while (new_id.size() != 3) {
      new_id += new_id[new_id.size() - 1];
    }
  }

  return answer = new_id;
}