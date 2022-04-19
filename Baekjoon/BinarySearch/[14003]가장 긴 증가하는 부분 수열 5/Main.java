import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

  public static ArrayList<Integer> lis;
  public static int[] A, seq, res;
  public static int N;

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

    N = Integer.parseInt(br.readLine());
    A = new int[N];
    seq = new int[N];
    lis = new ArrayList<>();

    StringTokenizer st = new StringTokenizer(br.readLine());

    for (int i = 0; i < N; i++) {
      A[i] = Integer.parseInt(st.nextToken());

      int idx = lower_bound(A[i]);

      if (idx == lis.size()) {
        lis.add(A[i]);
      } else {
        lis.set(idx, A[i]);
      }

      seq[i] = idx;
    }

    int target = lis.size() - 1;
    res = new int[lis.size()];

    for (int i = seq.length - 1; i >= 0; i--) {
      if (seq[i] == target) {
        res[seq[i]] = A[i];
        target--;
      }
    }

    bw.write(res.length + "\n");

    for (int n : res) {
      bw.write(n + " ");
    }
    bw.write("\n");

    bw.flush();
    bw.close();
    br.close();
  }
}
