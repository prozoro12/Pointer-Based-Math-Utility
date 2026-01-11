#include <iostream>
#include <limits>   // Required for numeric_limits
using namespace std;

/*
    Checks whether valid input exists.
    - arr must not be nullptr
    - size must be greater than 0

    Returns:
    - true  > input is valid
    - false > input not yet provided
*/
bool isInput(const float* arr, int size) {
    if (arr == nullptr || size <= 0) {
        cout << "Please enter numbers first\n\n";
        return false;
    }
    return true;
}

/*
    Takes input from the user and stores it
    in a dynamically allocated array using
    pointer arithmetic.
*/
void inputNumbers(float* arr, int size) {
    float numIn;

    for (int i = 0; i < size; i++) {
        cout << "Enter Number " << i + 1 << ": ";
        cin >> numIn;

        // Store value using pointer arithmetic
        *(arr + i) = numIn;
    }
    cout << endl;
}

/*
    Displays all numbers stored in the array.
    Uses pointer arithmetic instead of arr[i].
*/
void displayNumbers(const float* arr, int size) {
    if (isInput(arr, size)) {
        for (int i = 0; i < size; i++) {
            cout << *(arr + i) << endl;
        }
        cout << endl;
    }
}

/*
    Finds and returns the maximum value
    in the dynamically allocated array.
*/
float findMax(const float* arr, int size) {
    if (!isInput(arr, size)) {
        return 0.0f;   // Safe fallback value
    }

    // Initialize max with first element
    float max = *arr;

    for (int i = 1; i < size; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }

    return max;
}

/*
    Finds and returns the minimum value
    in the dynamically allocated array.
*/
float findMin(const float* arr, int size) {
    if (!isInput(arr, size)) {
        return 0.0f;
    }

    float min = *arr;

    for (int i = 1; i < size; i++) {
        if (*(arr + i) < min) {
            min = *(arr + i);
        }
    }

    return min;
}

/*
    Calculates and returns the average
    of all values in the array.
*/
double findAverage(const float* arr, int size) {
    if (!isInput(arr, size)) {
        return 0.0;
    }

    double sum = 0.0;

    for (int i = 0; i < size; i++) {
        sum += *(arr + i);
    }

    // Average = total sum / number of elements
    return sum / size;
}

int main() {
    bool running = true;     // Controls program loop
    int ans;                 // Menu choice
    int size = 0;            // Number of elements
    float* numbers = nullptr; // Pointer to heap memory

    while (running) {

        // Display menu
        cout << "1. Enter numbers\n"
            << "2. Display numbers\n"
            << "3. Find maximum\n"
            << "4. Find minimum\n"
            << "5. Calculate average\n"
            << "6. Exit\n";
        cout << "ANS: ";

        cin >> ans;

        // Input validation for menu choice
        if (cin.fail()) {
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nERROR: PLEASE ENTER VALID INPUT!\n\n";
            continue;
        }

        cout << endl;

        if (ans == 6) {
            // Exit program
            running = false;
        }
        else if (ans == 1) {
            // Input number of elements
            cout << "How many numbers do you wish to enter: ";
            cin >> size;
            cout << endl;

            if (size <= 0) {
                cout << "ERROR: PLEASE ENTER A POSITIVE SIZE!\n\n";
                continue;
            }

            // Free old memory (prevents memory leak)
            delete[] numbers;
            numbers = nullptr;

            // Allocate new memory on heap
            numbers = new float[size];

            // Fill array
            inputNumbers(numbers, size);
        }
        else if (ans == 2) {
            displayNumbers(numbers, size);
        }
        else if (ans == 3) {
            if (isInput(numbers, size)) {
                cout << "The largest number is "
                    << findMax(numbers, size) << "\n\n";
            }
        }
        else if (ans == 4) {
            if (isInput(numbers, size)) {
                cout << "The smallest number is "
                    << findMin(numbers, size) << "\n\n";
            }
        }
        else if (ans == 5) {
            if (isInput(numbers, size)) {
                cout << "The average value is "
                    << findAverage(numbers, size) << "\n\n";
            }
        }
    }

    // Final cleanup before program exit
    delete[] numbers;
    numbers = nullptr;

    return 0;
}
