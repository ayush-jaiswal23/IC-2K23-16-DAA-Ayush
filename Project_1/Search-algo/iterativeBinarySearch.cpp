#include<iostream>
using namespace std;

int iterativeBinarySearch(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return mid; 
        }
        if (arr[mid] < x) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    return -1; 
}
int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;

    int result = iterativeBinarySearch(arr, n, x);
    if (result != -1) {
        cout << x << " found at index: " << result << endl;
    } else {
        cout << x << " not found in the array." << endl;
    }

    x = 10;
    result = iterativeBinarySearch(arr, n, x);
    if (result != -1) {
        cout << x << " found at index: " << result << endl;
    } else {
        cout << x << " not found in the array." << endl;
    }
    return 0;
}