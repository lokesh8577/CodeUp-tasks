// This file includes solution of Week Story - 2.5
// Name : Lokesh Kumar
// Date : 19/12/25

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <climits>
using namespace std;

/* Utility function to safely take integer input */
int getSafeInt() {
    int value;
    while (true) {
        cin >> value;
        if (!cin.fail()) {
            return value;
        }
        cout << "Invalid input! Please enter a number: ";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
}

/* 
   Problem 1 : Cosmic Courier
 */
int findSecondLargest(vector<int>& numbers) {
    if (numbers.size() <= 1) return numbers[0];

    int maxValue = INT_MIN;
    int secondMaxValue = INT_MIN;

    for (int value : numbers) {
        if (value > maxValue) {
            secondMaxValue = maxValue;
            maxValue = value;
        } else if (value > secondMaxValue && value < maxValue) {
            secondMaxValue = value;
        }
    }

    return (secondMaxValue == INT_MIN) ? maxValue : secondMaxValue;
}

/* 
   Problem 2 : Digital Library
 */
class Library {
    vector<string> bookList;

public:
    void addBook(const string& book) {
        bookList.push_back(book);
    }

    bool isSubstring(const string& mainStr, const string& subStr) {
        for (int i = 0; i + subStr.size() <= mainStr.size(); i++) {
            int j = 0;
            while (j < subStr.size() && mainStr[i + j] == subStr[j]) {
                j++;
            }
            if (j == subStr.size()) return true;
        }
        return false;
    }

    void searchPartial(const string& query) {
        bool found = false;
        for (const string& book : bookList) {
            if (isSubstring(book, query)) {
                cout << "Book(\"" << book << "\")" << endl;
                found = true;
            }
        }
        if (!found) cout << "[]" << endl;
    }
};

/* 
   Problem 3 : Factory Floor
 */
vector<string> processFactoryItems(vector<int>& items) {
    vector<string> result(items.size());

    for (int i = 0; i < items.size(); i++) {
        if (items[i] % 15 == 0) result[i] = "Hazardous";
        else if (items[i] % 3 == 0) result[i] = "Heavy";
        else if (items[i] % 5 == 0) result[i] = "Fragile";
        else result[i] = to_string(items[i]);
    }
    return result;
}

/* 
   Problem 4 : Spy Cipher
 */
char findExtraCharacter(const string& original, const string& modified) {
    unordered_map<char, int> frequency;

    for (char c : original) frequency[c]++;
    for (char c : modified) {
        frequency[c]--;
        if (frequency[c] < 0) return c;
    }
    return ' ';
}

/* 
   Problem 5 : Corporate Bonus
 */
class Employee {
protected:
    double baseSalary;

public:
    Employee(double salary) {
        if (salary < 0) throw invalid_argument("Salary cannot be negative");
        baseSalary = salary;
    }

    virtual double calculateBonus() {
        return 0.10 * baseSalary;
    }
};

class Manager : public Employee {
public:
    Manager(double salary) : Employee(salary) {}
    double calculateBonus() override {
        return 0.25 * baseSalary + 5000;
    }
};

class Executive : public Manager {
public:
    Executive(double salary) : Manager(salary) {}
    double calculateBonus() override {
        return 0.50 * baseSalary + 10000;
    }
};

double calculateTotalBonus(vector<Employee*>& employees) {
    double total = 0;
    for (Employee* emp : employees) {
        total += emp->calculateBonus();
    }
    return total;
}

/* 
   Problem 6 : Security Log
 */
int calculateRangeSum(vector<int>& data, int start, int end) {
    if (start < 0 || end >= data.size() || start > end) {
        throw out_of_range("Invalid range");
    }

    int sum = 0;
    for (int i = start; i <= end; i++) sum += data[i];
    return sum;
}

/* 
   Problem 7 : Concert Seat
 */
string findDuplicateSeat(vector<vector<string>>& records) {
    unordered_set<int> seats;

    for (auto& r : records) {
        int seat = stoi(r[1]);
        if (seats.count(seat)) return r[0];
        seats.insert(seat);
    }
    return "-1";
}

/* 
   Problem 8 : Weather Station
 */
int countRecordBreakingDays(vector<int>& temperatures) {
    if (temperatures.empty()) return 0;

    int maxTemp = temperatures[0];
    int count = 1;

    for (int i = 1; i < temperatures.size(); i++) {
        if (temperatures[i] > maxTemp) {
            maxTemp = temperatures[i];
            count++;
        }
    }
    return count;
}

/* 
   Main Function
 */
int main() {
    Library library;
    bool isRunning = true;

    while (isRunning) {
        cout << "\nEnter choice:\n";
        cout << "1 Cosmic Courier\n2 Digital Library\n3 Factory Floor\n";
        cout << "4 Spy Cipher\n5 Corporate Bonus\n6 Security Log\n";
        cout << "7 Concert Seat\n8 Weather Station\n0 Exit\n";

        int choice = getSafeInt();

        try {
            switch (choice) {

                case 1: {
                    int n = getSafeInt();
                    vector<int> nums(n);
                    for (int& x : nums) x = getSafeInt();
                    cout << findSecondLargest(nums) << endl;
                    break;
                }

                case 2: {
                    int n = getSafeInt();
                    cin.ignore();
                    for (int i = 0; i < n; i++) {
                        string book;
                        getline(cin, book);
                        library.addBook(book);
                    }
                    string query;
                    getline(cin, query);
                    library.searchPartial(query);
                    break;
                }

                case 3: {
                    int n = getSafeInt();
                    vector<int> items(n);
                    for (int& x : items) x = getSafeInt();
                    auto result = processFactoryItems(items);
                    for (auto& s : result) cout << s << " ";
                    cout << endl;
                    break;
                }

                case 4: {
                    string a, b;
                    cin >> a >> b;
                    cout << findExtraCharacter(a, b) << endl;
                    break;
                }

                case 5: {
                    int n = getSafeInt();
                    vector<Employee*> employees;

                    for (int i = 0; i < n; i++) {
                        int type = getSafeInt();
                        double salary;
                        cin >> salary;

                        if (type == 1) employees.push_back(new Employee(salary));
                        else if (type == 2) employees.push_back(new Manager(salary));
                        else employees.push_back(new Executive(salary));
                    }

                    cout << calculateTotalBonus(employees) << endl;
                    break;
                }

                case 6: {
                    int n = getSafeInt();
                    vector<int> logs(n);
                    for (int& x : logs) x = getSafeInt();
                    int start = getSafeInt();
                    int end = getSafeInt();
                    cout << calculateRangeSum(logs, start, end) << endl;
                    break;
                }

                case 7: {
                    int n = getSafeInt();
                    vector<vector<string>> records(n, vector<string>(2));
                    for (int i = 0; i < n; i++) {
                        cin >> records[i][0] >> records[i][1];
                    }
                    cout << findDuplicateSeat(records) << endl;
                    break;
                }

                case 8: {
                    int n = getSafeInt();
                    vector<int> temp(n);
                    for (int& t : temp) t = getSafeInt();
                    cout << countRecordBreakingDays(temp) << endl;
                    break;
                }

                case 0:
                    isRunning = false;
                    break;

                default:
                    cout << "Invalid choice! Try again.\n";
            }
        }
        catch (exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    cout << "Thank You\n";
    return 0;
}
