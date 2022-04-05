import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Collections;

public class Main {

  public static Integer[] straws;
  public static int N, res;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    N = Integer.parseInt(br.readLine());
    res = -1;

    straws = new Integer[N];

    for (int i = 0; i < N; i++) {
      straws[i] = Integer.parseInt(br.readLine());
    }

    Arrays.sort(straws, Collections.reverseOrder());

    for (int i = 0; i < N - 2; i++) {
      if (straws[i] < straws[i + 1] + straws[i + 2]) {
        res = straws[i] + straws[i + 1] + straws[i + 2];
        break;
      }
    }

    bw.write(res + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}
