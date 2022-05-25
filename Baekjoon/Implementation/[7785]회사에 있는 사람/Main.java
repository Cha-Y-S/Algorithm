import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Collections;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {

  public static Set<String> company;
  public static String name, info;
  public static int N;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    N = Integer.parseInt(br.readLine());
    company = new TreeSet<>(Collections.reverseOrder());

    for (int i = 0; i < N; i++) {
      StringTokenizer st = new StringTokenizer(br.readLine());

      name = st.nextToken();
      info = st.nextToken();

      if (info.compareTo("enter") == 0) {
        company.add(name);
      } else {
        company.remove(name);
      }
    }

    for (String person : company) {
      bw.write(person + "\n");
    }

    bw.flush();
    bw.close();
    br.close();
  }
}