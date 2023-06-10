// Binary Search Tree operations in C++
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Create a node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Inorder Traversal
void inorder(struct node *root) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left);

    // Traverse root
    cout << root->key << " -> ";


    // Traverse right
    inorder(root->right);
  }
}

// INSERT A NODE
struct node *insert(struct node *node, int key) {
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(key);

  // Traverse to the right place and insert the node
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

// Find the inorder successor
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// SEARCH A NODE
struct node *search(struct node *root, int key) {
  // Return if the tree is empty or if the key is found
  if (root == NULL || root->key == key)
    return root;

  // Key is greater, so search in the right subtree
  if (key > root->key)
    return search(root->right, key);

  // Key is smaller, so search in the left subtree
  return search(root->left, key);
}

// DELETE A NODE
struct node *deleteNode(struct node *root, int key) {
  // Use the search function to find the node to be deleted
  struct node *node = search(root, key);

  // Return if the node is not found
  if (node == NULL)
    return root;

  // If the node is with only one child or no child
  if (node->left == NULL) {
    struct node *temp = node->right;
    free(node);
    return temp;
  } else if (node->right == NULL) {
    struct node *temp = node->left;
    free(node);
    return temp;
  }

  // If the node has two children
  struct node *temp = minValueNode(node->right);

  // Place the inorder successor in the position of the node to be deleted
  node->key = temp->key;

  // Delete the inorder successor
  node->right = deleteNode(node->right, temp->key);

  return root;
}


// Driver code
int main() {

    //Initialize random values
    const int SIZE = 10000; // Change this to adjust the size of the array

    //Initiazlize variables
    int arr[SIZE];
    int n = sizeof(arr)/sizeof(arr[0]);

    srand(time(nullptr)); // Seed the random number generator with the current time

    int randomNum = rand() % (SIZE + 1); // Generate a random number given from the size

    // Generate random numbers and fill the array
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand();
    }

    /*

    // Print out array unsorted

    cout << "Array before sorting: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    */


    //Initialize Tree Variables
    struct node *root = NULL;


    //INSERT

    clock_t start_time = clock(); // Start TIME

    for (int i = 0; i < n; i++) {
       root = insert(root, arr[i]);
    }

    clock_t end_time = clock(); // End TIME


    double elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;
    cout << "Execution time: " << elapsed_time*1000 << " milliseconds" << endl; // Print the execution time



    // SEARCH

    clock_t start_time = clock(); // Start TIME

    root = search(root, arr[randomNum]);

    clock_t end_time = clock(); // End TIME


    double elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;
    cout << "Execution time: " << elapsed_time*1000 << " milliseconds" << endl; // Print the execution time



    // DELETE

    clock_t start_time = clock(); // Start TIME

    root = deleteNode(root, arr[randomNum]); // DELETE OPERATION

    clock_t end_time = clock(); // End TIME

    double elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;
    cout << "Execution time: " << elapsed_time*1000 << " milliseconds" << endl; // Print the execution time




    return 0;

}
