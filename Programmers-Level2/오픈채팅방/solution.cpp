#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> solution(vector<string> record) {
  vector<string> answer;
  queue<pair<string, string>> q;
  unordered_map<string, string> map;

  for (int i = 0; i < record.size(); i++) {
    stringstream st;
    st.str(record[i]);

    while (!st.eof()) {
      string command;
      string uid;
      string name;

      st >> command;

      if (command == "Enter") {
        st >> uid >> name;
        map[uid] = name;
        q.push(make_pair(command, uid));
      } else if (command == "Leave") {
        st >> uid;
        q.push(make_pair(command, uid));
      } else {
        st >> uid >> name;
        map[uid] = name;
      }
    }
  }

  while (!q.empty()) {
    string command = q.front().first;
    string uid = q.front().second;
    string name = map[uid];
    string log = name + (command == "Enter" ? "님이 들어왔습니다." : "님이 나갔습니다.");
    answer.push_back(log);
    q.pop();
  }

  return answer;
}