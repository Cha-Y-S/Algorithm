import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

  public static int[] skill;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer st = new StringTokenizer(br.readLine());

    skill = new int[4];

    for (int i = 0; i < 4; i++) {
      skill[i] = Integer.parseInt(st.nextToken());
    }

    Arrays.sort(skill);

    bw.write(Math.abs((skill[0] + skill[3]) - (skill[1] + skill[2])) + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}