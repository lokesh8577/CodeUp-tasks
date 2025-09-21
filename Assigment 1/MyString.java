/* 
    Name - Lokesh Prajapat
    Date - 16/9/25
 */
import java.util.Scanner;

public class MyString {

    /* This method is used to expand characters in an input string with a particular digit
        example. Input: "a1b4c3" 
        Output: "abbbbccc"
     */
    public static String expandCharacters(String str) {
        String expandedResult = "";
        int i = 0;
        while (i < str.length()) {
            char letter = str.charAt(i);
            i++;
            int repeatCount = 0;
            while (i < str.length()) {
                char c = str.charAt(i);
                if (c >= '0' && c <= '9') {
                    repeatCount = repeatCount * 10 + (c - '0');
                    i++;
                } else {
                    break;
                }
            }
            for (int j = 0; j < repeatCount; j++) {
                expandedResult += letter;
            }
        }
        return expandedResult;
    }


    /*  This method is used to print frequency of a character from an input string
        example. Input: "aabcccdeee" 
        Output: "a2b1c3d1e3"
     */
    public static String characterFrequency(String text) {
        if (text == null || text.isEmpty()) {
            return "";
        }

        String frequencyResult = "";

        for (int i = 0; i < text.length(); i++) {
            char currentChar = text.charAt(i);

            boolean alreadyProcessed = false;
            for (int j = 0; j < i; j++) {
                if (text.charAt(j) == currentChar) {
                    alreadyProcessed = true;
                    break;
                }
            }

            if (!alreadyProcessed) {
                int count = 0;
                for (int k = 0; k < text.length(); k++) {
                    if (text.charAt(k) == currentChar) {
                        count++;
                    }
                }
                frequencyResult += currentChar + "" + count;
            }
        }

        return frequencyResult;
    }

    /* This method is used to check whether an input number is a prime number or not
        example. Input: 21 
        Output: "The given number is NOT prime"  
     */
    public static String isPrime(int number) {
        if (number <= 1) {
            return "The given number is NOT prime";
        }

        for (int divisor = 2; divisor*divisor < number/2; divisor++) {
            if (number % divisor == 0) {
                return "The given number is NOT prime";
            }
        }
        return "The given number is PRIME";
    }

    /*   This method is used to convert an input number to its word conversion
        example. Input: 51 
        Output: "fifty one" 
     */
    public static String numberToWords(int number) {
        if (number == 0) {
            return "zero";
        }
        if (number == 1000) {
            return "One thousand";
        }

        String[] singleDigits = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        String[] teenNumbers = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
            "sixteen", "seventeen", "eighteen", "nineteen"};
        String[] tensPlace = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

        String wordResult = "";

        if (number >= 100) {
            wordResult += singleDigits[number / 100] + " hundred";
            number %= 100;
            if (number > 0) {
                wordResult += " ";
            }
        }

        if (number >= 20) {
            wordResult += tensPlace[number / 10];
            number %= 10;
            if (number > 0) {
                wordResult += " ";
            }
        } else if (number >= 10) {
            wordResult += teenNumbers[number - 10];
            number = 0;
        }

        if (number > 0 && number < 10) {
            wordResult += singleDigits[number];
        }

        return wordResult;
    }

    /*  This method is used to print the length of longest substring without repeating characters
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
        Scanner userInput = new Scanner(System.in);
        int optionSelector;

        while (true) {
            System.out.println("\nMenu:");
            System.out.println("1. Expand Characters");
            System.out.println("2. Character Frequency");
            System.out.println("3. Check Prime");
            System.out.println("4. Number to Words");
            System.out.println("5. Longest Unique Substring");
            System.out.println("6. Exit");
            System.out.print("Choose an option (1-6): ");

            while (!userInput.hasNextInt()) {
                System.out.print("Enter a valid option (1-6): ");
                userInput.next();
            }
            optionSelector = userInput.nextInt();
            userInput.nextLine();

            switch (optionSelector) {
                case 1:
                    try {
                        System.out.print("Enter string (e.g. a1b4c3): ");
                        String expandInput = userInput.nextLine();
                        System.out.println("Expanded String: " + expandCharacters(expandInput));
                    } catch (Exception e) {
                        System.out.println("Invalid input! Please enter in correct format like a1b2c3.");
                    }
                    break;

                case 2:
                    try {
                        System.out.print("Enter string: ");
                        String frequencyInput = userInput.nextLine();
                        System.out.println("Character Frequency: " + characterFrequency(frequencyInput));
                    } catch (Exception e) {
                        System.out.println("Error! Please enter a valid string.");
                    }
                    break;

                case 3:
                    try {
                        System.out.print("Enter number: ");
                        if (userInput.hasNextInt()) {
                            int primeInput = userInput.nextInt();
                            userInput.nextLine();
                            System.out.println(isPrime(primeInput));
                        } else {
                            System.out.println("Invalid input! Please enter a valid integer.");
                            userInput.next();
                        }
                    } catch (Exception e) {
                        System.out.println("Error! Please enter a valid integer.");
                    }
                    break;

                case 4:
                    try {
                        System.out.print("Enter number (1-1000): ");
                        if (userInput.hasNextInt()) {
                            int numberInput = userInput.nextInt();
                            userInput.nextLine();
                            if (numberInput < 1 || numberInput > 1000) {
                                System.out.println("Number out of range! Enter between 1 and 1000.");
                            } else {
                                System.out.println("In Words: " + numberToWords(numberInput));
                            }
                        } else {
                            System.out.println("Invalid input! Please enter an integer.");
                            userInput.next();
                        }
                    } catch (Exception e) {
                        System.out.println("Error! Please enter a valid number.");
                    }
                    break;

                case 5:
                    try {
                        System.out.print("Enter string: ");
                        String uniqueInput = userInput.nextLine();
                        System.out.println("Longest Unique Substring Length: " + longestUniqueSubstring(uniqueInput));
                    } catch (Exception e) {
                        System.out.println("Error! Please enter a valid string.");
                    }
                    break;

                case 6:
                    System.out.println("Exiting program. Goodbye!");
                    userInput.close();
                    return; // exit main method

                default:
                    System.out.println("Invalid choice! Please choose between 1 and 6.");
                    break;
            }
        }
    }
}
