
public class FindUniq {

    public static int MIN = 3;

    public static void main(String[] args) {
        double res = findUniq(new double[] { 1, 1, 1, 0, 1, 1 });
        System.out.printf("Expected 0. Returned: %.0f\n", res);

        res = findUniq(new double[] { 2, 1, 1, 1, 1, 1 });
        System.out.printf("Expected 2. Returned: %.0f\n", res);

        res = findUniq(new double[] { 1, 3, 1, 1, 1, 1 });
        System.out.printf("Expected 3. Returned: %.0f\n", res);

        res = findUniq(new double[] { 1, 1, 4, 1, 1, 1 });
        System.out.printf("Expected 4. Returned: %.0f\n", res);

        res = findUniq(new double[] { 1, 1, 1, 1, 1, 5 });
        System.out.printf("Expected 5. Returned: %.0f\n", res);
    }

    public static double findUniq(double arr[]) {
        // If arr[0] and arr[1] are equal, then the multiplicity is arr[0] = arr[1];
        // But, if they aren't equal then we know that one of them is the answer.
        // So then see if arr[0] = arr[2], if they are then arr[1] is the answer, otherwise
        // arr[0];
        if (arr[0] != arr[1]) {
            return arr[1] == arr[2] ? arr[0] : arr[1];
        }

        for (int i = 1; i < arr.length - 1; ++i) {
            if (arr[i] != arr[0]) {
                return arr[i];
            }
        }

        return arr[arr.length - 1];
    }
}