public class Main {
  public static void main(String[] args) {
    Solution s = new Solution();

    int[] a, b;

    a = new int[] { 1, 2, 3, 4 };
    b = new int[] { -3, -1, 0, 2 };

    System.out.println(s.solution(a, b));

    a = new int[] { -1, 0, 1 };
    b = new int[] { 1, 0, -1 };

    System.out.println(s.solution(a, b));
  }
}
