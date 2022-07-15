import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
  
  public static int[] A;
  public static int[] B;
  public static int T, N, M, res;

  public static int lower_bound(int value){
    int low = 0;
    int high = B.length;    
    while(low < high){
      int mid = low + (high - low) / 2;

      if (value <= B[mid]){
        high = mid;
      } else {
        low = mid + 1;
      }
    }

    return high;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    
    T = Integer.parseInt(br.readLine());

    while(T-- > 0){
      StringTokenizer st = new StringTokenizer(br.readLine());

      N = Integer.parseInt(st.nextToken());
      M = Integer.parseInt(st.nextToken());

      A = new int[N];
      B = new int[M];
      res = 0;

      st = new StringTokenizer(br.readLine());
      for(int i = 0 ; i < N; i++){
        A[i] = Integer.parseInt(st.nextToken());
      }

      st = new StringTokenizer(br.readLine());
      for(int i = 0; i < M; i++){
        B[i] = Integer.parseInt(st.nextToken());
      }

      Arrays.sort(A);
      Arrays.sort(B);

      for(int i = 0; i < N; i++){
        int idx = lower_bound(A[i]);

        res += idx;
      }

      bw.write(res + "\n");
    }

    bw.flush();
    bw.close();
    br.close();
  }
}
