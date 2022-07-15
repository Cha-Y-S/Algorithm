import java.util.Scanner;

public class Main {
  public static int[][] dp;
  public static int R, C, W;
  public static int res;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    dp = new int[30][];

    for (int i = 0; i < 30; i++) {
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

    R = sc.nextInt();
    C = sc.nextInt();
    W = sc.nextInt();
    res = 0;

    for (int i = R - 1; i < R + W - 1; i++) {
      for (int j = C - 1; j < C + i - R + 1; j++)
        res += dp[i][j];
    }

    System.out.println(res);
  }
}