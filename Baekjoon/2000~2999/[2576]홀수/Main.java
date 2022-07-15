import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

  public static int num, res_min, res_sum;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    res_min = 100;
    res_sum = 0;

    for (int i = 0; i < 7; i++) {
      num = Integer.parseInt(br.readLine());

      if (num % 2 != 0) {
        res_min = res_min > num ? num : res_min;
        res_sum += num;
      }
    }

    if (res_sum == 0) {
      bw.write("-1\n");
    } else {
      bw.write(res_sum + "\n" + res_min + "\n");
    }
    bw.flush();
    bw.close();
    br.close();
  }
}
