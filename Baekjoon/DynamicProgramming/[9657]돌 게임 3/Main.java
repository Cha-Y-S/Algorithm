import java.util.Scanner;

public class Main {

  public static final int MAX = 1001;
  public static int dp[];
  public static int N;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    N = sc.nextInt();

    dp = new int[MAX];

    dp[1] = dp[3] = dp[4] = 1;
    dp[2] = 0;

    for (int i = 5; i <= N; i++) {
      if (Math.min(dp[i - 1], Math.min(dp[i - 3], dp[i - 4])) == 1)
        dp[i] = 0;
      else
        dp[i] = 1;
    }

    System.out.println(dp[N] == 1 ? "SK" : "CY");

    sc.close();
  }
}
