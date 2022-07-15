import java.util.Scanner;
import java.util.Arrays;

public class Main {

  public static int[] dp;
  public static int N;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    N = sc.nextInt();

    dp = new int[100_001];
    Arrays.fill(dp, 50_001);
    
    dp[2] = 1;
    dp[4] = 2;
    dp[5] = 1;

    for(int i = 6; i <= N; i++)
      dp[i] = dp[i-2] > dp[i-5] ? dp[i-5] + 1: dp[i-2] + 1;

    System.out.println((dp[N] > 50_000 ? -1 : dp[N]));
  }
}