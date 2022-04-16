import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

  public static class Pair {
    int step;
    int prev;

    Pair(int step, int prev) {
      this.step = step;
      this.prev = prev;
    }
  }

  public static Pair[] dp;
  public static int N;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    N = Integer.parseInt(br.readLine());

    dp = new Pair[N + 3];

    dp[1] = new Pair(0, 0);
    dp[2] = new Pair(1, 1);
    dp[3] = new Pair(1, 1);

    for (int i = 4; i <= N; i++) {
      dp[i] = new Pair(dp[i - 1].step + 1, i - 1);

      if (i % 2 == 0) {
        if (dp[i].step > dp[i / 2].step + 1) {
          dp[i] = new Pair(dp[i / 2].step + 1, i / 2);
        }
      }

      if (i % 3 == 0) {
        if (dp[i].step > dp[i / 3].step + 1) {
          dp[i] = new Pair(dp[i / 3].step + 1, i / 3);
        }
      }
    }

    bw.write(dp[N].step + "\n");

    int idx = N;

    while (idx > 0) {
      bw.write(idx + " ");

      idx = dp[idx].prev;
    }

    bw.write("\n");

    bw.flush();
    bw.close();
    br.close();
  }
}
