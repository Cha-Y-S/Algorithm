#include <cmath>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
  vector<int> answer;
  map<string, int> enter;
  map<string, int> parking;
  stringstream st;

  for (int i = 0; i < records.size(); i++) {
    string t, n, info;
    int hour, minute;
    st.str(records[i]);

    st >> t >> n >> info;

    hour = stoi(t.substr(0, 2));
    minute = stoi(t.substr(3));

    if (info == "IN") {
      enter[n] = hour * 60 + minute;
    } else {
      parking[n] += (hour * 60 + minute) - enter[n];
      enter.erase(n);
    }

    st.clear();
  }

  for (pair<string, int> p : enter) {
    parking[p.first] += (23 * 60 + 59) - p.second;
  }

  for (pair<string, int> p : parking) {
    int fee;

    if (p.second <= fees[0]) {
      fee = fees[1];
    } else {
      fee = fees[1] + ceil((double)(p.second - fees[0]) / fees[2]) * fees[3];
    }

    answer.push_back(fee);
  }

  return answer;
}