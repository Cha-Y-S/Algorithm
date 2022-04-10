import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
  
  public static class Order implements Comparable<Order>{
    int n;
    int t;

    Order(int n, int t){
      this.n = n;
      this.t = t;
    }

    @Override
    public int compareTo(Order o){
      return this.t != o.t ? Integer.compare(this.t, o.t) : Integer.compare(this.n, o.n);
    }
  }

  public static ArrayList<Order> tables;
  public static String operation;
  public static int N, M, o_table, o_time;

  public static void print_tables(BufferedWriter bw) throws IOException{
    if(tables.size() == 0){
      bw.write("sleep\n");
    } else {
      for(int i = 0; i < tables.size(); i++){
        bw.write(tables.get(i).n + " ");
      }
      bw.write("\n");
    }
  }

  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    tables = new ArrayList<>();

    for(int i = 0; i < N; i++){
      st = new StringTokenizer(br.readLine());

      operation = st.nextToken();

      if(operation.compareTo("order") == 0){
        o_table = Integer.parseInt(st.nextToken());
        o_time = Integer.parseInt(st.nextToken());

        tables.add(new Order(o_table, o_time));
      } else if(operation.compareTo("complete") == 0){
        o_table = Integer.parseInt(st.nextToken());

        tables.removeIf(ord -> ord.n == o_table);
      } else {
        Collections.sort(tables);
      }

      print_tables(bw);
    }

    bw.flush();
    bw.close();
    br.close();
  }
}
