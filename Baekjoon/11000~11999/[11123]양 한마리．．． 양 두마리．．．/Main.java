import java.io.*;
import java.util.*;

public class Main {

  public static class Pair {
    int x;
    int y;

    Pair(int x, int y){
      this.x = x;
      this.y = y;
    }
  }

  public static int[][] matrix;
  public static boolean[][] visited;
  public static Pair[] dir = {new Pair(1 ,0), new Pair(0,1), new Pair(-1, 0), new Pair(0, -1)};
  public static int T, H, W, res;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    T = Integer.parseInt(br.readLine());

    for (int t = 0; t < T; t++) {
      StringTokenizer st = new StringTokenizer(br.readLine());

      H = Integer.parseInt(st.nextToken());
      W = Integer.parseInt(st.nextToken());

      matrix = new int[H][W];
      visited = new boolean[H][W];
      res = 0;

      for(int i = 0; i < H; i++){
        String row;

        row = br.readLine();

        for(int j = 0; j < W; j++){
          matrix[i][j] = row.charAt(j) == '#' ? 1 : 0;
        }
      }

      for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
          if(visited[i][j] == false && matrix[i][j] == 1){
            bfs(i, j);
            res++;
          }
        }
      }

      bw.write(res + "\n");
    }
    bw.flush();
    bw.close();
    br.close();
  }

  public static void bfs(int x, int y){
    Queue<Pair> q = new LinkedList<>();

    q.offer(new Pair(x, y));
    visited[x][y] = true;

    while(q.size() != 0){
      Pair cur = q.poll();

      for(int i = 0; i < dir.length; i++){
        int nx = cur.x + dir[i].x;
        int ny = cur.y + dir[i].y;

        if(nx < 0 || ny < 0 || nx >= H || ny >= W) continue;

        if(visited[nx][ny] == false && matrix[nx][ny] == 1){
          q.offer(new Pair(nx, ny));
          visited[nx][ny] = true;
        }
      }
    }
  }
}
