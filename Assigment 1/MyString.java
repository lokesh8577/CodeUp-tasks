/* 
    Name - Lokesh Prajapat
    Date - 16/9/25
 */

public class MyString {


    /* This program is used to extand characters in an input string with a perticular digit
        example. Input: "a1b4c3" 
        Output: "abbbbccc"
     */

    public static String expandCharacters(String inputString) {
        String result = "";
        for (int i = 0; i < inputString.length(); i += 2) {
            char character = inputString.charAt(i);
            int count = inputString.charAt(i + 1) - '0';
            for (int j = 0; j < count; j++) {
                result += character;
            }
        }
        return result;
    }

    /*  This program is used to print Frequency of a character from a input string
        example. Input: "aabcccdeee" 
        Output: "a2b1c3d1e3"
     */

    public static String characterFrequency(String inputString) {
        String result = "";
        int count = 1;
        for (int i = 0; i < inputString.length(); i++) {
            if (i + 1 < inputString.length() && inputString.charAt(i) == inputString.charAt(i + 1)) {
                count++;
            } else {
                result += inputString.charAt(i) + "" + count;
                count = 1;
            }
        }
        return result;
    }

    /* This program is used to check whether a input number is a prime number or not
        example. Input: 21 
        Output: "The given number is NOT prime"  
     */

    public static String isPrime(int number) {
        if (number <= 1) {
            return "The given number is NOT prime";
        }
        for (int i = 2; i * i <= number; i++) {
            if (number % i == 0) {
                return "The given number is NOT prime";
            }
        }
        return "The given number is PRIME";
    }

    /*   This program is used to convert a input number to its word conversion
        example. Input: 51 
        Output: "fifty one" 
     */

    public static String numberToWords(int number) {
        if (number == 0) {
            return "zero";
        }

        String[] units = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        String[] teens = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
            "sixteen", "seventeen", "eighteen", "nineteen"};
        String[] tens = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

        String words = "";

        if (number >= 100) {
            words += units[number / 100] + " hundred";
            number %= 100;
            if (number > 0) {
                words += " ";
            }
        }
        if (number >= 20) {
            words += tens[number / 10];
            number %= 10;
            if (number > 0) {
                words += " ";
            }
        } else if (number >= 10) {
            words += teens[number - 10];
            number = 0;
        }
        if (number > 0 && number < 10) {
            words += units[number];
        }
        return words;
    }

    /*  This program is used to print the length of longest substring without repeating characters
        example. input: s = "abcabcbb" 
        Output: 3 
     */
    
    public static int longestUniqueSubstring(String inputString) {
        int[] visited = new int[256];
        for (int i = 0; i < 256; i++) {
            visited[i] = -1;
        }

        int maxLength = 0, start = -1;

        for (int i = 0; i < inputString.length(); i++) {
            if (visited[inputString.charAt(i)] > start) {
                start = visited[inputString.charAt(i)];
            }
            visited[inputString.charAt(i)] = i;
            maxLength = Math.max(maxLength, i - start);
        }
        return maxLength;
    }

    public static void main(String[] args) {
        System.out.println(expandCharacters("a1b4c3"));
        System.out.println(characterFrequency("aabcccdeee"));
        System.out.println(isPrime(7));
        System.out.println(numberToWords(848));
        System.out.println(longestUniqueSubstring("abcabcbb"));
    }
}
