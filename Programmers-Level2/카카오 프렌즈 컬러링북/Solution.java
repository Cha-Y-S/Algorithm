import java.util.LinkedList;
import java.util.Queue;

class Solution {

  private class Pair {
    int x;
    int y;

    Pair(int x, int y){
      this.x = x;
      this.y = y;
    }
  }

  private boolean[][] visited;
  private Pair[] dirs = {new Pair(-1, 0), new Pair(0, 1), new Pair(1, 0), new Pair(0, -1)};

  private int bfs(int m, int n, int x, int y, int target, int[][] picture){
    Queue<Pair> q = new LinkedList<>();
    int result = 0;
    
    q.offer(new Pair(x, y));
    visited[x][y] = true;

    while(!q.isEmpty()){
      Pair cur = q.poll();

      result++;

      for(int i = 0; i < dirs.length; i++){
        int nx = cur.x + dirs[i].x;
        int ny = cur.y + dirs[i].y;

        if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

        if(!visited[nx][ny] && picture[nx][ny] == target){
          q.offer(new Pair(nx, ny));
          visited[nx][ny] = true;
        }
      }
    }

    return result;
  }

  public int[] solution(int m, int n, int[][] picture) {
    int[] answer = new int[2];
    int numberOfArea = 0;
    int maxSizeOfOneArea = 0;

    visited = new boolean[m][n];

    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
        if(!visited[i][j] && picture[i][j] != 0){
          int tmp = bfs(m, n, i, j, picture[i][j], picture);

          maxSizeOfOneArea = tmp > maxSizeOfOneArea ? tmp : maxSizeOfOneArea;

          numberOfArea++;
        }
      }
    }

    answer[0] = numberOfArea;
    answer[1] = maxSizeOfOneArea;
    return answer;
  }
}
