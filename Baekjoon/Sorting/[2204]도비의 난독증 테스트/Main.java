import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class Main {

  public static class Pair implements Comparable<Pair> {
    public String first;
    public String second;

    Pair(String first, String second) {
      this.first = first;
      this.second = second;
    }

    @Override
    public int compareTo(Pair a) {
      return this.first.compareTo(a.first);
    }
  }

  public static Pair[] words;
  public static int N;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    while (true) {
      N = Integer.parseInt(br.readLine());

      if (N == 0)
        break;

      words = new Pair[N];

      for (int i = 0; i < N; i++) {
        String input;

        input = br.readLine();

        words[i] = new Pair(input.toUpperCase(), input);
      }

      Arrays.sort(words);

      bw.write(words[0].second + "\n");
    }

    bw.flush();
    bw.close();
    br.close();
  }
}