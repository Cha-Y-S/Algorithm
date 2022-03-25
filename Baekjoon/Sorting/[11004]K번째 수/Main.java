import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.*;
import java.util.StringTokenizer;
import java.io.*;

public class Main{

  public static int[] A;
  public static int N, K;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    K = Integer.parseInt(st.nextToken());

    A = new int[N];

    st = new StringTokenizer(br.readLine());
    for(int i = 0 ; i < N; i++){
      A[i] = Integer.parseInt(st.nextToken());
    }

    Arrays.sort(A);

    bw.write(A[K-1] + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}