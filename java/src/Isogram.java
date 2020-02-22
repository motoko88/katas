import java.util.HashMap;
import java.util.HashSet;

/**
 * https://www.codewars.com/kata/54ba84be607a92aa900000f1/java
 */
public class Isogram {

    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.printf("Usage: java Isogram <string>\n");
            return;
        }

        boolean res = isIsogram(args[0]);
        System.out.println(res);
    }

    public static boolean isIsogram(String str) {
        HashSet<String> hash = new HashSet<>();
        String current;
        for (int i = 0; i < str.length(); ++i) {
            current = Character.toString(str.charAt(i)).toLowerCase();
            if (!hash.contains(current)) {
                hash.add(current);
            } else {
                return false;
            }
        }
        return true;
    }
}