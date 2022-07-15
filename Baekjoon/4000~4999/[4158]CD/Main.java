import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

  public static int[] CD;
  public static int N, M, num, res;

  public static int lower_bound(int value) {
    int low = 0;
    int high = CD.length;

    while (low < high) {
      int mid = (low + high) / 2;

      if (value <= CD[mid]) {
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

    while (true) {
      StringTokenizer st = new StringTokenizer(br.readLine());

      N = Integer.parseInt(st.nextToken());
      M = Integer.parseInt(st.nextToken());

      if (N == 0 && M == 0)
        break;
      if (N == 0 || M == 0) {
        bw.write("0\n");
        continue;
      }

      CD = new int[N];
      res = 0;

      for (int i = 0; i < N; i++) {
        CD[i] = Integer.parseInt(br.readLine());
      }

      for (int i = 0; i < M; i++) {
        num = Integer.parseInt(br.readLine());

        int idx = lower_bound(num);

        if (idx == CD.length)
          continue;

        if (num == CD[idx]) {
          res++;
        }
      }

      bw.write(res + "\n");
    }
    bw.flush();
    bw.close();
    br.close();
  }
}
