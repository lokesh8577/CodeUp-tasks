// This files provides some of string operations like - append, replace, sort, reverse, palindrome check, count words, splice, split, shift and maximum repeated character in a string.
// Name - Lokesh Prajapat
// Date - 19/9/25

#include <iostream>
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
        vector<int> count(26, 0);
        for (int i = 0; i < input_string.length(); i++)
        {
            count[input_string[i] - 'a']++;
        }
        string result = "";
        for (int i = 0; i < 26; i++)
        {
            result += string(count[i], 'a' + i);
        }
        return result;
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

    /* Check if the string is a palindrome
       Example: Input: "madam"
                Output: true
     */
    bool IsPalindrome(string input_string)
    {
        int n = input_string.length();
        for (int i = 0; i < n / 2; i++)
        {
            if (input_string[i] != input_string[n - i - 1])
            {
                return false;
            }
        }
        return true;
    }

    /* Count words in a string
       Example: Input: "Hello World from C++"
                Output: 4
     */
    int CountWord(string input_string)
    {
        int count = 0;
        for (int i = 0; i < input_string.length(); i++)
        {
            if (input_string[i] == ' ')
            {
                count++;
            }
        }
        return count + 1;
    }

    /* Replace a string with another in a string
       Example: Input: "hello", replace 'll' with 'o'
                Output: "heoo"
     */

    string ReplaceString(string original)
    {
        string from,to;
        cout<<"Enter string which you want to replace from:"<<endl;
        getline(cin,from);
        cout<<"Enter the string which you want to replace to:"<<endl;
        getline(cin,to);
        string result = "";
        int n = original.size();
        int m = from.size();

        for (int i = 0; i < n;)
        {
            bool match = true;

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
        return result;
    }

    /* Remove substring from start index to end index (exclusive)
       Example: Input: "HelloWorld", start=2, end=5
                Output: "HeWorld"
     */
    string SpliceString(string original, int start, int end)
    {
        string output_string = "";
        for (int i = 0; i < original.length(); i++)
        {
            if (i < start || i >= end)
            {
                output_string += original[i];
            }
        }
        return output_string;
    }

    /* Extract substring from start index to end index (exclusive)
       Example: Input: "HelloWorld", start=0, end=5
                Output: "Hello"
     */
    string SplitString(string original, int start, int end)
    {
        string output_string = "";
        for (int i = start; i < end; i++)
        {
            output_string += original[i];
        }
        return output_string;
    }

    /* Shift characters of string by given position (right rotation)
       Example: Input: "Hello", position=2
                Output: "loHel"
     */
    string ShiftString(string original, int position)
    {
        int n = original.length();
        position = position % n;
        string shifted = original.substr(n - position) + original.substr(0, n - position);
        return shifted;
    }

    /* Find the character that repeats the most in the string
       Example: Input: "aabbbcccc"
                Output: 'c'
     */
    char MaximumRepeatedCharacter(string input_string)
    {
        vector<int> count(26, 0);
        for (int i = 0; i < input_string.length(); i++)
        {
            count[input_string[i] - 'a']++;
        }
        int max_count = 0;
        char result;
        for (int i = 0; i < 26; i++)
        {
            if (count[i] > max_count)
            {
                max_count = count[i];
                result = 'a' + i;
            }
        }
        return result;
    }
};

int main()
{
    StringFunctions obj;
    int optionSelector;

    while (true)
    {
        cout << "\nMenu:" << endl;
        cout << "1. Append String" << endl;
        cout << "2. Sort String" << endl;
        cout << "3. Reverse String" << endl;
        cout << "4. Check Palindrome" << endl;
        cout << "5. Count Words" << endl;
        cout << "6. Replace" << endl;
        cout << "7. Splice String" << endl;
        cout << "8. Split String" << endl;
        cout << "9. Shift String" << endl;
        cout << "10. Maximum Repeated Character" << endl;
        cout << "11. Exit" << endl;
        cout << "Choose an option (1-11): ";

        while (!(cin >> optionSelector))
        {
            cout << "Enter a valid option (1-11): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore();

        switch (optionSelector)
        {
        case 1:
        {
            string s1, s2;
            cout << "Enter first string: ";
            getline(cin, s1);
            cout << "Enter second string: ";
            getline(cin, s2);
            cout << "Appended String: " << obj.Append_String(s1, s2) << endl;
            break;
        }

        case 2:
        {
            string input;
            cout << "Enter string (lowercase): ";
            getline(cin, input);
            cout << "Sorted String: " << obj.SortString(input) << endl;
            break;
        }

        case 3:
        {
            string input;
            cout << "Enter string: ";
            getline(cin, input);
            cout << "Reversed String: " << obj.ReverseString(input) << endl;
            break;
        }

        case 4:
        {
            string input;
            cout << "Enter string: ";
            getline(cin, input);
            cout << (obj.IsPalindrome(input) ? "Palindrome" : "Not Palindrome") << endl;
            break;
        }

        case 5:
        {
            string input;
            cout << "Enter sentence: ";
            getline(cin, input);
            cout << "Word Count: " << obj.CountWord(input) << endl;
            break;
        }

        case 6:
        {
            string input;
            cout << "Enter string: ";
            getline(cin, input);
            cout << "Modified String: " << obj.ReplaceString(input) << endl;
            break;
        }

        case 7:
        {
            string input;
            int start, end;
            cout << "Enter string: ";
            getline(cin, input);
            cout << "Enter start index: ";
            cin >> start;
            cout << "Enter end index: ";
            cin >> end;
            cin.ignore();
            cout << "Spliced String: " << obj.SpliceString(input, start, end) << endl;
            break;
        }

        case 8:
        {
            string input;
            int start, end;
            cout << "Enter string: ";
            getline(cin, input);
            cout << "Enter start index: ";
            cin >> start;
            cout << "Enter end index: ";
            cin >> end;
            cin.ignore();
            cout << "Split Part: " << obj.SplitString(input, start, end) << endl;
            break;
        }

        case 9:
        {
            string input;
            int pos;
            cout << "Enter string: ";
            getline(cin, input);
            cout << "Enter shift positions: ";
            cin >> pos;
            cin.ignore();
            cout << "Shifted String: " << obj.ShiftString(input, pos) << endl;
            break;
        }

        case 10:
        {
            string input;
            cout << "Enter string (lowercase): ";
            getline(cin, input);
            cout << "Maximum Repeated Character: " << obj.MaximumRepeatedCharacter(input) << endl;
            break;
        }

        case 11:
            cout << "Exiting program. Goodbye!" << endl;
            return 0;

        default:
            cout << "Invalid choice! Please choose between 1 and 11." << endl;
            break;
        }
    }
}
