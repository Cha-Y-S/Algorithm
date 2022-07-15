import java.util.Scanner;

public class Main {

  public static int[] arr;
  public static int N, tmp1, tmp2, res;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    N = sc.nextInt();

    arr = new int[N + 1];

    tmp1 = tmp2 = res = 1;

    for (int i = 1; i <= N; i++)
      arr[i] = sc.nextInt();

    for (int i = 1; i < N; i++) {
      if (arr[i] <= arr[i + 1])
        tmp1++;
      else
        tmp1 = 1;

      if (arr[i] >= arr[i + 1])
        tmp2++;
      else
        tmp2 = 1;

      int result = Math.max(tmp1, tmp2);
      res = Math.max(result, res);
    }

    System.out.println(res);

    sc.close();
  }
}