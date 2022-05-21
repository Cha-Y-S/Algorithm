import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

  public static String N;

  public static String mul17(String n) {
    char[] left = (n + "0000").toCharArray();
    char[] right = ("0000" + n).toCharArray();
    String result = "";

    boolean carry = false;
    for (int i = left.length - 1; i >= 0; i--) {
      if (left[i] == '0' && right[i] == '0') {
        if (carry) {
          result = "1" + result;
        } else {
          result = "0" + result;
        }
        carry = false;
      } else if (left[i] == '1' && right[i] == '1') {
        if (carry) {
          result = "1" + result;
        } else {
          result = "0" + result;
        }
        carry = true;
      } else {
        if (carry) {
          result = "0" + result;
          carry = true;
        } else {
          result = "1" + result;
          carry = false;
        }
      }
    }

    result = carry ? "1" + result : result;

    return result;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    N = br.readLine();

    bw.write(mul17(N) + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}