import java.util.Scanner;

public class Main{

  public static int[] dp;
  public static int N;
  public static final int MAX = 1_000_001;
  public static final int MOD = 1_000_000_007;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    N = sc.nextInt();

    dp = new int[MAX];

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= N; i++)
      dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    
    System.out.println(dp[N]);
  }
}