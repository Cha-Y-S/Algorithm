import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

  public static Integer[] boxes;
  public static int T, J, N, R, C, res;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    T = Integer.parseInt(br.readLine());

    while (T-- > 0) {
      StringTokenizer st = new StringTokenizer(br.readLine());

      J = Integer.parseInt(st.nextToken());
      N = Integer.parseInt(st.nextToken());

      boxes = new Integer[N];
      res = 0;

      for (int i = 0; i < N; i++) {
        st = new StringTokenizer(br.readLine());

        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        boxes[i] = R * C;
      }

      Arrays.sort(boxes, Collections.reverseOrder());

      for (int i = 0; i < N; i++) {
        J -= boxes[i];
        res++;

        if (J <= 0)
          break;
      }
      bw.write(res + "\n");
    }

    bw.flush();
    bw.close();
    br.close();
  }
}
