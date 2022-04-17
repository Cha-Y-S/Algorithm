import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
  public static int[] seq, dp;
  public static int N;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    N = Integer.parseInt(br.readLine());

    seq = new int[N];
    dp = new int[N];

    StringTokenizer st = new StringTokenizer(br.readLine());

    for (int i = 0; i < N; i++) {
      seq[i] = Integer.parseInt(st.nextToken());
      dp[i] = seq[i];
    }

    for (int i = 1; i < N; i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (seq[i] > seq[j]) {
          dp[i] = Math.max(dp[i], dp[j] + seq[i]);
        }
      }
    }

    bw.write(Arrays.stream(dp).max().getAsInt() + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}
