// This file provides some of array operations like -
// Find Pivot Index, Paint House, Check Pair Sum, Find Unique Element, City Travel, Binary Conversion
// Name - Lokesh Prajapat
// Date - 03/11/25

#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
#include <algorithm>
#include "constants.h"
using namespace std;

class ArrayOperations
{
public:
    /*
    A function to find pivot index where sum of elements on left and right are equal (excluding that element)
    Example: [2, 3, -1, 8, 4]
    Output: 3 (index 3 -> value 8)
    */

    int findPivotIndex(vector<int> inputArray)
    {
        int totalSum = 0;
        for (int num : inputArray)
            totalSum += num;

        int leftSum = 0;
        for (int i = 0; i < inputArray.size(); i++)
        {
            int rightSum = totalSum - leftSum - inputArray[i];
            if (leftSum == rightSum)
                return i;
            leftSum += inputArray[i];
        }
        return -1;
    }

    /* A function that sums all elements except the maximum one.
       Example: [2, 4, 6, 3] → Output: 9 (2 + 4 + 3)
    */
    int paint(vector<int> inputArray)
    {
        int maxValue = INT_MIN;
        for (int num : inputArray)
            maxValue = max(maxValue, num);

        int sum = 0;
        bool maxRemoved = false;

        for (int num : inputArray)
        {
            if (num == maxValue && !maxRemoved)
            {
                maxRemoved = true;
                continue;
            }
            sum += num;
        }
        return sum;
    }

    /* A function to check if there exists a pair of elements whose sum equals targetValue
       Example: [1, 4, 7, 9], targetValue = 13 → Output: true (4 + 9)
    */
    bool hasPairWithSum(vector<int> inputArray, int targetValue)
    {
        unordered_set<int> seenNumbers;

        for (int num : inputArray)
        {
            int complement = targetValue - num;
            if (seenNumbers.find(complement) != seenNumbers.end())
                return true;
            seenNumbers.insert(num);
        }
        return false;
    }

    /* A function to find the unique element where every other element appears twice
       Example: [2, 3, 5, 4, 5, 3, 2] → Output: 4
    */
    int findUniqueElement(vector<int> inputArray)
    {
        int result = 0;
        for (int num : inputArray)
            result ^= num;
        return result;
    }

    /* A function to find how many cities can be visited with given energy
       Example: inputArray = [2,3,1,4,2], energy = 7 → Output: 3
    */
    int cityTravel(vector<int> inputArray, int initialEnergy)
    {
        for (int i = 0; i < inputArray.size(); i++)
        {
            if (initialEnergy - inputArray[i] >= 0)
                initialEnergy -= inputArray[i];
            else
                return i;
        }
        return inputArray.size();
    }

    /* A function to count the minimum number of flips required
       to make all elements equal in a binary array (0s and 1s)
       Example: [0, 0, 1, 1, 1] → Output: 2
    */
    int countMinFlips(vector<int> inputArray)
    {
        int zeroCount = 0, oneCount = 0;

        for (int num : inputArray)
        {
            if (num == 0)
                zeroCount++;
            else
                oneCount++;
        }
        return min(zeroCount, oneCount);
    }
};

class Point
{
    float x, y;

public:
    Point(float xCoord = 0, float yCoord = 0)
        : x(xCoord), y(yCoord) {}

    float calculateDistance(float xPoint, float yPoint)
    {
        float dx = (xPoint - x);
        float dy = (yPoint - y);
        return sqrt(dx * dx + dy * dy);
    }

    void translate(float newX, float newY)
    {
        x = newX;
        y = newY;
    }

    void display() const
    {
        cout << "(" << x << ", " << y << ")";
    }
};

class Shape
{
public:
    virtual float getArea() = 0;
};

class Circle : public Shape
{
    float radius;

public:
    Circle(float radiusValue)
        : radius(radiusValue) {}

    float getArea() override
    {
        return 3.14159f * radius * radius;
    }
};

class Square : public Shape
{
    float side;

public:
    Square(float sideValue)
        : side(sideValue) {}

    float getArea() override
    {
        return side * side;
    }
};

void GeometryOperations()
{
    float x1, x2, y1, y2;
    float translateX, translateY;
    float squareSide, circleRadius;

    cout << ENTER_POINT1;
    x1 = getValidFloat();
    y1 = getValidFloat();

    cout << ENTER_POINT2;
    x2 = getValidFloat();
    y2 = getValidFloat();

    cout << ENTER_CIRCLE_RADIUS;
    while (true)
    {
        circleRadius = getValidFloat();
        if (circleRadius > 0)
            break;
        cout << POSITIVE_RADIUS_ERR;
    }

    cout << ENTER_SQUARE_SIDE;
    while (true)
    {
        squareSide = getValidFloat();
        if (squareSide > 0)
            break;
        cout << POSITIVE_SIDE_ERR;
    }

    cout << ENTER_TRANSLATE;
    translateX = getValidFloat();
    translateY = getValidFloat();

    Point pointObj(x1, y1);
    Circle circleObj(circleRadius);
    Square squareObj(squareSide);

    float distance = pointObj.calculateDistance(x2, y2);
    float circleArea = circleObj.getArea();
    float squareArea = squareObj.getArea();

    pointObj.translate(translateX, translateY);

    cout << GEO_RESULTS_HEADER;
    cout << DIST_LABEL << distance << endl;
    cout << CIRCLE_AREA_LABEL << circleArea << endl;
    cout << SQUARE_AREA_LABEL << squareArea << endl;
    cout << TRANSLATED_LABEL;
    pointObj.display();
    cout << endl;
}

// Validate float input
float getValidFloat()
{
    float value;
    while (true)
    {
        if (cin >> value)
            return value;

        cout << "❌ Invalid input! Enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Validate integer input
int getValidInt()
{
    int x;
    while (true)
    {
        if (cin >> x)
            return x;

        cout << "❌ Invalid input! Enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main()
{
    ArrayOperations arrayOps;
    int menuChoice;

    do
    {
        cout << APP_TITLE;
        cout << MENU_OPTION_1 << endl;
        cout << MENU_OPTION_2 << endl;
        cout << MENU_OPTION_3 << endl;
        cout << MENU_OPTION_4 << endl;
        cout << MENU_OPTION_5 << endl;
        cout << MENU_OPTION_6 << endl;
        cout << MENU_OPTION_7 << endl;
        cout << MENU_OPTION_8 << endl;
        cout << MENU_SELECT;

        menuChoice = getValidInt();

        switch (menuChoice)
        {
        case 1:
        {
            cout << ENTER_ARRAY_SIZE;
            int n = getValidInt();

            vector<int> arr(n);
            cout << ENTER_ELEMENTS;
            for (int i = 0; i < n; i++)
                arr[i] = getValidInt();

            cout << "Pivot Index = " << arrayOps.findPivotIndex(arr) << "\n";
            break;
        }

        case 2:
        {
            cout << ENTER_ARRAY_SIZE;
            int n = getValidInt();

            vector<int> arr(n);
            cout << ENTER_ELEMENTS;
            for (int i = 0; i < n; i++)
                arr[i] = getValidInt();

            cout << "Sum Except Max = " << arrayOps.paint(arr) << "\n";
            break;
        }

        case 3:
        {
            cout << ENTER_ARRAY_SIZE;
            int n = getValidInt();

            vector<int> arr(n);
            cout << ENTER_ELEMENTS;
            for (int i = 0; i < n; i++)
                arr[i] = getValidInt();

            cout << ENTER_TARGET_SUM;
            int target = getValidInt();

            cout << "Pair Exists: "
                 << (arrayOps.hasPairWithSum(arr, target) ? "Yes" : "No") << "\n";
            break;
        }

        case 4:
        {
            cout << ENTER_ARRAY_SIZE;
            int n = getValidInt();

            vector<int> arr(n);
            cout << ENTER_ELEMENTS;
            for (int i = 0; i < n; i++)
                arr[i] = getValidInt();

            cout << "Unique Element = " << arrayOps.findUniqueElement(arr) << "\n";
            break;
        }

        case 5:
        {
            cout << ENTER_ARRAY_SIZE;
            int n = getValidInt();

            vector<int> arr(n);
            cout << ENTER_ELEMENTS;
            for (int i = 0; i < n; i++)
                arr[i] = getValidInt();

            cout << ENTER_ENERGY;
            int energy = getValidInt();

            cout << "Cities Visited = " << arrayOps.cityTravel(arr, energy) << "\n";
            break;
        }

        case 6:
        {
            cout << ENTER_ARRAY_SIZE;
            int n = getValidInt();

            vector<int> arr(n);
            cout << ENTER_BINARY_MSG;
            for (int i = 0; i < n; i++)
            {
                while (true)
                {
                    arr[i] = getValidInt();
                    if (arr[i] == 0 || arr[i] == 1)
                        break;
                    cout << "❌ Only 0 or 1 allowed. Try again: ";
                }
            }

            cout << "Minimum Flips = " << arrayOps.countMinFlips(arr) << "\n";
            break;
        }

        case 7:
        {
            cout << GEO_START;
            GeometryOperations();
            break;
        }

        case 8:
            cout << EXIT_MESSAGE;
            return 0;

        default:
            cout << INVALID_OPTION_MSG;
            break;
        }

    } while (true);

    return 0;
}
