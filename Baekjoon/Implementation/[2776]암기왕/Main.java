import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

  public static Map<Integer, Boolean> note;
  public static int T, N, M, num;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    T = Integer.parseInt(br.readLine());

    while (T-- != 0) {
      N = Integer.parseInt(br.readLine());
      note = new HashMap<>();
      StringTokenizer st = new StringTokenizer(br.readLine());

      for (int i = 0; i < N; i++) {
        num = Integer.parseInt(st.nextToken());

        note.put(num, true);
      }

      M = Integer.parseInt(br.readLine());
      st = new StringTokenizer(br.readLine());

      for (int i = 0; i < M; i++) {
        num = Integer.parseInt(st.nextToken());

        if (note.containsKey(num)) {
          bw.write(1 + "\n");
        } else {
          bw.write(0 + "\n");
        }
      }
    }

    bw.flush();
    bw.close();
    br.close();
  }
}
