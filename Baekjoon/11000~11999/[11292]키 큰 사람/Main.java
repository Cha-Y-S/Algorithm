import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

  public static class Student implements Comparable<Student> {
    String name;
    double height;

    Student(String name, double height) {
      this.name = name;
      this.height = height;
    }

    public int compareTo(Student a) {
      return Double.compare(a.height, this.height);
    }
  }

  public static ArrayList<Student> students;
  public static String name;
  public static double height;
  public static int N;

  public static void main(String[] args) throws NumberFormatException, IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    while (true) {
      N = Integer.parseInt(br.readLine());
      students = new ArrayList<Student>();

      if (N == 0) {
        break;
      }

      for (int i = 0; i < N; i++) {
        StringTokenizer st = new StringTokenizer(br.readLine());

        name = st.nextToken();
        height = Double.parseDouble(st.nextToken());

        students.add(new Student(name, height));
      }

      Collections.sort(students);

      double tmp = students.get(0).height;

      for (int i = 0; i < N; i++) {
        if (tmp != students.get(i).height) {
          break;
        }
        bw.write(students.get(i).name + " ");
      }
      bw.write("\n");
    }

    bw.flush();
    bw.close();
    br.close();
  }
}
