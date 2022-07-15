import java.util.*;
import java.io.*;

public class Main {

  public static class Nation implements Comparable<Nation> {
    public int id;
    public int gold;
    public int silver;
    public int bronze;

    public Nation(int id, int gold, int silver, int bronze){
      this.id = id;
      this.gold = gold;
      this.silver = silver;
      this.bronze = bronze;
    }

    @Override
    public int compareTo(Nation n){
      if(this.gold == n.gold){
        if(this.silver == n.silver){
          return Integer.compare(n.bronze, this.bronze);
        } else {
          return Integer.compare(n.silver, this.silver);
        }
      } else {
        return Integer.compare(n.gold, this.gold);
      }
    }
  }

  public static Nation[] nations;
  public static int N, K, id, gold, silver, bronze, res;

  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    K = Integer.parseInt(st.nextToken());

    nations = new Nation[N];

    for(int i = 0 ; i < N; i++){
      st = new StringTokenizer(br.readLine());

      id = Integer.parseInt(st.nextToken());
      gold = Integer.parseInt(st.nextToken());
      silver = Integer.parseInt(st.nextToken());
      bronze = Integer.parseInt(st.nextToken());

      nations[i] = new Nation(id, gold, silver, bronze);
    }

    Arrays.sort(nations);

    for(int i = 0 ; i < N; i++){
      if(nations[i].id == K){
        res = i;
        break;
      }
    }

    for(int i = 0; i < N; i++){
      if(nations[res].gold == nations[i].gold &&
      nations[res].silver == nations[i].silver &&
      nations[res].bronze == nations[i].bronze){
        bw.write((i + 1) + "\n");
        break;
      }
    }

    bw.flush();
    bw.close();
    br.close();
  }
}