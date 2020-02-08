public class Fibonacci {

    public static void main(String[] args) {
        if (args.length != 3) {
          System.out.printf("Usage: java Xbonacci <seed> <seed> <limit>\n");
          return;
        }

        int seedOne = Integer.parseInt(args[0]);
        int seedTwo = Integer.parseInt(args[1]);
        int n = Integer.parseInt(args[2]);
        int[] ans = fibonacci(new int []{seedOne,seedTwo}, n);

        // Print
        int i = 0;
        System.out.printf("{");
        for (; i < ans.length - 1; ++i) {
            System.out.printf("%d, ", ans[i]);
        }
        System.out.printf("%d}\n", ans[i]);
    }

  public static int[] fibonacci(int[] s, int n) {
      int[] ans = new int[n];
      ans[0] = s[0];
      ans[1] = s[1];
      for (int i = 2; i < n; ++i) {
          ans[i] = ans[i - 1] + ans[i - 2];
      }

      return ans;
  }
}