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
    int x;
    int y;

    Pair(int x, int y) {
      this.x = x;
      this.y = y;
    }

    @Override
    public int compareTo(Pair a) {
      return this.x != a.x ? Integer.compare(this.x, a.x) : Integer.compare(this.y, a.y);
    }
  }

  public static Pair[] cats;
  public static ArrayList<Integer> lis;
  public static int N, M, T, r, c;

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
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    T = Integer.parseInt(br.readLine());

    cats = new Pair[T];
    lis = new ArrayList<>();

    for (int i = 0; i < T; i++) {
      st = new StringTokenizer(br.readLine());

      r = Integer.parseInt(st.nextToken());
      c = Integer.parseInt(st.nextToken());

      cats[i] = new Pair(r, c);
    }

    Arrays.sort(cats);

    for (int i = 0; i < T; i++) {
      int first = cats[i].x;
      int second = cats[i].y;

      if (first > N || second > M)
        continue;

      if (lis.isEmpty() || lis.get(lis.size() - 1) <= second)
        lis.add(second);
      else {
        int idx = upper_bound(second);
        lis.set(idx, second);
      }
    }

    bw.write(lis.size() + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}
