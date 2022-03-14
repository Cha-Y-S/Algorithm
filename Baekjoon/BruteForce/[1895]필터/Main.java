import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

  public static int[][] img;
  public static int R, C, T, res;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer st = new StringTokenizer(br.readLine());

    R = Integer.parseInt(st.nextToken());
    C = Integer.parseInt(st.nextToken());
    img = new int[R][C];
    res = 0;

    for (int i = 0; i < R; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < C; j++) {
        img[i][j] = Integer.parseInt(st.nextToken());
      }
    }

    st = new StringTokenizer(br.readLine());

    T = Integer.parseInt(st.nextToken());

    for (int i = 0; i < R - 2; i++) {
      for (int j = 0; j < C - 2; j++) {
        int[] tmp = new int[9];

        for (int ti = 0; ti < 3; ti++) {
          for (int tj = 0; tj < 3; tj++) {
            tmp[3 * ti + tj] = img[i + ti][j + tj];
          }
        }

        Arrays.sort(tmp);

        if (tmp[4] >= T)
          res++;
      }
    }

    bw.write(res + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}