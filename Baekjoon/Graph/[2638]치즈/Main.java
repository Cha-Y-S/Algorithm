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

  public static class Pair {
    int first;
    int second;

    Pair(int first, int second) {
      this.first = first;
      this.second = second;
    }
  }

  public static int[][] matrix;
  public static boolean[][] visited;
  public static Pair[] dirs = { new Pair(-1, 0), new Pair(0, 1), new Pair(1, 0), new Pair(0, -1) };
  public static int N, M, res;

  public static int bfs() {
    Queue<Pair> q = new LinkedList<Pair>();
    ArrayList<Pair> candidates = new ArrayList<Pair>();
    int[][] copied = new int[N][M];
    int result = 0;

    for (int i = 0; i < N; i++) {
      System.arraycopy(matrix[i], 0, copied[i], 0, M);
    }

    q.add(new Pair(0, 0));
    visited[0][0] = true;
    copied[0][0] = -1;

    while (!q.isEmpty()) {
      Pair cur = q.poll();

      for (int i = 0; i < dirs.length; i++) {
        int nx = cur.first + dirs[i].first;
        int ny = cur.second + dirs[i].second;

        if (nx < 0 || ny < 0 || nx >= N || ny >= M)
          continue;

        if (!visited[nx][ny]) {
          if (matrix[nx][ny] == 1) {
            candidates.add(new Pair(nx, ny));
          } else {
            q.add(new Pair(nx, ny));
            copied[nx][ny] = -1;
          }
          visited[nx][ny] = true;
        }
      }
    }

    for (Pair cur : candidates) {
      int cx = cur.first;
      int cy = cur.second;
      int cnt = 0;

      for (int i = 0; i < dirs.length; i++) {
        int nx = cx + dirs[i].first;
        int ny = cy + dirs[i].second;

        if (copied[nx][ny] == -1)
          cnt++;
      }

      if (cnt >= 2) {
        matrix[cx][cy] = 0;
        result++;
      }
    }

    return result;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    matrix = new int[N][M];
    res = 0;

    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < M; j++) {
        matrix[i][j] = Integer.parseInt(st.nextToken());
      }
    }

    while (true) {
      visited = new boolean[N][M];

      if (bfs() == 0) {
        break;
      }

      res++;
    }

    bw.write(res + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}
