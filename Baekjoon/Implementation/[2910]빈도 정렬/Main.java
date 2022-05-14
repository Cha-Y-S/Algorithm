import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.Map.Entry;

public class Main {

  public static class Pair implements Comparable<Pair> {
    int key;
    int value;

    Pair(int key, int value) {
      this.key = key;
      this.value = value;
    }

    @Override
    public int compareTo(Pair other) {
      return this.value != other.value ? Integer.compare(other.value, this.value)
          : Integer.compare(order.get(this.key), order.get(other.key));
    }
  }

  public static Map<Integer, Integer> freq, order;
  public static ArrayList<Pair> sorted;
  public static int N, C;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    C = Integer.parseInt(st.nextToken());

    freq = new HashMap<>();
    order = new HashMap<>();
    sorted = new ArrayList<>();

    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < N; i++) {
      int tmp = Integer.parseInt(st.nextToken());

      if (freq.containsKey(tmp)) {
        freq.replace(tmp, freq.get(tmp) + 1);
      } else {
        freq.put(tmp, 1);
      }

      if (!order.containsKey(tmp)) {
        order.put(tmp, i);
      }
    }

    for (Entry<Integer, Integer> p : freq.entrySet()) {
      sorted.add(new Pair(p.getKey(), p.getValue()));
    }

    Collections.sort(sorted);

    for (int i = 0; i < sorted.size(); i++) {
      for (int j = 0; j < sorted.get(i).value; j++) {
        bw.write(sorted.get(i).key + " ");
      }
    }
    bw.write("\n");

    bw.flush();
    bw.close();
    br.close();
  }
}