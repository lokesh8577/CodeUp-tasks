/* 
    Name - Lokesh Prajapat
    Date - 16/9/25
 */

public class MyString {

    /* This program is used to expand characters in an input string with a particular digit
        example. Input: "a1b4c3" 
        Output: "abbbbccc"
     */
    public static String expandCharacters(String str) {
        String expandedResult = "";

        for (int pos = 0; pos < str.length(); pos += 2) {
            char letter = str.charAt(pos);
            int repeatCount = str.charAt(pos + 1) - '0';

            for (int repetition = 0; repetition < repeatCount; repetition++) {
                expandedResult += letter;
            }
        }
        return expandedResult;
    }

    /*  This program is used to print frequency of a character from an input string
        example. Input: "aabcccdeee" 
        Output: "a2b1c3d1e3"
     */
    public static String characterFrequency(String text) {
        String frequencyResult = "";
        int charCount = 1;

        for (int index = 0; index < text.length(); index++) {
            if (index + 1 < text.length() && text.charAt(index) == text.charAt(index + 1)) {
                charCount++;
            } else {
                frequencyResult += text.charAt(index) + "" + charCount;
                charCount = 1;
            }
        }
        return frequencyResult;
    }

    /* This program is used to check whether an input number is a prime number or not
        example. Input: 21 
        Output: "The given number is NOT prime"  
     */
    public static String isPrime(int num) {
        if (num <= 1) {
            return "The given number is NOT prime";
        }

        for (int divisor = 2; divisor * divisor <= num; divisor++) {
            if (num % divisor == 0) {
                return "The given number is NOT prime";
            }
        }
        return "The given number is PRIME";
    }

    /*   This program is used to convert an input number to its word conversion
        example. Input: 51 
        Output: "fifty one" 
     */
    public static String numberToWords(int num) {
        if (num == 0) {
            return "zero";
        }

        String[] singleDigits = {"","one","two","three","four","five","six","seven","eight","nine"};
        String[] teenNumbers = {"ten","eleven","twelve","thirteen","fourteen","fifteen",
            "sixteen","seventeen","eighteen","nineteen"};
        String[] tensPlace = {"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};

        String wordResult = "";

        if (num >= 100) {
            wordResult += singleDigits[num / 100] + " hundred";
            num %= 100;
            if (num > 0) {
                wordResult += " ";
            }
        }

        if (num >= 20) {
            wordResult += tensPlace[num / 10];
            num %= 10;
            if (num > 0) {
                wordResult += " ";
            }
        } else if (num >= 10) {
            wordResult += teenNumbers[num - 10];
            num = 0;
        }

        if (num > 0 && num < 10) {
            wordResult += singleDigits[num];
        }

        return wordResult;
    }

    /*  This program is used to print the length of longest substring without repeating characters
        example. input: s = "abcabcbb" 
        Output: 3 
     */
    public static int longestUniqueSubstring(String str) {
        int[] lastSeenAt = new int[256];
        for (int idx = 0; idx < 256; idx++) {
            lastSeenAt[idx] = -1;
        }

        int maxLen = 0;
        int windowStart = -1;

        for (int currentPos = 0; currentPos < str.length(); currentPos++) {
            if (lastSeenAt[str.charAt(currentPos)] > windowStart) {
                windowStart = lastSeenAt[str.charAt(currentPos)];
            }
            lastSeenAt[str.charAt(currentPos)] = currentPos;
            maxLen = Math.max(maxLen, currentPos - windowStart);
        }
        return maxLen;
    }

    public static void main(String[] args) {
        System.out.println(expandCharacters("a1b4c3"));
        System.out.println(characterFrequency("aabcccdeee"));
        System.out.println(isPrime(7));
        System.out.println(numberToWords(848));
        System.out.println(longestUniqueSubstring("abcabcbb"));
    }
}
