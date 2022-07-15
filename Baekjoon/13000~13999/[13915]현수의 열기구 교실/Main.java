import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.Set;

public class Main {

  public static Set<Integer> s;
  public static String num;
  public static int N, tmp;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    while ((num = br.readLine()) != null && !num.equals("")) {
      N = Integer.parseInt(num);
      s = new HashSet<Integer>();

      for (int i = 0; i < N; i++) {
        tmp = 0;

        num = br.readLine();

        for (char c : num.toCharArray()) {
          tmp |= 1 << (c - 'a');
        }

        s.add(tmp);
      }

      bw.write(s.size() + "\n");
    }

    bw.flush();
    bw.close();
    br.close();
  }
}