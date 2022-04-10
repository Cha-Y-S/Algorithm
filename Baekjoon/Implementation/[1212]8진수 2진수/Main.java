import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

  public static String octal;

  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();

    octal = br.readLine();
    
    for(int i = 0; i < octal.length(); i++){
      String tmp = Integer.toBinaryString(octal.charAt(i) - '0');
      if(tmp.length() == 2 && i != 0) tmp = "0" + tmp;
      else if(tmp.length() == 1 && i != 0) tmp = "00" + tmp;

      sb.append(tmp);
    }

    bw.write(sb + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}