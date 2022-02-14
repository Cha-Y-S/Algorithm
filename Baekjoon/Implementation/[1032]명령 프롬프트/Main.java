import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.lang.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    String res = "";
    int N;

    N = sc.nextInt();

    String[] files = new String[N];

    for (int i = 0; i < N; i++)
      files[i] = sc.next();

    for (int i = 0; i < files[0].length(); i++) {
      boolean flag = true;
      for (int j = 0; j < files.length - 1; j++) {
        if (files[j].charAt(i) != files[j + 1].charAt(i)) {
          flag = false;
          break;
        }
      }
      if (flag)
        res += files[0].charAt(i);
      else
        res += "?";
    }

    System.out.println(res);
  }
}