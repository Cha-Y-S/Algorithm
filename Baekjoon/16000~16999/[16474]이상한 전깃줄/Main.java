import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

  public static class Pair implements Comparable<Pair> {
    int first;
    int second;

    Pair(int first, int second) {
      this.first = first;
      this.second = second;
    }

    @Override
    public int compareTo(Pair other) {
      return this.first != other.first ? Integer.compare(this.first, other.first)
          : Integer.compare(other.second, this.second);
    }
  }

  public static Pair[] connected;
  public static Map<Integer, Integer> l_pole, r_pole;
  public static ArrayList<Integer> lis;
  public static int N, M, K;

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
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    l_pole = new HashMap<Integer, Integer>();
    r_pole = new HashMap<Integer, Integer>();

    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < N; i++) {
      l_pole.put(Integer.parseInt(st.nextToken()), i);
    }

    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < M; i++) {
      r_pole.put(Integer.parseInt(st.nextToken()), i);
    }

    K = Integer.parseInt(br.readLine());
    connected = new Pair[K];

    for (int i = 0; i < K; i++) {
      st = new StringTokenizer(br.readLine());

      connected[i] = new Pair(l_pole.get(Integer.parseInt(st.nextToken())),
          r_pole.get(Integer.parseInt(st.nextToken())));
    }

    Arrays.sort(connected);

    lis = new ArrayList<>();

    for (int i = 0; i < K; i++) {
      int idx = lower_bound(connected[i].second);

      if (idx == lis.size()) {
        lis.add(connected[i].second);
      } else {
        lis.set(idx, connected[i].second);
      }
    }

    bw.write((K - lis.size()) + "\n");

    bw.flush();
    bw.close();
    br.close();

  }
}
