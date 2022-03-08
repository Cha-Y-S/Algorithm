import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

  public static ArrayList<ArrayList<Integer>> parent;
  public static int[] child;
  public static int[] res;
  public static int N, M, pre, post;

  public static class Pair {
    public int subject;
    public int count;

    public Pair(int subject, int count) {
      this.subject = subject;
      this.count = count;
    }
  }

  public static void topological_sort() {
    Queue<Pair> q = new LinkedList<>();

    for (int i = 1; i < child.length; i++) {
      if (child[i] == 0)
        q.add(new Pair(i, 1));
    }

    while (!q.isEmpty()) {
      Pair cur = q.poll();

      res[cur.subject] = cur.count;

      for (int i = 0; i < parent.get(cur.subject).size(); i++) {
        if (--child[parent.get(cur.subject).get(i)] == 0)
          q.add(new Pair(parent.get(cur.subject).get(i), cur.count + 1));
      }
    }
  }

  public static void print_res(BufferedWriter bw) throws IOException {
    for (int i = 1; i <= N; i++) {
      bw.write(res[i] + " ");
    }
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    parent = new ArrayList<>();
    child = new int[N + 1];
    res = new int[N + 1];

    for (int i = 0; i < N + 1; i++) {
      parent.add(new ArrayList<Integer>());
    }

    for (int i = 0; i < M; i++) {
      st = new StringTokenizer(br.readLine());

      pre = Integer.parseInt(st.nextToken());
      post = Integer.parseInt(st.nextToken());

      parent.get(pre).add(post);
      child[post]++;
    }

    topological_sort();

    print_res(bw);

    bw.flush();
    bw.close();
    br.close();
  }
}
