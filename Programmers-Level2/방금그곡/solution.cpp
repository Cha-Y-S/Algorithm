#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string convert(string s, map<string, char> m);

string solution(string m, vector<string> musicinfos) {
  string answer = "";
  pair<int, string> m_info = {0, ""};
  string melody = "";

  map<string, char> sharp;

  // Set custom melody for #
  sharp["C#"] = 'H';
  sharp["D#"] = 'I';
  sharp["F#"] = 'J';
  sharp["G#"] = 'K';
  sharp["A#"] = 'L';

  // Convert melody # -> custom character
  melody = convert(m, sharp);

  for (int i = 0; i < musicinfos.size(); i++) {
    string title, music;
    int s_time, e_time, play_time;

    // Get music's play time from (end time - start time)
    s_time = stoi(musicinfos[i].substr(0, 2)) * 60 + stoi(musicinfos[i].substr(3, 2));
    e_time = stoi(musicinfos[i].substr(6, 2)) * 60 + stoi(musicinfos[i].substr(9, 2));
    play_time = e_time - s_time;

    stringstream st(musicinfos[i].substr(12, musicinfos[i].size() - 12));

    // Get music's title and melody
    getline(st, title, ',');
    getline(st, music);

    // Convert melody # -> custom character
    music = convert(music, sharp);

    // Set melody's length be same as play time
    if (music.size() < play_time) {
      string temp = music;
      for (int i = 0; i < play_time / music.size(); i++)
        temp += music;
      music = temp.substr(0, play_time);
    } else
      music = music.substr(0, play_time);

    // Check whether m is in music's melody
    if (music.find(melody) != string::npos) {
      if (m_info.first < play_time) {
        m_info = {play_time, title};
      }
    }
  }

  answer = m_info.second == "" ? "(None)" : m_info.second;

  return answer;
}

string convert(string s, map<string, char> m) {
  string result = "";

  for (int i = 0; i < s.size(); i++) {
    if (s[i + 1] == '#') {
      result += m[s.substr(i, 2)];
      i++;
    } else
      result += s[i];
  }

  return result;
}