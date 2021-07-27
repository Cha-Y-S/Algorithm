#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct FName {
  string head;
  string number;
  string tail;
};

int compare(FName a, FName b) {
  transform(a.head.begin(), a.head.end(), a.head.begin(), ::tolower);
  transform(b.head.begin(), b.head.end(), b.head.begin(), ::tolower);
  if (a.head != b.head) {
    return a.head < b.head;
  } else {
    if (stoi(a.number) != stoi(b.number))
      return stoi(a.number) < stoi(b.number);
    else
      return 0;
  }
}

vector<string> solution(vector<string> files) {
  vector<string> answer;
  vector<FName> f;

  for (int i = 0; i < files.size(); i++) {
    FName temp;

    int j = 0;
    while (!isdigit(files[i][j])) {
      temp.head.push_back(files[i][j++]);
    }

    while (isdigit(files[i][j])) {
      temp.number.push_back(files[i][j++]);
    }

    for (; j < files[i].size(); j++) {
      temp.tail.push_back(files[i][j]);
    }

    f.push_back(temp);
  }

  stable_sort(f.begin(), f.end(), compare);

  for (int i = 0; i < f.size(); i++) {
    string temp = f[i].head + f[i].number + f[i].tail;
    answer.push_back(temp);
  }

  return answer;
}