#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Applicant {
  string lang;
  string job;
  string career;
  string food;
  int point;
};

void printApplicant(vector<Applicant> app);

vector<int> solution(vector<string> info, vector<string> query) {
  vector<int> answer;
  vector<Applicant> app;
  stringstream st;

  for (int i = 0; i < info.size(); i++) {
    Applicant person;
    st.str(info[i]);
    st >> person.lang >> person.job >> person.career >> person.food >> person.point;
    app.push_back(person);
    st.clear();
  }

  // printApplicant(app);

  for (int i = 0; i < query.size(); i++) {
    st.clear();
    vector<Applicant> pass;
    Applicant cond;
    string temp;
    st.str(query[i]);
    st >> cond.lang >> temp >> cond.job >> temp >> cond.career >> temp >> cond.food >> cond.point;

    if (cond.lang == "-")
      pass = app;
    else {
      for (int j = 0; j < app.size(); j++) {
        if (cond.lang == app[j].lang) pass.push_back(app[j]);
      }
    }

    // printApplicant(pass);

    if (pass.size() == 0) {
      answer.push_back(0);
      continue;
    }

    if (cond.job != "-") {
      for (int j = 0; j < pass.size(); j++) {
        if (cond.job != pass[j].job) {
          pass.erase(pass.begin() + j, pass.begin() + j + 1);
          j--;
        }
      }
    }

    if (pass.size() == 0) {
      answer.push_back(0);
      continue;
    }

    if (cond.career != "-") {
      for (int j = 0; j < pass.size(); j++) {
        if (cond.career != pass[j].career) {
          pass.erase(pass.begin() + j, pass.begin() + j + 1);
          j--;
        }
      }
    }

    if (pass.size() == 0) {
      answer.push_back(0);
      continue;
    }

    if (cond.food != "-") {
      for (int j = 0; j < pass.size(); j++) {
        if (cond.food != pass[j].food) {
          pass.erase(pass.begin() + j, pass.begin() + j + 1);
          j--;
        }
      }
    }

    // cout << "food" << endl;
    // printApplicant(pass);

    if (pass.size() == 0) {
      answer.push_back(0);
      continue;
    }

    for (int j = 0; j < pass.size(); j++) {
      if (cond.point > pass[j].point) {
        pass.erase(pass.begin() + j, pass.begin() + j + 1);
        j--;
      }
    }

    if (pass.size() == 0) {
      answer.push_back(0);
      continue;
    }

    answer.push_back(pass.size());
  }

  return answer;
}

void printApplicant(vector<Applicant> app) {
  cout << "Lang\tJob\tCareer\tFood\tPoint" << endl;
  for (int i = 0; i < app.size(); i++) {
    cout << app[i].lang << "\t" << app[i].job << "\t" << app[i].career << "\t" << app[i].food << "\t" << app[i].point << endl;
  }
  cout << endl;
}