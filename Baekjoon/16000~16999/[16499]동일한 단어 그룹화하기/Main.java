import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Main {

  public static Set<String> s;
  public static String word;
  public static int N;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    N = Integer.parseInt(br.readLine());

    s = new HashSet<>();

    for (int i = 0; i < N; i++) {
      word = br.readLine();
      char[] tmp = word.toCharArray();

      Arrays.sort(tmp);

      s.add(new String(tmp));
    }

    bw.write(s.size() + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}