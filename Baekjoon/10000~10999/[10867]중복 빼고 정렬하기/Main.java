import java.util.*;
import java.io.*;

public class Main {

  public static Set<Integer> s;
  public static int N, num;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    
    N = Integer.parseInt(br.readLine());
    s = new TreeSet<Integer>();

    StringTokenizer st = new StringTokenizer(br.readLine());
    for (int i = 0; i < N; i++) {
      num = Integer.parseInt(st.nextToken());
      s.add(num);
    }

    for (int n : s) {
      bw.write(n + " ");
    }
    bw.write("\n");

    bw.flush();
    bw.close();
    br.close();
  }
}