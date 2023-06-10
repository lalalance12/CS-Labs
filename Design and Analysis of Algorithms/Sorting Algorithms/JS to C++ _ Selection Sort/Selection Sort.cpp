#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 10000;
const int NUM_EXPERIMENTS = 30;
const string DELIMITER = "\t";

class SortingAlgorithm {
protected:
    int* orig;
    int* arr;
    int n;

public:
    SortingAlgorithm(int* arrInput, int n) {
        this->n = n;
        this->orig = new int[n];
        this->arr = new int[n];
        for (int i = 0; i < n; ++i) {
            this->orig[i] = arrInput[i];
        }
    }

    double getAverageRunTime(int numIterations) {
        double sum = 0.0;
        for (int i = 0; i < numIterations; ++i) {
            sum += this->getRunTime();
        }
        return (sum / numIterations);
    }

    void initArray() {
        for (int i = 0; i < n; ++i) {
            arr[i] = orig[i];
        }
    }

    virtual void sort() = 0;

private:
    double getRunTime() {
        this->initArray();
        auto timeStart = chrono::high_resolution_clock::now();
        this->sort();
        auto timeEnd = chrono::high_resolution_clock::now();
        if (!this->isSorted())
            cout << "----- BUG in Sorting! -----" << endl;
        return chrono::duration<double>(timeEnd - timeStart).count();
    }

    bool isSorted() {
        for (int i = 1; i < this->n; ++i) {
            if (this->arr[i] < this->arr[i - 1])
                return false;
        }
        return true;
    }
};

class SelectionSort : public SortingAlgorithm {
public:
    SelectionSort(int* arr, int n) : SortingAlgorithm(arr, n) {}

    void sort() {
        int last = n - 1;
        for (int i = 0; i < last; ++i) {
            int minValue = arr[i];
            int minIndex = i;
            for (int j = i + 1; j < n; ++j) {
                if (arr[j] < minValue) {
                    minValue = arr[j];
                    minIndex = j;
                }
            }
            arr[minIndex] = arr[i];
            arr[i] = minValue;
        }
    }
};



int main()
{
    // open input file
    ifstream inputFile("SortingInput.txt");

    // read number of test cases from input file
    int numCases;
    inputFile >> numCases;

    // perform benchmark for each test case
    for (int i = 0; i < numCases; ++i) {
        int numItems;
        inputFile >> numItems;

        // read array values from input file and store to a vector
        vector<int> arrOrig(numItems);
        for (int j = 0; j < numItems; ++j) {
            inputFile >> arrOrig[j];
        }

        // perform benchmark
        SortingAlgorithm* sortAlg = new SelectionSort(arrOrig.data(), numItems);
        double avgTime = sortAlg->getAverageRunTime(NUM_EXPERIMENTS);
        cout << "Average runtime for case " << (i+1) << " with " << numItems << " items: " << avgTime << " seconds." << endl;
        delete sortAlg;
    }

    return 0;
}
