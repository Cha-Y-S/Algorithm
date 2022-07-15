import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

  public static int[][] grade;
  public static int K, N;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    K = Integer.parseInt(br.readLine());

    grade = new int[K][];

    for(int i = 0; i < K; i++){
      StringTokenizer st = new StringTokenizer(br.readLine());

      N = Integer.parseInt(st.nextToken());

      grade = new int[K][N];

      bw.write("Class " + (i + 1) + "\n");

      for(int j = 0; j < N; j++){
        grade[i][j] = Integer.parseInt(st.nextToken());
      }

      Arrays.sort(grade[i]);

      bw.write("Max " + grade[i][N -1] + ", ");
      bw.write("Min " + grade[i][0] + ", ");
      
      int gap = 0;
      for(int j = 1; j < N; j++){
        gap = gap < grade[i][j] - grade[i][j-1] ? grade[i][j] - grade[i][j-1] : gap;
      }

      bw.write("Largest gap " + gap + "\n");
    }

    bw.flush();
    bw.close();
    br.close();
  }
}