import java.util.Scanner;

public class Main {

  public static int[] dp;
  public static int N;
  public static final int MAX = 100_001;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    N = sc.nextInt();

    dp = new int[MAX];

    dp[1] = dp[2] = dp[5] = dp[7] = 1;
    dp[3] = dp[4] = dp[6] = 2;

    for(int i= 8; i <= N; i++)
      dp[i] = Math.min(dp[i-1] + 1, Math.min(dp[i-2] + 1, Math.min(dp[i-5] + 1, dp[i-7] + 1)));

    System.out.println(dp[N]);

    sc.close();
  }
}
