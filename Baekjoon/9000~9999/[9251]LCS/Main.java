import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

  public static int[][] dp;
  public static String A, B;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    A = br.readLine();
    B = br.readLine();

    dp = new int[A.length() + 1][B.length() + 1];

    for (int i = 0; i < dp.length; i++) {
      for (int j = 0; j < dp[i].length; j++) {
        if (i == 0 || j == 0) {
          dp[i][j] = 0;
        } else if (A.charAt(i - 1) == B.charAt(j - 1)) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    bw.write(dp[A.length()][B.length()] + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}