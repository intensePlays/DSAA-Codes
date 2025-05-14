#include <iostream>
#include <climits>
using namespace std;

// Structure to hold min and max
struct MinMax {
    int min;
    int max;
};

// Divide and conquer function
MinMax findMinMax(int arr[], int low, int high) {
    MinMax result, left, right;

    // If there's only one element
    if (low == high) {
        result.min = result.max = arr[low];
        return result;
    }

    // If there are two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    // If more than two elements
    int mid = (low + high) / 2;
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}

// Main driver
int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of elements!" << endl;
        return 1;
    }

    int arr[n];  // Using VLA (works in C++11 and above compilers like GCC)

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    MinMax result = findMinMax(arr, 0, n - 1);

    cout << "\nMinimum element: " << result.min << endl;
    cout << "Maximum element: " << result.max << endl;

    return 0;
}
