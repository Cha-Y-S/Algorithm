import java.util.Scanner;

public class Main {

  public static int[] dp;
  public static int H, Y;

  public static int getBenefitA(int x) {
    return (int) (x * 1.05);
  }

  public static int getBenefitB(int x){
    return (int)(x * 1.2);
  }

  public static int getBenefitC(int x){
    return (int)(x * 1.35);
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    H = sc.nextInt();
    Y = sc.nextInt();


    dp = new int[Y + 1];
    dp[0] = H;
    
    for(int i = 1; i <= Y; i++){
      if(i >= 5)
        dp[i] = Math.max(getBenefitA(dp[i - 1]), Math.max(getBenefitB(dp[i - 3]), getBenefitC(dp[i - 5])));
      else if(i >= 3)
        dp[i] = Math.max(getBenefitA(dp[i - 1]), getBenefitB(dp[i - 3]));
      else
        dp[i] = getBenefitA(dp[i - 1]);
    }

    System.out.println(dp[Y]);
  }
}