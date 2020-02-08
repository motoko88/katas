import java.util.Arrays;

public class Xbonacci {

    public static void main(String[] args) {
        if (args.length != 0) {
          System.out.printf("Usage: java Xbonacci\n");
          return;
        }

        double[] ans = tribonacci(new double []{1,1,1},10);
        // Print
        int i = 0;
        System.out.printf("{");
        for (; i < ans.length - 1; ++i) {
            System.out.printf("%.0f, ", ans[i]);
        }
        System.out.printf("%.0f}\n", ans[i]);
    }

  public static double[] tribonacci(double[] s, int n) {
    if (n == 0) {
      return new double[]{};
    } else if (n == 1) {
      return new double[]{s[0]};
    } else if (n == 2) {
      return new double[]{s[0], s[1]};
    }

    double[] ans = new double[n];
    ans[0] = s[0];
    ans[1] = s[1];
    ans[2] = s[2];
    for (int i = 3; i < n; ++i) {
        ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
    }

    return Arrays.copyOfRange(ans, 0, n);
  }
}