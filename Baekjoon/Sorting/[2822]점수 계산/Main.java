import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class Main {

  public static class Pair implements Comparable<Pair> {
    public int first, second;

    public Pair(int first, int second) {
      super();
      this.first = first;
      this.second = second;
    }

    @Override
    public int compareTo(Pair p) {
      if (this.first == p.first) {
        return Integer.compare(this.second, p.second);
      } else {
        return Integer.compare(p.first, this.first);
      }
    }
  }

  public static Pair[] grade;
  public static int[] number;
  public static int res;

  public static void main(String[] args) throws NumberFormatException, IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    grade = new Pair[8];
    number = new int[5];
    res = 0;

    for (int i = 0; i < 8; i++) {
      int point = Integer.parseInt(br.readLine());

      grade[i] = new Pair(point, i + 1);
    }

    Arrays.sort(grade);

    for (int i = 0; i < 5; i++) {
      res += grade[i].first;
      number[i] = grade[i].second;
    }

    bw.write(res + "\n");

    Arrays.sort(number);

    for (int i = 0; i < 5; i++) {
      bw.write(number[i] + " ");
    }

    bw.flush();
    bw.close();
    br.close();
  }
}
