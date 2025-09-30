// This files provides some of string operations like - valid parentesis, sum of digits, consecutive sum, caesar cipher encoding, encoded ASCII.
// Name - Lokesh Prajapat
// Date - 30/9/25
#include <iostream>
#include "Constant.h"
using namespace std;

class Operations
{
public:
    /* A function to generate all combinations of valid parentheses
        Example: Input: 3
                    Output: "((()))", "(()())", "(())()", "()(())", "()()()"
    */

    vector<string> ValidParentesis(vector<string> &result, string current, int open, int close, int max)
    {
        if (current.length() == max * 2)
        {
            result.push_back(current);
            return result;
        }

        if (open < max)
            ValidParentesis(result, current + "(", open + 1, close, max);
        if (close < open)
            ValidParentesis(result, current + ")", open, close + 1, max);

        return result;
    }

    /*
        A function to calculate the sum of digits of a number
        Example: Input: 123
                    Output: 6
    */
    int SumOfDigits(int number)
    {
        if (number == 0)
            return 0;
        return (number % 10 + SumOfDigits(number / 10));
    }

    /*
        A function to find the number of ways a given number can be expressed as the sum of consecutive positive integers
        Example: Input: 15
                    Output: 4 (15 = 15, 7+8, 4+5+6, 1+2+3+4+5)
    */
    int ConsecutiveSum(int number)
    {
        int count = 0;
        int doubleNum = 2 * number;

        for (int k = 1; k <= number; k++)
        {
            if (doubleNum % k == 0)
            {
                int temp = doubleNum / k - (k - 1);
                if (temp > 0 && temp % 2 == 0)
                    count++;
            }
        }
        return count;
    }

    /* A function to perform Caesar Cipher encoding on a given string
        Example: Input: "Hello, World!"
                    Output: "Khoor, Zruog!"
    */
    string CaesarCipherEncoding(string text)
    {
        string result = "";
        int shift;
        cout << "Enter the shift value : ";
        cin>> shift;
        for (int i = 0; i < text.length(); i++)
        {
            if (isupper(text[i]))
                result += char(int(text[i] + shift - 65) % 26 + 65);
            else if (islower(text[i]))
                result += char(int(text[i] + shift - 97) % 26 + 97);
            else
                result += text[i];
        }
        return result;
    }
    /* A function to encode the ASCII values of characters in a string by shifting them by a given series value
        Example: Input: "abc", series = 2
                    Output: "cde"
    */
    vector<char> EncodedASCII(vector<char> &result, int series)
    {
        for (int i = 0; i < result.size(); i++)
        {
            result[i] = char(int(result[i]) + series);
        }
        return result;
    }
};


int main()
{
    Operations obj;
    int optionSelector;

    do
    {
        cout << OP_MENU;

        while (!(cin >> optionSelector))
        {
            cout << INVALID_OPTION;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore();

        switch (optionSelector)
        {
        case 1:
        {
            int number;
            cout << "Enter a positive integer (1-8): ";
            while (!(cin >> number) || number < 1 || number > 8)
            {
                cout << VALID_POSITIVE_INT;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore();

            vector<string> result;
            result = obj.ValidParentesis(result, "", 0, 0, number);
            cout << "Valid Parentheses combinations are:\n";
            for (const string &s : result)
            {
                cout << s << "\n";
            }
            break;
        }
        case 2:
        {
            int number;
            cout << ENTER_NUMBER;
            while (!(cin >> number) || number < 1)
            {
                cout << VALID_INT;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore();

            int sum = obj.SumOfDigits(number);
            cout << "Sum of digits: " << sum << "\n";
            break;
        }
        case 3:
        {
            int number;
            cout << ENTER_NUMBER;
            while (!(cin >> number) || number < 1)
            {
                cout << VALID_INT;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore();

            int ways = obj.ConsecutiveSum(number);
            cout << "Number of ways to express " << number
                 << " as the sum of consecutive positive integers: " << ways << "\n";
            break;
        }
        case 4:
        {
            string text;
            cout << ENTER_STRING;
            getline(cin, text);

            string encodedText = obj.CaesarCipherEncoding(text);
            cout << "Encoded string using Caesar Cipher: " << encodedText << "\n";
            break;
        }
        case 5:
        {
            int size;
            cout << ENTER_CHAR_SIZE;
            while (!(cin >> size) || size < 1)
            {
                cout << VALID_INT;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore();

            vector<char> charArray(size);
            cout << ENTER_CHAR;
            for (int i = 0; i < size; i++)
            {
                cin >> charArray[i];
            }
            cin.ignore();

            int series;
            cout << "Enter the series value to shift ASCII values: ";
            while (!(cin >> series))
            {
                cout << "Please enter a valid integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore();

            vector<char> encodedArray = obj.EncodedASCII(charArray, series);
            cout << "Encoded ASCII character array: ";
            for (char c : encodedArray)
            {
                cout << c;
            }
            cout << "\n";
            break;
        }
        case 6:
            cout << EXITING_STRING << "\n";
            return 0;

        default:
            cout << INVALID_OPTION << "\n";
            break;
        }

    } while (true);

    return 0;
}
