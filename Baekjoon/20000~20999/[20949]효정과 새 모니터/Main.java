import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

  public static class Pair implements Comparable<Pair> {
    double ppi;
    int id;

    Pair(double ppi, int id) {
      this.ppi = ppi;
      this.id = id;
    }

    @Override
    public int compareTo(Pair a) {
      if (this.ppi != a.ppi) {
        return Double.compare(a.ppi, this.ppi);
      } else {
        return Integer.compare(this.id, a.id);
      }
    }
  }

  public static Pair[] monitor;
  public static int N, W, H;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    N = Integer.parseInt(br.readLine());

    monitor = new Pair[N];

    for (int i = 0; i < N; i++) {
      StringTokenizer st = new StringTokenizer(br.readLine());

      W = Integer.parseInt(st.nextToken());
      H = Integer.parseInt(st.nextToken());

      double m_ppi = Math.sqrt(W * W + H * H) / 77;

      monitor[i] = new Pair(m_ppi, i + 1);
    }

    Arrays.sort(monitor);

    for (int i = 0; i < N; i++) {
      bw.write(monitor[i].id + "\n");
    }

    bw.flush();
    bw.close();
    br.close();
  }
}