import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

  public static int point, low, res;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    low = 100;
    res = 0;

    for (int i = 0; i < 4; i++) {
      point = Integer.parseInt(br.readLine());

      low = low > point ? point : low;

      res += point;
    }

    res -= low;
    low = 100;

    for (int i = 0; i < 2; i++) {
      point = Integer.parseInt(br.readLine());

      low = low > point ? point : low;

      res += point;
    }

    res -= low;

    bw.write(res + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}
