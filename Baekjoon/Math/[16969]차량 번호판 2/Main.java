import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
  
  public static String n_format;
  public static final int MOD = 1_000_000_009;
  public static long res;
  public static boolean flag;

  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    n_format = br.readLine();
    res = 1;

    for(int i = 0 ; i < n_format.length(); i++){
      if(n_format.charAt(i) == 'c'){
        if(i == 0){
          res *= 26;
        } else {
          res = (res * (flag ? 26 : 25)) % MOD;
        }
        flag = false;
      } else {
        if(i == 0){
          res *= 10;
        } else {
          res = (res * (flag ? 9 : 10)) % MOD;
        }
        flag = true;
      }
    }

    bw.write(res + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}
