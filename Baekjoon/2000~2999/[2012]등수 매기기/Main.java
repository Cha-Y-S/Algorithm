import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class Main {

  public static int[] grade;
  public static long res;
  public static int N;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    N = Integer.parseInt(br.readLine());

    grade = new int[N];
    res = 0;

    for (int i = 0; i < N; i++) {
      grade[i] = Integer.parseInt(br.readLine());
    }

    Arrays.sort(grade);

    for (int i = 0; i < N; i++) {
      res += Math.abs(grade[i] - (i + 1));
    }

    bw.write(res + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}