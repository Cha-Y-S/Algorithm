import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

  public static class Info implements Comparable<Info> {
    int nation;
    int student;
    int point;

    Info(int nation, int student, int point) {
      super();
      this.nation = nation;
      this.student = student;
      this.point = point;
    }

    @Override
    public int compareTo(Info i) {
      return Integer.compare(i.point, this.point);
    }
  }

  public static Info[] grade;
  public static HashMap<Integer, Integer> m;
  public static int N;

  public static void main(String[] args) throws NumberFormatException, IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    N = Integer.parseInt(br.readLine());
    m = new HashMap<Integer, Integer>();

    grade = new Info[N];

    for (int i = 0; i < N; i++) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      int nation, student, point;

      nation = Integer.parseInt(st.nextToken());
      student = Integer.parseInt(st.nextToken());
      point = Integer.parseInt(st.nextToken());

      grade[i] = new Info(nation, student, point);
    }

    Arrays.sort(grade);

    int i = 0;
    int cnt = 0;

    while (cnt < 3) {
      if (m.containsKey(grade[i].nation)) {
        if (m.get(grade[i].nation) == 2) {
          i++;
          continue;
        }
        m.put(grade[i].nation, 2);
        cnt++;
        bw.write(grade[i].nation + " " + grade[i].student + "\n");

      } else {
        m.put(grade[i].nation, 1);
        cnt++;
        bw.write(grade[i].nation + " " + grade[i].student + "\n");
      }
      i++;
    }

    bw.flush();
    bw.close();
    br.close();
  }
}