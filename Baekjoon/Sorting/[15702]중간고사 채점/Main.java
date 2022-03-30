import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

  public static class Pair implements Comparable<Pair> {
    int id;
    int grade;

    Pair(int id, int grade) {
      this.id = id;
      this.grade = grade;
    }

    @Override
    public int compareTo(Pair a) {
      if (this.grade != a.grade) {
        return Integer.compare(a.grade, this.grade);
      } else {
        return Integer.compare(this.id, a.id);
      }
    }

  }

  public static Pair[] info;
  public static int[] point;
  public static int N, M, st_id, st_grade;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    point = new int[N];
    info = new Pair[M];

    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < N; i++) {
      point[i] = Integer.parseInt(st.nextToken());
    }

    for (int i = 0; i < M; i++) {
      String tmp;
      st_grade = 0;

      st = new StringTokenizer(br.readLine());
      st_id = Integer.parseInt(st.nextToken());

      for (int j = 0; j < N; j++) {
        tmp = st.nextToken();

        if (tmp.compareTo("O") == 0)
          st_grade += point[j];
      }

      info[i] = new Pair(st_id, st_grade);
    }

    Arrays.sort(info);

    bw.write(info[0].id + " " + info[0].grade + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}