import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

  public static ArrayList<Integer> lis;
  public static int T, N, K, num;

  public static int lower_bound(int value) {
    int low = 0;
    int high = lis.size();

    while (low < high) {
      int mid = (low + high) / 2;

      if (value <= lis.get(mid)) {
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
      bw.write("Case #" + (t + 1) + "\n");

      lis = new ArrayList<>();

      StringTokenizer st = new StringTokenizer(br.readLine());

      N = Integer.parseInt(st.nextToken());
      K = Integer.parseInt(st.nextToken());

      st = new StringTokenizer(br.readLine());
      for (int i = 0; i < N; i++) {
        num = Integer.parseInt(st.nextToken());

        int idx = lower_bound(num);

        if (idx == lis.size()) {
          lis.add(num);
        } else {
          lis.set(idx, num);
        }
      }

      bw.write((K <= lis.size() ? 1 : 0) + "\n");
    }

    bw.flush();
    bw.close();
    br.close();
  }
}
