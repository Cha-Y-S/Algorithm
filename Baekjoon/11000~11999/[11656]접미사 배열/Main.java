import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

public class Main {

  public static ArrayList<String> suffix;
  public static String S;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    S = br.readLine();

    suffix = new ArrayList<String>();

    while (S.length() > 0) {
      suffix.add(S);
      S = S.substring(1);
    }

    suffix.sort(Comparator.naturalOrder());

    for (String s : suffix) {
      bw.write(s + "\n");
    }

    bw.flush();
    bw.close();
    br.close();
  }

}
