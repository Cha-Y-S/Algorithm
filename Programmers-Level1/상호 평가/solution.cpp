#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<vector<int>> scores) {
  string answer = "";
  vector<double> avg;
  int n = scores.size();

  for (int c = 0; c < n; c++) {
    vector<double> point;

    // Initialize self point
    for (int r = 0; r < n; r++) {
      point.push_back(scores[r][c]);
    }

    bool isUnique = true;

    // Check whether self point is unique max/min
    if (point[c] == *max_element(point.begin(), point.end()) || point[c] == *min_element(point.begin(), point.end())) {
      for (int i = 0; i < point.size(); i++) {
        if (i != c && point[i] == point[c]) {
          isUnique = false;
        }
      }
    } else {
      isUnique = false;
    }

    double grade = 0;

    for (int i = 0; i < point.size(); i++) {
      // If there is unique max / min, except that
      if (isUnique && c == i) continue;
      grade += point[i];
    }

    // Get self average by dividing by n or n -1
    grade = isUnique ? grade / (n - 1) : grade / n;

    // Get self grade
    if (grade >= 90)
      answer.push_back('A');
    else if (grade >= 80)
      answer.push_back('B');
    else if (grade >= 70)
      answer.push_back('C');
    else if (grade >= 50)
      answer.push_back('D');
    else
      answer.push_back('F');
  }

  return answer;
}