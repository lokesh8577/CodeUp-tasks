// This files provides some of string operations like - append, replace, sort, reverse of string.
// Name - Lokesh Prajapat
// Date - 19/9/25

#include <iostream>
#include "Constant.h"
using namespace std;

class StringFunctions
{
public:
    /* Append one string to another
       Example: Input: "Hello", "World"
                Output: "Hello World"
     */
    string Append_String(string original, string toAdd)
    {
        return original + " " + toAdd;
    }

    /* Sort characters of the string alphabetically
       Example: Input: "dcba"
                Output: "abcd"
     */
    string SortString(string input_string)
    {
        int n = input_string.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (input_string[j] > input_string[j + 1])
                {
                    char temp = input_string[j];
                    input_string[j] = input_string[j + 1];
                    input_string[j + 1] = temp;
                }
            }
        }
        return input_string;
    }

    /* Reverse a string
       Example: Input: "Hello"
                Output: "olleH"
     */
    string ReverseString(string input_string)
    {
        int n = input_string.length();
        for (int i = 0; i < n / 2; i++)
        {
            swap(input_string[i], input_string[n - i - 1]);
        }
        return input_string;
    }

    /* Replace a string with another in a string
       Example: Input: "hello", replace 'll' with 'o'
                Output: "heoo"
     */

    string ReplaceChar(string original)
    {
        string from;
        char to;

        cout << "Enter substring you want to replace from: ";
        getline(cin, from);

        cout << "Enter the character you want to replace to: ";
        cin >> to;

        string result = "";
        int n = original.size();
        int m = from.size();

        for (int i = 0; i < n;)
        {
            bool match = true;

            // check if substring matches
            for (int j = 0; j < m; j++)
            {
                if (i + j >= n || original[i + j] != from[j])
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                result += to;
                i += m;
            }
            else
            {
                result += original[i];
                i++;
            }
        }
        cout << MODIFIED_STRING;
        return result;
    }
};

int main()
{
    StringFunctions obj;
    int optionSelector;

    while (true)
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
            string s1, s2;
            cout << ENTER_FIRST_STRING;
            getline(cin, s1);
            cout << ENTER_SECOND_STRING;
            getline(cin, s2);
            cout << APPENDED_STRING << obj.Append_String(s1, s2) << endl;
            break;
        }

        case 2:
        {
            string input;
            cout << ENTER_STRING;
            getline(cin, input);
            cout << SORTED_STRING << obj.SortString(input) << endl;
            break;
        }

        case 3:
        {
            string input;
            cout << ENTER_STRING;
            getline(cin, input);
            cout << REVERSED_STRING << obj.ReverseString(input) << endl;
            break;
        }
        case 4:
        {
            string input;
            cout << ENTER_STRING;
            getline(cin, input);
            cout << obj.ReplaceChar(input) << endl;
            break;
        }

        case 5:
            cout << EXITING_STRING << endl;
            return 0;

        default:
            cout << INVALID_OPTION << endl;
            break;
        }
    }
}
