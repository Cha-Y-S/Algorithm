#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void initTable(vector<map<string, int>> &t, vector<string> jobs, string s);

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
  string answer = "";
  vector<string> jobs = {"SI", "CONTENTS", "HARDWARE", "PORTAL", "GAME"};
  vector<map<string, int>> table_map(5);
  vector<pair<string, int>> lang_pref;
  int max = 0;

  // Parse information from parameters
  for (int i = 0; i < table.size(); i++)
    initTable(table_map, jobs, table[i]);

  for (int i = 0; i < languages.size(); i++)
    lang_pref.push_back({languages[i], preference[i]});

  // Get job that has highest point
  for (int i = 0; i < table_map.size(); i++) {
    int sum = 0;

    for (int j = 0; j < lang_pref.size(); j++)
      sum += table_map[i][lang_pref[j].first] * lang_pref[j].second;

    if (max < sum) {
      max = sum;
      answer = jobs[i];
    } else if (max == sum) {
      // if jobs[i] has same point with answer, get alphabetical first job
      answer = jobs[i] < answer ? jobs[i] : answer;
    }
  }

  return answer;
}

void initTable(vector<map<string, int>> &t, vector<string> jobs, string s) {
  string job, language;
  stringstream st;
  int job_index;
  int point = 5;

  st.str(s);

  st >> job;

  for (int i = 0; i < jobs.size(); i++) {
    if (job == jobs[i]) {
      job_index = i;
      break;
    }
  }

  while (!st.eof()) {
    st >> language;

    t[job_index][language] = point--;
  }
}