import java.util.Scanner;

public class Main{

  public static double[] dp;
  public static double res;
  public static int N;
  
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    N = sc.nextInt();

    dp = new double[N];

    for(int i = 0; i < N; i++)
      dp[i] = sc.nextDouble();

    res = dp[0];

    for (int i = 1; i < N; i++) {
      dp[i] = Math.max(dp[i], dp[i - 1] * dp[i]);
      res = Math.max(res, dp[i]);
    }

    System.out.println(String.format("%.3f", res));
  }
}