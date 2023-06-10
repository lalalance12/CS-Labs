#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

void slow_sort(int arr[], int n) {
    srand(time(0)); // seed the random number generator
    int i, j; // Initialize i and j

    while (true) {
        i = rand() % n; //Generate a random number for i
        j = rand() % n; //Generate a random number for j

        //If i < j, but a[i] > a[j], swap them
        if (i < j && arr[i] > arr[j]) {
            swap(arr[i], arr[j]);
        }

        //Check if the array is sorted or not
        bool sorted = true;
        for (int k = 1; k < n; k++) {
            if (arr[k] < arr[k-1]) {
                sorted = false;
                break;
            }
        }
        if (sorted) {
            break;
        }
    }
}

int main() {
    // Change this to the size of the array you want
    int size = 4000;

    int arr[size];
	srand(time(NULL));

	//For Execution Time
	auto start = chrono::high_resolution_clock::now();
    slow_sort(arr, size);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout<<endl;


    // Loop to input the elements into the array
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % size;
    }

    //Print out the unsorted array
    cout <<"Unsorted array"<<endl;
    for (int i = 0; i < size; i++){

        cout << arr[i] <<" ";
    }

    //Execute slow sort
    slow_sort(arr,size);

    //Print out the sorted array
    cout<<"Sorted array"<<endl;
    for (int i = 0; i < size; i++){
        cout << arr[i] <<" ";
    }
    cout << endl;


    cout << "DONE" << endl;

    //Print out time taken in microseconds
    cout<<"Time taken by function: "<< duration.count() << " microseconds" << endl;

    return 0;
}
