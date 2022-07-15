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
    String sid;
    int order;

    Pair(String sid, int order) {
      this.sid = sid;
      this.order = order;
    }

    @Override
    public int compareTo(Pair other) {
      return Integer.compare(this.order, other.order);
    }
  }

  public static Map<String, Integer> enroll;
  public static ArrayList<Pair> res;
  public static int K, L;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer st = new StringTokenizer(br.readLine());

    K = Integer.parseInt(st.nextToken());
    L = Integer.parseInt(st.nextToken());

    enroll = new HashMap<>();
    res = new ArrayList<>();

    for (int i = 0; i < L; i++) {
      String tmp = br.readLine();

      if (enroll.containsKey(tmp)) {
        enroll.replace(tmp, i);
        continue;
      }

      enroll.put(tmp, i);
    }

    for (Entry<String, Integer> e : enroll.entrySet()) {
      res.add(new Pair(e.getKey(), e.getValue()));
    }

    Collections.sort(res);

    for (int i = 0; i < res.size(); i++) {
      if (K-- > 0) {
        bw.write(res.get(i).sid + "\n");
      } else {
        break;
      }
    }

    bw.flush();
    bw.close();
    br.close();
  }
}
