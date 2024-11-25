#include <iostream>
using namespace std;

// Function Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) 
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Function Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) 
        L[i] = arr[left + i];
    
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Function Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Function Print Array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

// Main
int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    // Bubble Sort
    int arr1[] = { 64, 34, 25, 12, 22, 11, 90 };
    bubbleSort(arr1, n);
    cout << "Bubble Sorted array: ";
    printArray(arr1, n);

    // Selection Sort
    int arr2[] = { 64, 34, 25, 12, 22, 11, 90 };
    selectionSort(arr2, n);
    cout << "Selection Sorted array: ";
    printArray(arr2, n);

    // Insertion Sort
    int arr3[] = { 64, 34, 25, 12, 22, 11, 90 };
    insertionSort(arr3, n);
    cout << "Insertion Sorted array: ";
    printArray(arr3, n);

    // Merge Sort
    int arr4[] = { 64, 34, 25, 12, 22, 11, 90 };
    mergeSort(arr4, 0, n - 1);
    cout << "Merge Sorted array: ";
    printArray(arr4, n);

    // Quick Sort
    int arr5[] = { 64, 34, 25, 12, 22, 11, 90 };
    quickSort(arr5, 0, n - 1);
    cout << "Quick Sorted array: ";
    printArray(arr5, n);

    // Heap Sort
    int arr6[] = { 64, 34, 25, 12, 22, 11, 90 };
    heapSort(arr6, n);
    cout << "Heap Sorted array: ";
    printArray(arr6, n);

    return 0;
}
