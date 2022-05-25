import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

  public static int day, car, res;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    day = Integer.parseInt(br.readLine());

    StringTokenizer st = new StringTokenizer(br.readLine());
    res = 0;

    for (int i = 0; i < 5; i++) {
      car = Integer.parseInt(st.nextToken());

      res = car == day ? res + 1 : res;
    }

    bw.write(res + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}
