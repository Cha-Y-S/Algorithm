#include <algorithm>
#include <climits>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
  string answer = "";
  vector<int> numbers;
  stringstream st;
  int num, min, max;

  st.str(s);

  while (st >> num)
    numbers.push_back(num);

  min = *min_element(numbers.begin(), numbers.end());
  max = *max_element(numbers.begin(), numbers.end());

  answer += to_string(min) + " " + to_string(max);

  return answer;
}