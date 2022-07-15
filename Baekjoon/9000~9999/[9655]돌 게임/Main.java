import java.util.Scanner;

public class Main {

  public static int N;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    N = sc.nextInt();

    System.out.println(N % 2 == 0 ? "CY" : "SK");

    sc.close();
  }

}
