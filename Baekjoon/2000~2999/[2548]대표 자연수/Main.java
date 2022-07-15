import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

  public static int[] naturals;
  public static int N;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    N = Integer.parseInt(br.readLine());

    naturals = new int[N];

    StringTokenizer st = new StringTokenizer(br.readLine());

    for (int i = 0; i < N; i++) {
      naturals[i] = Integer.parseInt(st.nextToken());
    }

    Arrays.sort(naturals);

    int q = N / 2;
    int r = N % 2;

    bw.write(naturals[q + r - 1] + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}
