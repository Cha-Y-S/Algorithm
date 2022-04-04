import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

  public static class Student implements Comparable<Student> {
    int korean;
    int english;
    int math;
    String name;

    public Student(int korean, int english, int math, String name) {
      this.korean = korean;
      this.english = english;
      this.math = math;
      this.name = name;
    }

    @Override
    public int compareTo(Student a) {
      if (this.korean != a.korean) {
        return Integer.compare(a.korean, this.korean);
      } else {
        if (this.english != a.english) {
          return Integer.compare(this.english, a.english);
        } else {
          if (this.math != a.math) {
            return Integer.compare(a.math, this.math);
          } else {
            return this.name.compareTo(a.name);
          }
        }
      }
    }
  }

  public static Student[] students;
  public static int N;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    N = Integer.parseInt(br.readLine());

    students = new Student[N];

    for (int i = 0; i < N; i++) {
      StringTokenizer st = new StringTokenizer(br.readLine());

      String n;
      int k, e, m;

      n = st.nextToken();
      k = Integer.parseInt(st.nextToken());
      e = Integer.parseInt(st.nextToken());
      m = Integer.parseInt(st.nextToken());

      students[i] = new Student(k, e, m, n);
    }

    Arrays.sort(students);

    for (int i = 0; i < N; i++) {
      bw.write(students[i].name + "\n");
    }

    bw.flush();
    bw.close();
    br.close();
  }
}
