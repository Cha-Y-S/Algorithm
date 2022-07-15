import java.util.Scanner;

public class Main {

  public static long N;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    N = sc.nextLong();

    System.out.println(N * (N - 1) / 2);

    sc.close();
  }
}