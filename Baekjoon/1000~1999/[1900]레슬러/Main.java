import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

  public static class Player implements Comparable<Player> {
    public int id;
    public int power;
    public int ring;

    public Player(int id, int power, int ring) {
      this.id = id;
      this.power = power;
      this.ring = ring;
    }

    @Override
    public int compareTo(Player a) {
      return Integer.compare(a.power + this.power * a.ring, this.power + a.power * this.ring);
    }
  }

  public static Player[] players;
  public static int N;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    N = Integer.parseInt(br.readLine());

    players = new Player[N];

    for (int i = 0; i < N; i++) {
      StringTokenizer st = new StringTokenizer(br.readLine());

      int p = Integer.parseInt(st.nextToken());
      int r = Integer.parseInt(st.nextToken());

      players[i] = new Player(i + 1, p, r);
    }

    Arrays.sort(players);

    for (Player p : players) {
      bw.write(p.id + "\n");
    }

    bw.flush();
    bw.close();
    br.close();
  }
}
