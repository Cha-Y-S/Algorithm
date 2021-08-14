#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string convertNBase(int n, int t, int m, int p);

string solution(int n, int t, int m, int p) {
  string answer = "";
  string convert = "";

  convert = convertNBase(n, t, m, p);

  for (int i = p - 1; i < (t - 1) * m + p; i += m) {
    answer.push_back(convert[i]);
  }

  return answer;
}

string convertNBase(int n, int t, int m, int p) {
  string result = "";
  vector<char> more_than_10 = {'A', 'B', 'C', 'D', 'E', 'F'};
  int i = 0;

  // Looping until sequence of n base number's size is (t - 1) * m + p
  while (result.size() < (t - 1) * m + p) {
    string temp = "";
    int target = i;
    int j = 0;

    // Exception when target number is 0
    if (target == 0) {
      temp.push_back('0');
      result += temp;
      i++;
      continue;
    }

    // Get digit of target number (Get amount of bit)
    while (pow(n, j) <= target) {
      j++;
    }

    // Get converted number by n base
    while (j-- != 0) {
      int t_number = target / pow(n, j);
      temp.push_back(t_number >= 10 ? more_than_10[t_number % 10] : t_number + '0');
      target = target % (int)pow(n, j);
    }

    result += temp;
    i++;
  }

  return result;
}