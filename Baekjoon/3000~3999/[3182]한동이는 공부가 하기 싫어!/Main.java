import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
  
  public static int[] graph;
  public static boolean[] visited;
  public static int N, maximum, res;

  public static int bfs(int start){
    Queue<Integer> q = new LinkedList<>();
    visited = new boolean[N+1];
    int result = 0;

    q.add(start);
    visited[start] = true;

    while(!q.isEmpty()){
      int cur = q.poll();

      result += 1;

      if(!visited[graph[cur]]){
        q.add(graph[cur]);
        visited[graph[cur]] = true;
      }
    }
    
    return result;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    N = Integer.parseInt(br.readLine());

    graph = new int[N + 1];
    maximum = 0;

    for(int i = 1; i <= N; i++){
      graph[i] = Integer.parseInt(br.readLine());
    }

    for(int i = 1; i <= N; i++){
      int tmp = bfs(i);

      if(tmp > maximum){
        maximum = tmp;
        res = i;
      }
    }

    bw.write(res + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}