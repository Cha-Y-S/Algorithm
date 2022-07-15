import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

  public static Set<Integer> A, B, C, lucky_number;
  public static int T, N, M, K;

  public static void input_data(BufferedReader br) throws IOException {
    N = Integer.parseInt(br.readLine());

    StringTokenizer st = new StringTokenizer(br.readLine());

    for (int i = 0; i < N; i++) {
      A.add(Integer.parseInt(st.nextToken()));
    }

    M = Integer.parseInt(br.readLine());

    st = new StringTokenizer(br.readLine());

    for (int i = 0; i < M; i++) {
      B.add(Integer.parseInt(st.nextToken()));
    }

    K = Integer.parseInt(br.readLine());

    st = new StringTokenizer(br.readLine());

    for (int i = 0; i < K; i++) {
      C.add(Integer.parseInt(st.nextToken()));
    }
  }

  public static boolean check_validity(String number) {
    boolean result = true;

    for (int i = 0; i < number.length(); i++) {
      if (number.charAt(i) != '5' && number.charAt(i) != '8') {
        result = false;
        break;
      }
    }

    return result;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    T = Integer.parseInt(br.readLine());

    while (T-- > 0) {
      A = new HashSet<>();
      B = new HashSet<>();
      C = new HashSet<>();
      lucky_number = new HashSet<>();

      input_data(br);

      for (int a : A) {
        for (int b : B) {
          for (int c : C) {
            int tmp = a + b + c;
            if (check_validity(Integer.toString(tmp))) {
              lucky_number.add(tmp);
            }
          }
        }
      }

      bw.write(lucky_number.size() + "\n");
    }
    bw.flush();
    bw.close();
    br.close();
  }
}
