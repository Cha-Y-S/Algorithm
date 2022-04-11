public class Main {
  public static void main(String[] args) {
    int picture[][] = {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}};
    
    Solution s = new Solution();
    print_solution(s.solution(6, 4, picture));
  }

  public static void print_solution(int[] res){
    System.out.print("[");

    for(int i = 0; i < res.length; i++){
      System.out.print(res[i]);

      if((i + 1) != res.length) System.out.print(", ");
    }

    System.out.println("]");
  }
}
