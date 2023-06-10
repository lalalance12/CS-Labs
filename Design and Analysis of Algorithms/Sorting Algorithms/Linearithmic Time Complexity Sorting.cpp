#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// SHELL SORT //
void shellSort(int arr[], int n){
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
// MERGE SORT //

// Merges two subarrays of array[] - First subarray is arr[begin..mid] - Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid,int const right){

    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne
        = 0, // Initial index of first sub-array
        indexOfSubArrayTwo
        = 0; // Initial index of second sub-array
    int indexOfMergedArray
        = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

// Begin is for left index and end is - second subarray is arr[mid+1..end]  of arr to be sorted
void mergeSort(int array[], int const begin, int const end){
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}


// HEAP SORT //

// To heapify a subtree rooted with node i which is an index in arr[]then n is size of heap
void heapify(int arr[], int N, int i){

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int l = 2 * i + 1;

    // right = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest
    // so far
    if (r < N && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int N){

    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    // One by one extract an element
    // from heap
    for (int i = N - 1; i > 0; i--) {

        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Print array to check the array
void printArray(int arr[], int n){
    int i;
    for (int i=0; i<n; i++)
        cout << arr[i] << ",";
    cout << endl;
}


int main(){
    const int SIZE = 10000; // Change this to adjust the size of the array
    int arr[SIZE];
    int n = sizeof(arr)/sizeof(arr[0]);
    srand(time(nullptr)); // Seed the random number generator with the current time


    // Generate random numbers and fill the array
    for (int i = 0; i < SIZE; i++) {
        arr[i] = std::rand();
    }


    // Print out array unsorted
    //cout << "Array before sorting: \n";
    //printArray(arr, n);


    // Sort the array using Shell sort and measure the execution time
    clock_t start_time = clock();

    // Select what sort you will use

    shellSort(arr, SIZE);
    //mergeSort(arr, 0, n - 1);
    //heapSort(arr, n);


    clock_t end_time = clock();
    double elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;

    // Print out array sorted
    //cout << "\nArray after sorting: \n";
    //printArray(arr, n);

    // Print the execution time
    cout << "Execution time: " << elapsed_time*1000 << " milliseconds" << endl;

    return 0;
}
