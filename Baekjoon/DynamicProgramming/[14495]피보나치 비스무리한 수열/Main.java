import java.util.Scanner;

public class Main {

  public static long[] dp;
  public static final int MAX = 117;
  public static int N;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    N = sc.nextInt();

    dp = new long[MAX];

    dp[1] = dp[2] = dp[3] = 1;

    for (int i = 4; i <= N; i++)
      dp[i] = dp[i - 1] + dp[i - 3];

    System.out.println(dp[N]);
  }
}