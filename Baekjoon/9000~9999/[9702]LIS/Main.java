import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;

public class Main {

  public static int[] seq;
  public static ArrayList<Integer> lis;
  public static int T, N, res;

  public static int lower_bound(int value) {
    int low = 0;
    int high = lis.size();

    while (low < high) {
      int mid = (low + high) / 2;

      if (value < lis.get(mid)) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }

    return high;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    T = Integer.parseInt(br.readLine());

    for (int t = 0; t < T; t++) {
      N = Integer.parseInt(br.readLine());
      seq = new int[N];
      res = 0;

      for (int i = 0; i < N; i++) {
        seq[i] = Integer.parseInt(br.readLine());
      }

      for (int i = 0; i < N; i++) {
        lis = new ArrayList<>();
        for (int j = i; j < N; j++) {
          int idx = lower_bound(seq[j]);

          if (idx == lis.size()) {
            lis.add(seq[j]);
          } else {
            lis.set(idx, seq[j]);
          }
          res += lis.size();
        }
      }

      bw.write("Case #" + (t + 1) + ": " + res + "\n");
    }

    bw.flush();
    bw.close();
    br.close();
  }
}
