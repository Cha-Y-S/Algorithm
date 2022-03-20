import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
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
  public static int H, W, hour, res;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer st = new StringTokenizer(br.readLine());

    H = Integer.parseInt(st.nextToken());
    W = Integer.parseInt(st.nextToken());

    matrix = new int[H][W];
    hour = 0;

    for (int i = 0; i < H; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < W; j++) {
        matrix[i][j] = Integer.parseInt(st.nextToken());
      }
    }

    while (true) {
      visited = new boolean[H][W];

      int tmp = bfs();

      if (tmp == 0) {
        break;
      }

      res = tmp;
    }

    bw.write((--hour) + "\n" + res + "\n");

    bw.flush();
    bw.close();
    br.close();
  }

  public static int bfs() {
    Queue<Pair> q = new LinkedList<Pair>();
    int cnt = 0;

    q.offer(new Pair(0, 0));
    visited[0][0] = true;
    hour++;

    while (!q.isEmpty()) {
      Pair cur = q.poll();

      for (int i = 0; i < dirs.length; i++) {
        int nx = cur.first + dirs[i].first;
        int ny = cur.second + dirs[i].second;

        if (nx < 0 || ny < 0 || nx >= H || ny >= W)
          continue;

        if (!visited[nx][ny]) {
          if (matrix[nx][ny] == 0) {
            q.offer(new Pair(nx, ny));
          } else {
            matrix[nx][ny] = 0;
            cnt++;
          }
          visited[nx][ny] = true;
        }
      }
    }

    return cnt;
  }
}