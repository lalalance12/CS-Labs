#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

/*
void binaryInsertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int left = 0;
        int right = i - 1;

        // Binary search to find the correct position for insertion
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > key) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // Shift elements to the right to make space for the key
        for (int j = i - 1; j >= left; j--) {
            arr[j + 1] = arr[j];
        }

        // Insert the key at the correct position
        arr[left] = key;
    }
}

*/


//Counting Sort implementation
// Function to get the maximum element in an array
int getMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}



void countingSort(int arr[], int n) {
    int max = getMax(arr, n);
    int output[n]; // Output array to store sorted elements
    int count[max + 1]; // Count array to store the frequency of each element

    // Initialize count array with 0
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Store the frequency of each element in count array
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Update the input array with sorted elements from count array
    for (int i = 0, j = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[j++] = i;
            count[i]--;
        }
    }
}

/*
// BUCKET SORT //
// Insertion Sort for sorting the individual buckets
void insertionSort(vector<int>& bucket) {
    int n = bucket.size();
    for (int i = 1; i < n; i++) {
        int key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}



// Bucket Sort implementation
void bucketSort(vector<int>& arr) {
    int n = arr.size();

    // Create n buckets
    vector<vector<int>> buckets(n);

    // Place elements into appropriate buckets
    for (int i = 0; i < n; i++) {
        int idx = n * arr[i] / (RAND_MAX + 1); // Update bucket index calculation
        buckets[idx].push_back(arr[i]);
    }

    // Sort individual buckets using Insertion Sort
    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i]);
    }

    // Concatenate sorted buckets back into the original array
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[k++] = buckets[i][j];
        }
    }
}


// Radix Sort implementation
void radixSort(int arr[], int size) {
    int max = getMax(arr, size); // Find the maximum element in the array

    // Perform counting sort for every digit in the maximum element
    for (int exp = 1; max / exp > 0; exp *= 10) {
        int* countArray = new int[10](); // Initialize a count array with zeros for each digit
        int* output = new int[size]; // Initialize an output array for storing sorted elements

        // Count the occurrences of each digit in the input array
        for (int i = 0; i < size; i++) {
            countArray[(arr[i] / exp) % 10]++;
        }

        // Compute the cumulative count of digits in the count array
        for (int i = 1; i < 10; i++) {
            countArray[i] += countArray[i - 1];
        }

        // Overwrite the input array with sorted elements in the output array
        for (int i = size - 1; i >= 0; i--) {
            output[--countArray[(arr[i] / exp) % 10]] = arr[i];
        }

        // Copy the sorted elements from the output array to the input array
        for (int i = 0; i < size; i++) {
            arr[i] = output[i];
        }

        delete[] countArray; // Free dynamically allocated memory
        delete[] output; // Free dynamically allocated memory
    }
}
*/


int main(){
    const int SIZE = 100000; // Change this to adjust the size of the array
    int arr[SIZE]; // For non vector int sort algorithms
    //vector<int> arr(SIZE); // for bin and bucket sort

    int n = sizeof(arr)/sizeof(arr[0]);
    //int n = arr.size(); // for bin and  bucket sort

    srand(time(nullptr)); // Seed the random number generator with the current time

    // Generate random numbers and fill the array
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand();
    }

    // Print out array unsorted
    /*
    cout << "Array before sorting: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    */

    // Sort the array using binary insertion sort and measure the execution time
    clock_t start_time = clock();

    // Select what sort you will use:
    // binaryInsertionSort(arr);
    // countingSort(arr, n);
    // bucketSort(arr);
    // radixSort(arr,SIZE);

    clock_t end_time = clock();
    double elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;

    // Print out array sorted
    /*
    cout << "\nArray after sorting: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    */

    // Print the execution time
    cout << "Execution time: " << elapsed_time*1000 << " milliseconds" << endl;

    return 0;

}
