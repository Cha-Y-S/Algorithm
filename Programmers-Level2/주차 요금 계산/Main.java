public class Main {
  
  public static void main(String[] args) {
    int[] fees = new int[] {180, 5000, 10, 600};
    String[] records = new String[] {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};

    Solution sol = new Solution();

    print_solution(sol.solution(fees, records));

    fees = new int[] {120, 0, 60, 591};
    records = new String[] {"16:00 3961 IN", "16:00 0202 IN", "18:00 3961 OUT", "18:00 0202 OUT", "23:58 3961 IN"};

    print_solution(sol.solution(fees, records));

    fees = new int[] {1, 461, 1, 10};
    records = new String[] {"00:00 1234 IN"};

    print_solution(sol.solution(fees, records));
  }

  public static void print_solution(int[] res) {
    System.out.print("[");

    for (int i = 0; i < res.length; i++) {
      System.out.print(res[i]);

      if ((i + 1) != res.length)
        System.out.print(", ");
    }

    System.out.println("]");
  }
}
