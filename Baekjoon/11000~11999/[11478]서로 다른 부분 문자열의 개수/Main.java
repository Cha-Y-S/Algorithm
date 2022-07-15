import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.Set;

public class Main {

  public static Set<String> sub;
  public static String S, tmp;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    S = br.readLine();

    sub = new HashSet<>();

    for (int i = 0; i < S.length(); i++) {
      tmp = "";
      for (int j = i; j < S.length(); j++) {
        tmp += S.charAt(j);
        sub.add(tmp);
      }
    }

    bw.write(sub.size() + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}