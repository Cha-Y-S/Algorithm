import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Map;
import java.util.TreeMap;
import java.util.Map.Entry;

public class Main {

  public static Map<String, Integer> trees;
  public static String tree;
  public static int cnt;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    trees = new TreeMap<>();
    cnt = 0;

    while ((tree = br.readLine()) != null) {
      if (trees.containsKey(tree)) {
        trees.replace(tree, trees.get(tree) + 1);
      } else {
        trees.put(tree, 1);
      }
      cnt++;
    }

    for (Entry<String, Integer> p : trees.entrySet()) {
      bw.write(String.format("%s %.4f\n", p.getKey(), ((double) p.getValue() / cnt * 100)));
    }

    bw.flush();
    bw.close();
    br.close();
  }
}