#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool doKeepingDistance(vector<vector<int>> wr);
bool isInside(int x, int y, int x_limit, int y_limit);

vector<int> solution(vector<vector<string>> places) {
  vector<int> answer;

  for (int i = 0; i < places.size(); i++) {
    /*
      0: table
      1: person
      2: partition
    */
    vector<vector<int>> wr;

    for (int j = 0; j < places[i].size(); j++) {
      vector<int> temp;
      for (int k = 0; k < places[i][j].size(); k++) {
        if (places[i][j][k] == 'P')
          temp.push_back(1);
        else if (places[i][j][k] == 'O')
          temp.push_back(0);
        else
          temp.push_back(2);
      }
      wr.push_back(temp);
    }

    answer.push_back(doKeepingDistance(wr));
  }

  return answer;
}

bool doKeepingDistance(vector<vector<int>> wr) {
  bool answer = true;

  vector<pair<int, int>> dir1_4 = {make_pair(0, 1), make_pair(1, 0)};
  vector<pair<int, int>> dir2_4 = {make_pair(0, 2), make_pair(2, 0)};
  vector<pair<int, int>> diagonal = {make_pair(1, 1), make_pair(1, -1)};

  for (int i = 0; i < wr.size(); i++) {
    for (int j = 0; j < wr[i].size(); j++) {
      if (wr[i][j] == 1) {
        int cx = i;
        int cy = j;

        // Check that other person is inside distance of 1 manhattan
        for (int k = 0; k < dir1_4.size(); k++) {
          int nx = cx + dir1_4[k].first;
          int ny = cy + dir1_4[k].second;

          if (isInside(nx, ny, wr.size(), wr[nx].size()) && wr[nx][ny] == 1) {
            answer = false;
            break;
          }
        }

        // Check that partition is between wr[cx][cy] and  other person who is inside distance of 2 manhattan
        for (int k = 0; k < dir2_4.size(); k++) {
          int nx = cx + dir2_4[k].first;
          int ny = cy + dir2_4[k].second;

          if (isInside(nx, ny, wr.size(), wr[nx].size()) && wr[nx][ny] == 1 && !(wr[(cx + nx) / 2][(cy + ny) / 2] == 2)) {
            answer = false;
            break;
          }
        }

        // Check that partition is between wr[cx][cy] and diagonal person
        for (int k = 0; k < diagonal.size(); k++) {
          int nx = cx + diagonal[k].first;
          int ny = cy + diagonal[k].second;

          if (isInside(nx, ny, wr.size(), wr[nx].size()) && wr[nx][ny] == 1 && !(wr[nx][cy] == 2 && wr[cx][ny] == 2)) {
            answer = false;
            break;
          }
        }
      }
    }
    if (!answer) break;
  }

  return answer;
}

bool isInside(int x, int y, int x_limit, int y_limit) {
  return (0 <= x && x < x_limit) && (0 <= y && y < y_limit);
}