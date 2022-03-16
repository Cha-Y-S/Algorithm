import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {

  public static BigInteger[][] dp;
  public static int N, M;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    dp = new BigInteger[N + 1][];

    for (int i = 0; i <= N; i++) {
      dp[i] = new BigInteger[i + 1];
    }

    dp[0][0] = dp[1][0] = dp[1][1] = new BigInteger("1");

    for (int i = 2; i <= N; i++) {
      for (int j = 0; j < dp[i].length; j++) {
        if (i == j || j == 0)
          dp[i][j] = new BigInteger("1");
        else
          dp[i][j] = dp[i - 1][j - 1].add(dp[i - 1][j]);
      }
    }

    bw.write(dp[N][M] + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}
