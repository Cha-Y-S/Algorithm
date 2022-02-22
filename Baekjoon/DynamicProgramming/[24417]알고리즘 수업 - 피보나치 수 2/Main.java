import java.util.Scanner;

public class Main {

    public static int tmp1, tmp2, res;
    public static int N;
    public static final int MOD = 1_000_000_007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();

        tmp1 = tmp2 = 1;

        for (int i = 3; i <= N; i++) {
            res = (tmp1 + tmp2) % MOD;
            tmp1 = tmp2;
            tmp2 = res;
        }

        System.out.println(res + " " + (N - 2));

        sc.close();
    }
}