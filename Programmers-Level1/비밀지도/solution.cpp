#include <cmath>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
  vector<string> answer;
  vector<string> map1;
  vector<string> map2;

  for (int i = 0; i < n; i++) {
    int temp1 = arr1[i];
    int temp2 = arr2[i];
    string tString1;
    string tString2;
    int bit = n;

    while (bit-- != 0) {
      int base = pow(2, bit);
      tString1.push_back((temp1 / base) + '0');
      tString2.push_back((temp2 / base) + '0');
      temp1 %= base;
      temp2 %= base;
    }
    map1.push_back(tString1);
    map2.push_back(tString2);
  };

  for (int i = 0; i < n; i++) {
    string tString;
    for (int j = 0; j < n; j++) {
      if (map1[i][j] == '1' || map2[i][j] == '1') {
        tString.push_back('#');
      } else {
        tString.push_back(' ');
      }
    }
    answer.push_back(tString);
  }

  return answer;
}