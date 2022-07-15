#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

struct Student {
  int korean;
  int english;
  int math;
  string name;
};

vector<Student> students;
int N;

int cmp(Student a, Student b) {
  if (a.korean != b.korean) {
    return a.korean > b.korean;
  } else {
    if (a.english != b.english) {
      return a.english < b.english;
    } else {
      if (a.math != b.math) {
        return a.math > b.math;
      } else {
        return a.name < b.name;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  students = vector<Student>(N);

  for (int i = 0; i < N; i++) {
    int k, e, m;
    string n;

    cin >> n >> k >> e >> m;

    students[i].korean = k;
    students[i].english = e;
    students[i].math = m;
    students[i].name = n;
  }

  sort(students.begin(), students.end(), cmp);

  for (int i = 0; i < N; i++) {
    cout << students[i].name << endl;
  }

  return 0;
}