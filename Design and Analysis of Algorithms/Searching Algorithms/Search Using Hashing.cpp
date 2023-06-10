#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to print an array
void print_array(const vector<int>& arr) {
    // Iterating and printing the array
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " " ;
    }
    cout << endl;
}

int print_num_prob(int prob){
    cout <<"Probe count = " << prob << endl;
}

// Function to implement LINEAR PROBING
void hashing_1(vector<int>& table, int tsize, const vector<int>& arr) {

    // Initialize probe counter
    int probe = 0;

    // Iterating through the array
    for (int i = 0; i < arr.size(); i++) {
        // Computing the hash value
        int hv = arr[i] % tsize;

        // If the slot is empty, insert the value
        if (table[hv] == -1) {
            table[hv] = arr[i];
        } else {

            // If there is a collision, use Linear probing
            int j = 1;
            int slot = (hv + j) % tsize;
            while (table[slot] != -1) {
                j++;
                slot = (hv + j) % tsize;
            }
            table[slot] = arr[i];
            cout << "Collision occurred at index " << slot << endl;

            //Update probe counter
            probe ++;
        }
    }
    print_array(table);
    print_num_prob(probe);
}


// Function to QUADRATIC PROBING
void hashing_2(vector<int>& table, int tsize, const vector<int>& arr)
{
    // Initialize probe counter
    int probe = 0;

    // Iterating through the array
    for (int i = 0; i < arr.size(); i++) {
        // Computing the hash value
        int hv = arr[i] % tsize;

        // If the slot is empty, insert the value
        if (table[hv] == -1)
            table[hv] = arr[i];
        else {

            // If there is a collision, use Quadratic Probing
            for (int j = 0; j < tsize; j++) {
                int slot = (hv + j * j) % tsize;
                if (table[slot] == -1) {
                    table[slot] = arr[i];
                    cout << "Collision occurred at index " << slot << endl;

                    //Update probe counter
                    probe ++;
                    break;

                }
            }
        }
    }
    print_array(table);
    print_num_prob(probe);
}





// Function to implement double hashing
void hashing_3(vector<int>& table, int tsize, const vector<int>& arr) {

    // Initialize probe counter
    int probe = 0;

    // Iterating through the array
    for (int i = 0; i < arr.size(); i++) {
        // Computing the primary hash value
        int hv = arr[i] % tsize;

        // If the slot is empty, insert the value
        if (table[hv] == -1) {
            table[hv] = arr[i];
        } else {
            // Compute the secondary hash value
            int dv = 13 - (arr[i] % 13);
            int j = 1;
            int slot = (hv + j * dv) % tsize;
            while (table[slot] != -1) {
                int dv_2 = dv_2 + dv;
                slot = (hv + j * dv_2) % tsize;
            }
            table[slot] = arr[i];
            cout << "Collision occurred at index " << slot << endl;

            //Update probe counter
            probe ++;
        }
    }
    print_array(table);
    print_num_prob(probe);
}





int main() {
    vector<int> arr = {25, 88, 3, 38, 20, 71, 55, 56, 50, 105};
    //int N = 10;

    // Size of the hash table
    int L = 17;
    vector<int> hash_table(L, -1);

    // Function call (call them one at a time)


    cout << "Linear Hashing" << endl;
    hashing_1(hash_table, L, arr);
    cout << " " << endl;
    cout << " " << endl;


    /*
    cout << "Quadratic Hashing" << endl;
    hashing_2(hash_table, L, arr);
    cout << " " << endl;
    cout << " " << endl;
    */

    /*
    cout << "Double Hashing" << endl;
    hashing_3(hash_table, L, arr);
    cout << " " << endl;
    cout << " " << endl;
    */

    return 0;
}




