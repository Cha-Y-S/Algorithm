import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

  public static class Pair implements Comparable<Pair> {
    public int first;
    public int second;

    Pair(int first, int second) {
      this.first = first;
      this.second = second;
    }

    @Override
    public int compareTo(Pair other) {
      return Integer.compare(this.first, other.first);
    }
  }

  public static Pair[] pole;
  public static int[] dp;
  public static int N;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    N = Integer.parseInt(br.readLine());

    pole = new Pair[N];
    dp = new int[N];

    Arrays.fill(dp, 1);

    for (int i = 0; i < N; i++) {
      StringTokenizer st = new StringTokenizer(br.readLine());

      pole[i] = new Pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
    }

    Arrays.sort(pole);

    for (int i = 1; i < N; i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (pole[i].second > pole[j].second) {
          dp[i] = Math.max(dp[i], dp[j] + 1);
        }
      }
    }

    bw.write((N - Arrays.stream(dp).max().getAsInt()) + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}
