import java.util.ArrayList;
import java.util.Scanner;
import java.lang.String;

public class Main {

  public static class Pair {
    public int vertex;
    public double prob;

    public Pair(int vertex, double prob) {
      this.vertex = vertex;
      this.prob = prob;
    }
  }

  public static ArrayList<ArrayList<Pair>> graph;
  public static double[][] dp;
  public static int t, M;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    t = sc.nextInt();
    M = sc.nextInt();

    graph = new ArrayList<>();
    dp = new double[4][t + 1];
    dp[0][0] = dp[1][0] = dp[2][0] = dp[3][0] = 0.25;

    for (int i = 0; i < 4; i++)
      graph.add(new ArrayList<Pair>());

    for (int i = 0; i < M; i++) {
      char s, e;
      double prob;

      s = sc.next().charAt(0);
      e = sc.next().charAt(0);
      prob = sc.nextDouble();

      graph.get(s - 'A').add(new Pair(e - 'A', prob));
    }

    for (int k = 0; k < t; k++) {
      for (int i = 0; i < 4; i++) {
        for (Pair p : graph.get(i)) {
          dp[p.vertex][k + 1] += dp[i][k] * p.prob;
        }
      }
    }

    for (int i = 0; i < 4; i++) {
      System.out.println(String.format("%.2f", dp[i][t] * 100));
    }

    sc.close();
  }
}