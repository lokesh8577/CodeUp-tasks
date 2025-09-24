/* 
    This files provides some of operations like - expanding characters, character frequency, prime checking, number to words conversion
    Name - Lokesh Prajapat
    Date - 16/9/25
 */
import java.util.Scanner;

public class MyString {


    /* This program is used to extand characters in an input string with a perticular digit
        example. Input: "a1b4c3" 
        Output: "abbbbccc"
     */
    public static String expandCharacters(String inputString) {
        if (inputString == null || inputString.length() == 0) {
            return "";
        }

        String result = "";
        int n = inputString.length();
        int i = 0;

        while (i < n) {
            char ch = inputString.charAt(i);
            i++;
            int count = 0;
            while (i < n && inputString.charAt(i) >= '0' && inputString.charAt(i) <= '9') {
                int digit = inputString.charAt(i) - '0';
                count = count * 10 + digit;
                i++;
            }

            if (count == 0) {
                result += ch;
            } else {
                for (int k = 0; k < count; k++) {
                    result += ch;
                }
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
        int n = inputString.length();

        boolean[] visited = new boolean[256];

        for (int i = 0; i < n; i++) {
            char ch = inputString.charAt(i);
            if (visited[ch]) {
                continue;
            }

            int count = 0;
            for (int j = 0; j < n; j++) {
                if (inputString.charAt(j) == ch) {
                    count++;
                }
            }
            visited[ch] = true;
            result += ch;
            String countStr = "";
            int temp = count;

            if (temp == 0) {
                countStr = "0";
            } else {
                String reverse = "";
                while (temp > 0) {
                    int digit = temp % 10;
                    char digitChar = (char) ('0' + digit);
                    reverse += digitChar;
                    temp /= 10;
                }
                for (int k = reverse.length() - 1; k >= 0; k--) {
                    countStr += reverse.charAt(k);
                }
            }

            result += countStr;
        }

        return result;
    }

    /* This program is used to check whether a input number is a prime number or not
        example. Input: 21 
        Output: "The given number is NOT prime"  
     */
    public static String isPrime(int number) {
        if (number <= 1) {
            return Constant.NOT_PRIME_STRING;
        }
        for (int i = 2; i * i <= number; i++) {
            if (number % i == 0) {
                return Constant.NOT_PRIME_STRING;
            }
        }
        return Constant.PRIME_STRING;
    }

    /*   This program is used to convert a input number to its word conversion
        example. Input: 51 
        Output: "fifty one" 
     */
    public static String numberToWords(int number) {
        if (number == 0) {
            return "zero";
        }
        if (number == 1000) {
            return "one thousand";
        }
        if (number < 0 || number > 1000) {
            return "Number out of range";
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
        Scanner sc = new Scanner(System.in);

        int choice;

        do {
            System.out.print(Constant.OP_STRING);
            choice = sc.nextInt();
            sc.nextLine();

            switch(choice) {
                case 1:
                    System.out.print(Constant.ENTER_STRING);
                    String input1 = sc.nextLine();
                    System.out.println("Expanded: " + expandCharacters(input1));
                    break;
                case 2:
                    System.out.print(Constant.ENTER_STRING);
                    String input2 = sc.nextLine();
                    System.out.println("Character Frequency: " + characterFrequency(input2));
                    break;
                case 3:
                    System.out.print(Constant.ENTER_NUMBER);
                    int num1 = sc.nextInt();
                    System.out.println(isPrime(num1));
                    break;
                case 4:
                    System.out.print(Constant.ENTER_NUMBER);
                    int num2 = sc.nextInt();
                    System.out.println("In words: " + numberToWords(num2));
                    break;
                case 5:
                    System.out.print(Constant.ENTER_STRING);
                    String input3 = sc.nextLine();
                    System.out.println("Length of Longest Unique Substring: " + longestUniqueSubstring(input3));
                    break;
                case 6:
                    System.out.println(Constant.EXIT__STRING);
                    break;
                default:
                    System.out.println(Constant.INVALID_INPUT);
            }
        } while (choice != 6);

        sc.close();
    }
}
