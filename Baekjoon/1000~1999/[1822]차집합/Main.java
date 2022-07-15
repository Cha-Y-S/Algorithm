import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {

  public static int A, B;
  public static TreeSet<Integer> s;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer st = new StringTokenizer(br.readLine());

    A = Integer.parseInt(st.nextToken());
    B = Integer.parseInt(st.nextToken());
    s = new TreeSet<Integer>();

    st = new StringTokenizer(br.readLine());

    for (int i = 0; i < A; i++) {
      int num = Integer.parseInt(st.nextToken());

      s.add(num);
    }

    st = new StringTokenizer(br.readLine());

    for (int i = 0; i < B; i++) {
      int num = Integer.parseInt(st.nextToken());

      if (s.contains(num))
        s.remove(num);
    }

    bw.write(s.size() + "\n");

    for (int n : s) {
      bw.write(n + " ");
    }

    bw.flush();
    bw.close();
    br.close();
  }
}
