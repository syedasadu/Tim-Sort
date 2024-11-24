#include <iostream>
using namespace std;

int min(int a, int b) {
    return (a < b) ? a : b;
}

// Insertion Sort for small Data
void insertionSort(int* arr, int left, int right) {
    cout << "Performing Insertion Sort on range [" << left << ", " << right << "]: " << endl;
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;

            for (int i = left; i <= right; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        arr[j + 1] = key;
    }

    for (int i = left; i <= right; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
}

void merge(int* arr, int left, int mid, int right) {
    cout << "Merging ranges [" << left << ", " << mid << "] and [" << mid + 1 << ", " << right << "]: " << endl;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

    for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++) rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        }
        else {
            arr[k++] = rightArr[j++];
        }

        for (int i = left; i <= right; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    while (i < n1) arr[k++] = leftArr[i++];
    while (j < n2) arr[k++] = rightArr[j++];

    delete[] leftArr;
    delete[] rightArr;

    for (int i = left; i <= right; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
}

void timSort(int* arr, int n, int run) {
    // Sort individual subarrays of size 'run' using Insertion Sort
    for (int i = 0; i < n; i += run) {
        insertionSort(arr, i, min((i + run - 1), (n - 1)));
    }

    for (int size = run; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = min((left + size - 1), (n - 1));
            int right = min((left + 2 * size - 1), (n - 1));
            if (mid < right) merge(arr, left, mid, right);
        }
    }
}

int main() {
    int n, run;

    cout << "Enter number of elements in array: ";
    cin >> n;
    cout << "Enter run size: ";
    cin >> run;

    int* arr = new int[n];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    

    timSort(arr, n, run);
    cout << "---------------------------------------------------\n\n";
    cout << "Original Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    cout << "---------------------------------------------------\n\n";
    cout << "Final Sorted Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    cout << "---------------------------------------------------";
    delete[] arr;

    return 0;
}
