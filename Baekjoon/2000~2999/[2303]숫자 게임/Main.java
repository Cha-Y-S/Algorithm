import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
  
  public static class Player implements Comparable<Player>{
    int id;
    int maximum;

    public Player(int id, int maximum){
      this.id = id;
      this.maximum = maximum;
    }

    @Override
    public int compareTo(Player a){
      return this.maximum != a.maximum ? Integer.compare(a.maximum, this.maximum) : Integer.compare(a.id, this.id);
    }
  }

  public static Player[] players;
  public static int N;

  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    N = Integer.parseInt(br.readLine());

    players = new Player[N];

    for(int p = 0 ; p < N; p++){
      StringTokenizer st = new StringTokenizer(br.readLine());
      int cards[] = new int[5];
      int sum = 0;
      

      for(int i = 0 ; i < 5; i++){    
        cards[i] = Integer.parseInt(st.nextToken());
      }

      for(int i = 0 ; i < 5; i++){
        for(int j = i + 1; j < 5; j++){
          for(int k = j + 1; k < 5; k++){
            int tmp = (cards[i] + cards[j] + cards[k]) % 10;
            sum = tmp > sum ? tmp : sum;
          }
        }
      }
      players[p] = new Player(p + 1, sum);
    }

    Arrays.sort(players);

    bw.write(players[0].id + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}