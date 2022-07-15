import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;

public class Main {

  public static Integer[] A;
  public static int T;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    T = sc.nextInt();

    for(int t = 0; t < T; t++){
      A = new Integer[10];
 
      for(int i = 0; i < 10; i++){
        A[i] = sc.nextInt();
      }

      Arrays.sort(A, Collections.reverseOrder());

      System.out.println(A[2]);
    }
  }
}