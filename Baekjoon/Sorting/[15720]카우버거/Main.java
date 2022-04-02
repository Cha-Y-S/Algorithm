import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
  
  public static class Pair implements Comparable<Pair> {
    public int first;
    public boolean second;
  
    Pair(int first, boolean second) {
      this.first = first;
      this.second = second;
    }
  
    @Override
    public int compareTo(Pair a) {
      return Integer.compare(a.first, this.first);
    }
  }
  public static Pair[] total;
  public static Integer[] burger;
  public static Integer[] drink;
  public static Integer[] side;
  public static int B, C, D, max_size, res1, res2;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer st = new StringTokenizer(br.readLine());

    B = Integer.parseInt(st.nextToken());
    C = Integer.parseInt(st.nextToken());
    D = Integer.parseInt(st.nextToken());

    max_size = Math.max(B, Math.max(C, D));

    total = new Pair[max_size];
    burger = new Integer[B];
    side = new Integer[C];
    drink = new Integer[D];
    res1 = res2 =0;

    st = new StringTokenizer(br.readLine());

    for (int i = 0; i < B; i++) {
      burger[i] = Integer.parseInt(st.nextToken());
    }

    st = new StringTokenizer(br.readLine());

    for (int i = 0; i < C; i++) {
      side[i] = Integer.parseInt(st.nextToken());
    }

    st = new StringTokenizer(br.readLine());

    for (int i = 0; i < D; i++) {
      drink[i] = Integer.parseInt(st.nextToken());
    }

    Arrays.sort(burger, Collections.reverseOrder());
    Arrays.sort(side, Collections.reverseOrder());
    Arrays.sort(drink, Collections.reverseOrder());

    for (int i = 0; i < max_size; i++) {
      total[i] = new Pair(0, true);
      if (i < B) {
        total[i].first += burger[i];
      } else {
        total[i].second = false;
      }
      if (i < C) {
        total[i].first += side[i];
      } else {
        total[i].second = false;
      }
      if (i < D) {
        total[i].first += drink[i];
      } else {
        total[i].second = false;
      }
    }

    for(int i = 0 ; i < max_size; i++){
      res1 += total[i].first;

      if(total[i].second){
        res2 += total[i].first * 0.9;
      } else {
        res2 += total[i].first;
      }
    }

    bw.write(res1 + "\n" + res2 + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}