#include <iostream>
using namespace std;

//GROUPMATES: CLARIN, GICOLE, LOMPON


// Using a sorting algorithm (selection sort)
int Selection_Sort(int arr[], int n) {
    // Selection sort
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }
        swap(arr[i], arr[maxIdx]);
    }
    // Find third maximum
    int maxCount = 1;
    int thirdMax = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            maxCount++;
            if (maxCount == 3) {
                thirdMax = arr[i];
                break;
            }
        }
    }
    return thirdMax;
}

// Maam Emily Algorithm (using 3 arrays)

// Find the maximum number in an array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Copy the array without the maximum number
void copyArrayWithoutMax(int arr1[], int arr2[], int n, int max) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr1[i] != max) {
            arr2[j] = arr1[i];
            j++;
        }
    }
}

// Function that does the algorithm of Maam Emily using 3 arrays
int findThirdMax_MaamEmily_Algo(int arr1[], int n){

    // Find the maximum number of the first array
    int max1 = findMax(arr1, n);

    int arr2[n - 1]; // Make a 2nd array

    // Copy the numbers in array 1 to array 2 without the maximum number of array 1
    copyArrayWithoutMax(arr1, arr2, n, max1);

    int arr3[n - 2]; // Make a 3rd array

    // Find the maximum number of the 2nd array
    int max2 = findMax(arr2, n - 1);

    // Copy the numbers in array 2 to array 3 without the maximum number of array 2
    copyArrayWithoutMax(arr2, arr3, n - 1, max2);

    // Find the maximum number of the third array
    int max3 = findMax(arr3, n - 2);
    return max3;
}



// Vince Algorithm
int findThirdMax_Vince_Algo(int arr[], int n) {
    // Initialize the first 3 unique numbers in the array as the first, second and third maximum number
    int firstMax = arr[0], secondMax = arr[1], thirdMax = arr[2];

    for (int i = 3; i < n; i++) {
        if (arr[i] == firstMax || arr[i] == secondMax || arr[i] == thirdMax) {
            continue; // Skip duplicates
        }

        if (arr[i] > firstMax || arr[i] > secondMax || arr[i] > thirdMax) {
             if (firstMax <= secondMax && firstMax <= thirdMax){
                firstMax = arr[i];

             }
             else if (secondMax <= firstMax && secondMax <= thirdMax){
               secondMax = arr[i];

             }
             else {
                thirdMax = arr[i];
             }
        }
    }

    //Finding the third Max of the 3 variables
    //Note that the variable name thirdmax does not hold the third maximum value in the array therefore we find out by comparing the three variables on which is the third max

    // finding the least number out of the 3 variables
    int least = firstMax;
    if (secondMax < least) {
        least = secondMax;
    }
    if (thirdMax < least) {
        least = thirdMax;
    }

    return least;

    }



int main()
{
    int arr[] = {1, 3, 18, 7, 8, 9, 16, 17};
    int n = sizeof(arr) / sizeof(arr[0]);


    int thirdMax_MaamEmily_Algo = findThirdMax_MaamEmily_Algo(arr, n);
    cout << "(Maam Emily Algorithm) Third maximum element is: " << thirdMax_MaamEmily_Algo << endl;

    int thirdMax_Vince_Algo = findThirdMax_Vince_Algo(arr, n);
    cout << "(Vince Algorithm) Third maximum element is: " << thirdMax_Vince_Algo << endl;

    int thirdMax_Sort = Selection_Sort(arr, n);
    cout << "(Sorting Algorithm) Third maximum element is: " << thirdMax_Sort << endl;

    return 0;
}
