#include<iostream>
#include <vector>
using namespace std;

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[low]; // Choose the first element as pivot
        int i = low + 1;
        int j = high;

        while(i <= j) {
            while(i <= j && arr[i] <= pivot) {
                i++;
            }
            while(j >= i && arr[j] > pivot) {
                j--;
            }
            if(i < j) {
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[j], arr[low]);

        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;      
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}