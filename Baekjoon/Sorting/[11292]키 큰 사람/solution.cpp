#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

struct Student {
  string name;
  double height;
};

vector<Student> students;
string name;
double height;
int N;

bool cmp(Student a, Student b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    cin >> N;

    if (N == 0)
      break;

    students = vector<Student>(N);

    for (int i = 0; i < N; i++) {
      cin >> name >> height;

      students[i].name = name;
      students[i].height = height;
    }

    stable_sort(students.begin(), students.end(), cmp);

    double tmp = students[0].height;

    for (int i = 0; i < N; i++) {
      if (students[i].height != tmp) {
        break;
      }
      cout << students[i].name << " ";
    }
    cout << endl;
  }

  return 0;
}

bool cmp(Student a, Student b) {
  return a.height > b.height;
}
