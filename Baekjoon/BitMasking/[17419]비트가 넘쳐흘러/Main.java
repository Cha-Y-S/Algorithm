import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

  public static String K;
  public static int N, res;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    st = new StringTokenizer(br.readLine());
    K = st.nextToken();

    res = 0;

    for (int i = 0; i < N; i++) {
      if (K.charAt(i) == '1')
        res++;
    }

    bw.write(res + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}