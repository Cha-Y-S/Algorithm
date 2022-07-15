import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

  public static String s, res;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    s = br.readLine();
    res = s;


    for(int i = 0 ; i < s.length() - 2; i++){
      for(int j = i + 1 ; j < s.length() - 1; j++){
        StringBuilder sb1 = new StringBuilder(s.substring(0, i + 1));
        StringBuilder sb2 = new StringBuilder(s.substring(i + 1, j + 1));
        StringBuilder sb3 = new StringBuilder(s.substring(j + 1, s.length()));

        StringBuilder result = new StringBuilder();

        result.append(sb1.reverse());
        result.append(sb2.reverse());
        result.append(sb3.reverse());

        if(res.compareTo(result.toString()) > 0){
          res = result.toString();
        }
      }
    }

    bw.write(res + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}