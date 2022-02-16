import java.util.Scanner;

public class Main {

  public static int[][] dp;
  public static int N, K;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    N = sc.nextInt();
    K = sc.nextInt();

    dp = new int[N][];

    for (int i = 0; i < N; i++) {
      dp[i] = new int[i + 1];

      for (int j = 0; j < dp[i].length; j++) {
        if (j == 0) {
          dp[i][j] = 1;
          continue;
        }
        if (j == dp[i].length - 1) {
          dp[i][j] = 1;
          break;
        }
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
      }
    }

    System.out.println(dp[N - 1][K - 1]);
  }
}