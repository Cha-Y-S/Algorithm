import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

  public static int[][] sticker, dp;
  public static int T, N;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    T = Integer.parseInt(br.readLine());

    while (T-- != 0) {
      N = Integer.parseInt(br.readLine());

      sticker = new int[2][N];
      dp = new int[2][N];

      for (int i = 0; i < 2; i++) {
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int j = 0; j < N; j++) {
          sticker[i][j] = Integer.parseInt(st.nextToken());
        }
      }

      dp[0][0] = sticker[0][0];
      dp[1][0] = sticker[1][0];

      if (N > 1) {
        dp[0][1] = sticker[0][1] + dp[1][0];
        dp[1][1] = sticker[1][1] + dp[0][0];
      }

      for (int i = 2; i < N; i++) {
        dp[0][i] = sticker[0][i] + Math.max(dp[1][i - 1], dp[1][i - 2]);
        dp[1][i] = sticker[1][i] + Math.max(dp[0][i - 1], dp[0][i - 2]);
      }

      bw.write(Math.max(dp[0][N - 1], dp[1][N - 1]) + "\n");
    }

    bw.flush();
    bw.close();
    br.close();
  }
}
