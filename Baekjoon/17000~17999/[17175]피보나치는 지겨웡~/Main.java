import java.util.Scanner;

public class Main {

  public static final int MAX = 51;
  public static final int MOD = 1_000_000_007;
  public static int[] dp;
  public static int N;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    N = sc.nextInt();

    dp = new int[MAX];

    dp[0] = dp[1] = 1;

    for (int i = 2; i <= N; i++)
      dp[i] = (dp[i - 1] + dp[i - 2] + 1) % MOD;

    System.out.println(dp[N]);

    sc.close();
  }
}