import java.util.Scanner;

public class Main {

  public static final int INF = 987_654_321;
  public static int[][][] dp;
  public static int[][] matrix;
  public static int N, M, res;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    N = sc.nextInt();
    M = sc.nextInt();

    dp = new int[N + 1][M + 1][3];
    matrix = new int[N + 1][M + 1];
    res = INF;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        matrix[i][j] = sc.nextInt();
      }
    }

    for (int j = 0; j < M; j++) {
      for (int k = 0; k < 3; k++) {
        dp[0][j][k] = matrix[0][j];
      }
    }

    for (int i = 1; i <= N; i++) {
      for (int j = 0; j < M; j++) {
        if (j == 0) {
          dp[i][j][1] = dp[i - 1][j + 1][0] + matrix[i][j];
          dp[i][j][2] = Math.min(dp[i - 1][j + 1][0], dp[i - 1][j][1]) + matrix[i][j];
        } else if (j == M - 1) {
          dp[i][j][0] = Math.min(dp[i - 1][j][1], dp[i - 1][j - 1][2]) + matrix[i][j];
          dp[i][j][1] = dp[i - 1][j - 1][2] + matrix[i][j];
        } else {
          dp[i][j][0] = Math.min(dp[i - 1][j][1], dp[i - 1][j - 1][2]) + matrix[i][j];
          dp[i][j][1] = Math.min(dp[i - 1][j + 1][0], dp[i - 1][j - 1][2]) + matrix[i][j];
          dp[i][j][2] = Math.min(dp[i - 1][j + 1][0], dp[i - 1][j][1]) + matrix[i][j];
        }
      }
    }

    for (int j = 0; j < M; j++) {
      for (int k = 0; k < 3; k++) {
        if (dp[N][j][k] == 0)
          continue;
        res = Math.min(res, dp[N][j][k]);
      }
    }

    System.out.println(res);

    sc.close();
  }
}