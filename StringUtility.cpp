// This files provides some of string operations like - Count Unique Palindrome, Fibonacci, Snake to Camel, Count Consonants, Binary to Decimal
// Name - Lokesh Prajapat
// Date - 07/10/25

#include <iostream>
#include <set>
#include "StringConstant.h"
using namespace std;

class StringOperations
{
public:
    /* A function to check if a string is palindrome or not
    Example Input: "aba"
    output: true
    */
    bool isPalindrome(string str)
    {
        int start = 0, end = str.size() - 1;
        while (start <= end)
        {
            if (str[start] != str[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    /* A function to count unique palindrome in a given string
    Example Input: "ababa"
    output: 3 (aba, bab, ababa)
    */
    int CountUniquePalindrome(string input_string)
    {
        set<string> uniquePalindromes;
        for (int i = 0; i < input_string.size(); i++)
        {
            for (int j = i + 2; j < input_string.size(); j++)
            {
                string sub = input_string.substr(i, j - i + 1);
                if (isPalindrome(sub))
                    uniquePalindromes.insert(sub);
            }
        }
        return uniquePalindromes.size();
    }

    /* A function to find nth number in Fibonacci sequence
    Example Input: 5
    output: 5 (0, 1, 1, 2, 3, 5)
    */
    int Fibbonacci(int number)
    {
        if (number < 2)
            return number;
        long long int number1 = 0;
        long long int number2 = 1;
        for (int i = 2; i <= number; i++)
        {
            long long int sum = number1 + number2;
            number1 = number2;
            number2 = sum;
        }
        return number2;
    }

    /* A function to convert snake_case string to camelCase string
    Example Input: "hello_world"
    output: "helloWorld"
    */
    string SnakeToCamel(string input_string)
    {
        string result_string = "";

        for (int i = 0; i < input_string.size(); i++)
        {
            if (input_string[i] == '_')
            {
                if (i + 1 < input_string.size() && isalpha(input_string[i + 1]))
                {
                    i++;
                    char ch = input_string[i] - 32;
                    result_string += ch;
                }
            }
            else
            {
                result_string += input_string[i];
            }
        }
        return result_string;
    }

    /* A function to count consonants in a given string
    Example Input: "hello world"
    output: 7 (h, l, l, w, r, l, d)
    */
    int CountConstant(string input_string)
    {
        vector<int> temp(26, 0);
        for (int i = 0; i < input_string.size(); i++)
        {
            int index = input_string[i] - 'a' + 1;
            temp[index]++;
        }
        int count = 0;
        for (int i = 0; i < 26; i++)
        {
            if (temp[i] > 0)
                count++;
        }
        return count;
    }

    /* A function to convert binary string to decimal number
    Example Input: "101"
    output: 5
    */
    int BinaryToDecimal(string input_string)
    {
        int ans = 0;
        int power = 0;
        for (int i = input_string.size() - 1; i >= 0; i--)
        {
            if (input_string[i] == '0')
            {
                power++;
                continue;
            }
            else
            {
                int number = input_string[i] - '0';
                ans += pow(2, power);
                power++;
            }
        }
        return ans;
    }
};

int main()
{
    StringOperations obj;
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
            string text;
            cout << ENTER_STRING;
            getline(cin, text);
            int result = obj.CountUniquePalindrome(text);
            cout << "The number of unique palindrome is - " << result << "\n";
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

            cout << "The " << number << "th number in the Fibonacci sequence is - " << obj.Fibbonacci(number) << "\n";
            break;
        }
        case 3:
        {
            string text;
            cout << ENTER_STRING;
            getline(cin, text);
            string result = obj.SnakeToCamel(text);
            cout << "The camelCase format is - " << result << "\n";
            break;
        }
        case 4:
        {
            string text;
            bool valid = false;
            do
            {
                cout << ENTER_STRING;
                getline(cin, text);
                valid = !text.empty() && text.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") == string::npos;
                if (!valid)
                {
                    cout << "Please enter alphabets only.\n";
                }
            } while (!valid);
            cout << "The number of consonants is - " << obj.CountConstant(text) << "\n";
            break;
        }
        case 5:
        {
            string text;
            bool valid = false;
            do
            {
                cout << ENTER_STRING;
                getline(cin, text);
                valid = !text.empty() && text.find_first_not_of("01") == string::npos;
                if (!valid)
                {
                    cout << "Please enter a valid binary number (only 0 and 1).\n";
                }
            } while (!valid);
            cout << "The Decimal of given binary is - " << obj.BinaryToDecimal(text) << "\n";
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