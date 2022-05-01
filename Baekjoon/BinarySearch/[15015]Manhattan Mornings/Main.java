import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

  public static class Pair implements Comparable<Pair> {
    public int first;
    public int second;

    public Pair(int first, int second) {
      this.first = first;
      this.second = second;
    }

    @Override
    public int compareTo(Pair other) {
      return this.first != other.first ? Integer.compare(this.first, other.first)
          : Integer.compare(this.second, other.second);
    }
  }

  public static Pair[] errands;
  public static ArrayList<Integer> lis;
  public static Pair H, W, conv;
  public static int N;

  public static int upper_bound(int value) {
    int low = 0;
    int high = lis.size();

    while (low < high) {
      int mid = (low + high) / 2;

      if (value < lis.get(mid)) {
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
    StringTokenizer st = new StringTokenizer(br.readLine());

    H = new Pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
    W = new Pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
    conv = new Pair(0, 0);

    W.first -= H.first;
    W.second -= H.second;

    if (W.first < 0) {
      conv.first = -1;
    } else {
      conv.first = 1;
    }

    if (W.second < 0) {
      conv.second = -1;
    } else {
      conv.second = 1;
    }

    errands = new Pair[N];
    lis = new ArrayList<>();

    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());

      errands[i] = new Pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));

      errands[i].first -= H.first;
      errands[i].first *= conv.first;

      errands[i].second -= H.second;
      errands[i].second *= conv.second;
    }

    H = new Pair(0, 0);
    W.first *= conv.first;
    W.second *= conv.second;

    Arrays.sort(errands);

    for (Pair p : errands) {
      if (p.first < H.first || p.first > W.first)
        continue;
      if (p.second < H.second || p.second > W.second)
        continue;
      if (lis.isEmpty() || lis.get(lis.size() - 1) <= p.second) {
        lis.add(p.second);
      } else {
        int idx = upper_bound(p.second);
        lis.set(idx, p.second);
      }
    }

    bw.write(lis.size() + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}