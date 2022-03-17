import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

  public static int[] number;
  public static boolean[] visited;
  public static int N, M;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    number = new int[N];
    visited = new boolean[N];

    for (int i = 0; i < N; i++) {
      number[i] = Integer.parseInt(br.readLine());
      visited[i] = false;
    }

    bw.write(bfs(0) + "\n");

    bw.flush();
    bw.close();
    br.close();
  }

  public static int bfs(int v) {
    Queue<Integer> q = new LinkedList<Integer>();
    int res = 1;

    q.add(number[v]);
    visited[v] = false;

    while (q.size() != 0) {
      int cur = q.poll();

      if (cur == M) {
        break;
      }

      if (!visited[number[cur]]) {
        q.add(number[cur]);
        visited[number[cur]] = true;
        res++;
      } else {
        res = -1;
      }
    }
    return res;
  }
}
