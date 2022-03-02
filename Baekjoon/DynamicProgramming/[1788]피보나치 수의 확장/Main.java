import java.util.Scanner;

public class Main {

  public static int[] dp;
  public static int N, tmp;
  public static final int MAX = 1_000_001;
  public static final int MOD = 1_000_000_000;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    N = sc.nextInt();

    dp = new int[MAX];
    tmp = Math.abs(N);
    dp[1] = 1;

    for (int i = 2; i <= tmp; i++)
      dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;

    System.out.println(N == 0 ? 0 : (N < 0 && tmp % 2 == 0 ? -1 : 1));
    System.out.println(dp[tmp]);

    sc.close();
  }
}