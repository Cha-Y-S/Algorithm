#include <iostream>
#include <string>
#include <vector>

using namespace std;

void zipByQuad(vector<vector<int>> &arr, int &z, int &o, int x, int y, int s);

vector<int> solution(vector<vector<int>> arr) {
  vector<int> answer;
  int zero_cnt = 0;
  int one_cnt = 0;

  zipByQuad(arr, zero_cnt, one_cnt, 0, 0, arr.size());

  answer = {zero_cnt, one_cnt};

  return answer;
}

void zipByQuad(vector<vector<int>> &arr, int &z, int &o, int x, int y, int s) {
  // Set standard number
  int standard = arr[x][y];

  for (int i = x; i < x + s; i++) {
    for (int j = y; j < y + s; j++) {
      // If there is different number compared with standard
      if (arr[i][j] != standard) {
        // Divided into 4 areas
        zipByQuad(arr, z, o, x, y, s / 2);
        zipByQuad(arr, z, o, x, y + s / 2, s / 2);
        zipByQuad(arr, z, o, x + s / 2, y, s / 2);
        zipByQuad(arr, z, o, x + s / 2, y + s / 2, s / 2);
        return;
      }
    }
  }

  if (!standard)
    z++;
  else
    o++;
}