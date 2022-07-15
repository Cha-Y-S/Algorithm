import java.util.Scanner;

public class Main {

  public static int[] dp;
  public static int N;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    N = sc.nextInt();

    dp = new int[11];
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 3;

    for (int i = 4; i <= N; i++) {
      int a = i / 2;
      int b = i - (i / 2);

      dp[i] = a * b + dp[a] + dp[b];
    }

    System.out.println(dp[N]);
  }
}
