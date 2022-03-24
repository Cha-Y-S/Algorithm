import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

  public static class Person implements Comparable<Person> {
    String name;
    int year;
    int month;
    int day;

    Person(String name, int year, int month, int day) {
      this.name = name;
      this.year = year;
      this.month = month;
      this.day = day;
    }

    @Override
    public int compareTo(Person a) {
      if (a.year != this.year) {
        return Integer.compare(this.year, a.year);
      } else {
        if (this.month != a.month) {
          return Integer.compare(this.month, a.month);
        } else {
          return Integer.compare(this.day, a.day);
        }
      }
    }
  }

  public static Person[] people;
  public static String name;
  public static int N, year, month, day;

  public static void main(String[] args) throws NumberFormatException, IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    N = Integer.parseInt(br.readLine());

    people = new Person[N];

    for (int i = 0; i < N; i++) {
      StringTokenizer st = new StringTokenizer(br.readLine());

      name = st.nextToken();
      day = Integer.parseInt(st.nextToken());
      month = Integer.parseInt(st.nextToken());
      year = Integer.parseInt(st.nextToken());

      people[i] = new Person(name, year, month, day);
    }

    Arrays.sort(people);

    bw.write(people[N - 1].name + "\n" + people[0].name + "\n");

    bw.flush();
    bw.close();
    br.close();
  }
}
