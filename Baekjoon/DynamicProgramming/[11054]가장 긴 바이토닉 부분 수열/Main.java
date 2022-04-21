import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

  public static int[] seq, rseq, dp_asc, dp_desc;
  public static int N;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    N = Integer.parseInt(br.readLine());

    seq = new int[N];
    rseq = new int[N];
    dp_asc = new int[N];
    dp_desc = new int[N];

    Arrays.fill(dp_asc, 1);
    Arrays.fill(dp_desc, 1);

    StringTokenizer st = new StringTokenizer(br.readLine());

    for (int i = 0; i < N; i++) {
      seq[i] = Integer.parseInt(st.nextToken());
      rseq[N - i - 1] = seq[i];
    }

    for (int i = 1; i < N; i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (seq[i] > seq[j]) {
          dp_asc[i] = Math.max(dp_asc[i], dp_asc[j] + 1);
        }

        if (rseq[i] > rseq[j]) {
          dp_desc[i] = Math.max(dp_desc[i], dp_desc[j] + 1);
        }
      }
    }

    int lbs_size = 0;

    for (int i = 0; i < N; i++) {
      lbs_size = Math.max(lbs_size, dp_asc[i] + dp_desc[N - i - 1] - 1);
    }

    bw.write(lbs_size + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}