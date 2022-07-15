import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.Map.Entry;

public class Main {

  public static class PSI implements Comparable<PSI> {
    public String first;
    public int second;

    public PSI(String first, int second) {
      this.first = first;
      this.second = second;
    }

    @Override
    public int compareTo(PSI a) {
      return this.first.compareTo(a.first);
    }
  }

  public static class PDS implements Comparable<PDS> {
    public double first;
    public String second;

    public PDS(double first, String second) {
      this.first = first;
      this.second = second;
    }

    @Override
    public int compareTo(PDS a) {
      return Double.compare(a.first, this.first);
    }
  }

  public static PSI[] staff;
  public static ArrayList<PSI> res;
  public static ArrayList<PDS> s;
  public static Map<String, Integer> candidates;
  public static int X, N;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    X = Integer.parseInt(br.readLine());
    N = Integer.parseInt(br.readLine());

    staff = new PSI[N];
    candidates = new TreeMap<>();
    res = new ArrayList<>();
    s = new ArrayList<>();

    for (int i = 0; i < N; i++) {
      StringTokenizer st = new StringTokenizer(br.readLine());

      staff[i] = new PSI(st.nextToken(), Integer.parseInt(st.nextToken()));

      if ((double) staff[i].second / X * 100 >= 5) {
        candidates.put(staff[i].first, 0);

        for (int j = 0; j < 14; j++) {
          s.add(new PDS((double) staff[i].second / (j + 1), staff[i].first));
        }
      }
    }

    Collections.sort(s);

    for (int i = 0; i < 14; i++) {
      candidates.put(s.get(i).second, candidates.get(s.get(i).second) + 1);
    }

    for (Entry<String, Integer> e : candidates.entrySet()) {
      res.add(new PSI(e.getKey(), e.getValue()));
    }

    for (int i = 0; i < res.size(); i++) {
      bw.write(res.get(i).first + " " + res.get(i).second + "\n");
    }

    bw.flush();
    bw.close();
    br.close();
  }

}