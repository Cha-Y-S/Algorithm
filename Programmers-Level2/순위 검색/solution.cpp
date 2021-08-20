#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int mappingInfo(string input);
void mappingLanguage(string lang, int& s, int& e);
void mappingJob(string job, int& s, int& e);
void mappingCareer(string career, int& s, int& e);
void mappingFood(string food, int& s, int& e);

vector<int> solution(vector<string> info, vector<string> query) {
  vector<int> answer;
  vector<int> db[3][2][2][2];

  // Parse applicant's information from info vector and Store it into database
  for (int i = 0; i < info.size(); i++) {
    stringstream st;
    st.str(info[i]);

    while (!st.eof()) {
      vector<int> info_index;
      int point;
      for (int i = 0; i < 4; i++) {
        string input;
        st >> input;
        info_index.push_back(mappingInfo(input));
      }

      st >> point;

      db[info_index[0]][info_index[1]][info_index[2]][info_index[3]].push_back(point);
    }
  }

  // Sort in order to perform binary search
  for (int l = 0; l < 3; l++)
    for (int j = 0; j < 2; j++)
      for (int c = 0; c < 2; c++)
        for (int f = 0; f < 2; f++)
          sort(db[l][j][c][f].begin(), db[l][j][c][f].end());

  for (int i = 0; i < query.size(); i++) {
    // Parse condition from query and Convert to integer
    stringstream st;
    string lang, job, career, food, temp;
    int point, sl, sj, sc, sf, el, ej, ec, ef;
    st.str(query[i]);

    st >> lang >> temp >> job >> temp >> career >> temp >> food >> point;

    // Get applicant's scope that satisfy each condition
    mappingLanguage(lang, sl, el);
    mappingJob(job, sj, ej);
    mappingCareer(career, sc, ec);
    mappingFood(food, sf, ef);

    int cnt = 0;
    for (int l = sl; l < el; l++) {
      for (int j = sj; j < ej; j++) {
        for (int c = sc; c < ec; c++) {
          for (int f = sf; f < ef; f++) {
            int n = db[l][j][c][f].size();
            if (!n) continue;

            vector<int>::iterator it = lower_bound(db[l][j][c][f].begin(), db[l][j][c][f].end(), point);

            if (it == db[l][j][c][f].end()) continue;
            cnt += n - (it - db[l][j][c][f].begin());
          }
        }
      }
    }

    answer.push_back(cnt);
  }

  return answer;
}

int mappingInfo(string input) {
  int result = 0;

  if (input == "cpp" || input == "backend" || input == "junior" || input == "chicken")
    result = 0;
  else if (input == "python")
    result = 2;
  else
    result = 1;

  return result;
}

void mappingLanguage(string lang, int& s, int& e) {
  if (lang == "-") {
    s = 0;
    e = 3;
    return;
  } else if (lang == "cpp")
    s = 0;
  else if (lang == "java")
    s = 1;
  else
    s = 2;
  e = s + 1;
}

void mappingJob(string job, int& s, int& e) {
  if (job == "-") {
    s = 0;
    e = 2;
    return;
  } else if (job == "backend")
    s = 0;
  else
    s = 1;
  e = s + 1;
}

void mappingCareer(string career, int& s, int& e) {
  if (career == "-") {
    s = 0;
    e = 2;
    return;
  } else if (career == "junior")
    s = 0;
  else
    s = 1;
  e = s + 1;
}

void mappingFood(string food, int& s, int& e) {
  if (food == "-") {
    s = 0;
    e = 2;
    return;
  } else if (food == "chicken")
    s = 0;
  else
    s = 1;
  e = s + 1;
}