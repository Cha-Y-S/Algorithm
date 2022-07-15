import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
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
      return Integer.compare(this.first, other.first);
    }
  }

  public static Pair[] pole;
  public static ArrayList<Integer> lis, res;
  public static int[] idxs;
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

    pole = new Pair[N];
    idxs = new int[N];

    lis = new ArrayList<>();
    res = new ArrayList<>();

    for (int i = 0; i < N; i++) {
      StringTokenizer st = new StringTokenizer(br.readLine());

      pole[i] = new Pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
    }

    Arrays.sort(pole);

    for (int i = 0; i < N; i++) {
      int idx = lower_bound(pole[i].second);

      idxs[i] = idx;

      if (idx == lis.size()) {
        lis.add(pole[i].second);
      } else {
        lis.set(idx, pole[i].second);
      }
    }

    int target = lis.size() - 1;
    for (int i = N - 1; i >= 0; i--) {
      if (target == idxs[i]) {
        target--;
      } else {
        res.add(pole[i].first);
      }
    }

    res.sort(Comparator.naturalOrder());

    bw.write((N - lis.size()) + "\n");

    for (int n : res) {
      bw.write(n + "\n");
    }

    bw.flush();
    bw.close();
    br.close();
  }
}