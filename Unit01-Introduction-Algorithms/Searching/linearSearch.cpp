#include<iostream>
using namespace std;

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; 
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;

    int result = linearSearch(arr, n, x);
    if (result != -1) {
        cout << x<< " found at index: " << result << endl;
    } else {
        cout << x<< " not found in the array." << endl;
    }

    x = 10;
    result = linearSearch(arr, n, x);
    if (result != -1) {
        cout << x<< " found at index: " << result << endl;
    } else {
        cout << x<< "  not found in the array." << endl;
    }
    return 0;
}
