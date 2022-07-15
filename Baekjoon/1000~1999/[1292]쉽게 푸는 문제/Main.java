import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

  public static int[] v;
  public static int A, B, idx, res;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer st = new StringTokenizer(br.readLine());

    A = Integer.parseInt(st.nextToken());
    B = Integer.parseInt(st.nextToken());

    v = new int[1000];
    res = idx = 0;

    for(int i = 1; i <= 1000; i++){
      for(int j = 0; j < i && idx < 1000; j++){
        v[idx++] = i;
      }
    }

    for(int i = A - 1; i < B; i++){
      res += v[i];
    }

    bw.write(res + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}