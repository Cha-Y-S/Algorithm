import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

  public static ArrayList<Integer> res;
  public static int N, seq;

  public static int lower_bound(int value) {
    int low = 0;
    int high = res.size();

    while (low < high) {
      int mid = (low + high) / 2;

      if (value <= res.get(mid)) {
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

    N = Integer.parseInt(br.readLine());
    res = new ArrayList<Integer>();
    res.add(1_000_001);

    StringTokenizer st = new StringTokenizer(br.readLine());
    for (int i = 0; i < N; i++) {
      seq = Integer.parseInt(st.nextToken());

      int idx = lower_bound(seq);

      if (idx == res.size()) {
        res.add(seq);
      } else {
        res.set(idx, seq);
      }
    }

    bw.write(res.size() + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}