import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;

public class Main {

  public static Map<String, Integer> player;
  public static String p;
  public static int N;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    N = Integer.parseInt(br.readLine());
    player = new HashMap<>();

    for (int i = 0; i < N; i++) {
      p = br.readLine();

      if (!player.containsKey(p)) {
        player.put(p, 1);
        continue;
      }

      player.replace(p, player.get(p) + 1);
    }

    for (int i = 0; i < N - 1; i++) {
      p = br.readLine();

      player.replace(p, player.get(p) - 1);
    }

    for (Entry<String, Integer> entry : player.entrySet()) {
      if (entry.getValue() != 0) {
        bw.write(entry.getKey() + "\n");
        break;
      }
    }

    bw.flush();
    bw.close();
    br.close();
  }
}
