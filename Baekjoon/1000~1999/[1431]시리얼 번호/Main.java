import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class Main {

  public static class Word implements Comparable<Word> {
    public String word;

    public Word(String word) {
      this.word = word;
    }

    @Override
    public int compareTo(Word a) {
      if (this.word.length() != a.word.length()) {
        return Integer.compare(this.word.length(), a.word.length());
      }

      int this_sum = 0;
      int a_sum = 0;

      for (int i = 0; i < this.word.length(); i++) {
        if ('0' <= this.word.charAt(i) && this.word.charAt(i) <= '9')
          this_sum += this.word.charAt(i) - '0';
        if ('0' <= a.word.charAt(i) && a.word.charAt(i) <= '9')
          a_sum += a.word.charAt(i) - '0';
      }

      if (this_sum != a_sum) {
        return Integer.compare(this_sum, a_sum);
      } else {
        return this.word.compareTo(a.word);
      }
    }
  }

  public static Word[] words;
  public static int N;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    N = Integer.parseInt(br.readLine());

    words = new Word[N];

    for (int i = 0; i < N; i++) {
      words[i] = new Word(br.readLine());
    }

    Arrays.sort(words);

    for (Word w : words) {
      bw.write(w.word + "\n");
    }

    bw.flush();
    bw.close();
    br.close();
  }
}