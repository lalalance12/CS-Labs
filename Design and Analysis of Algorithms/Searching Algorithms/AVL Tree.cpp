#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;


class Node {
   public:
  int key;
  Node *left;
  Node *right;
  int height;
};

int max(int a, int b);

// Calculate height
int height(Node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

// New node creation
Node *newNode(int key) {
  Node *node = new Node();
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

// Rotate right
Node *rightRotate(Node *y) {
  Node *x = y->left;
  Node *T2 = x->right;
  x->right = y;
  y->left = T2;
  y->height = max(height(y->left),
          height(y->right)) +
        1;
  x->height = max(height(x->left),
          height(x->right)) +
        1;
  return x;
}

// Rotate left
Node *leftRotate(Node *x) {
  Node *y = x->right;
  Node *T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = max(height(x->left),
          height(x->right)) +
        1;
  y->height = max(height(y->left),
          height(y->right)) +
        1;
  return y;
}

// Get the balance factor of each node
int getBalanceFactor(Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) -
       height(N->right);
}

// INSERT A NODE
Node *insertNode(Node *node, int key) {
  // Find the correct postion and insert the node
  if (node == NULL)
    return (newNode(key));
  if (key < node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);
  else
    return node;

  // Update the balance factor of each node and
  // balance the tree
  node->height = 1 + max(height(node->left),
               height(node->right));
  int balanceFactor = getBalanceFactor(node);
  if (balanceFactor > 1) {
    if (key < node->left->key) {
      return rightRotate(node);
    } else if (key > node->left->key) {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }
  }
  if (balanceFactor < -1) {
    if (key > node->right->key) {
      return leftRotate(node);
    } else if (key < node->right->key) {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }
  }
  return node;
}

// Node with minimum value
Node *nodeWithMimumValue(Node *node) {
  Node *current = node;
  while (current->left != NULL)
    current = current->left;
  return current;
}


// SEARCH A NODE
Node *search(Node *root, int key) {
  // Return if the tree is empty or if the key is found
  if (root == NULL || root->key == key)
    return root;

  // Key is greater, so search in the right subtree
  if (key > root->key)
    return search(root->right, key);

  // Key is smaller, so search in the left subtree
  return search(root->left, key);
}

// Delete a node
Node *deleteNode(Node *root, int key) {
  // Find the node and delete it
  if (root == NULL)
    return root;
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    if ((root->left == NULL) ||
      (root->right == NULL)) {
      Node *temp = root->left ? root->left : root->right;
      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      Node *temp = nodeWithMimumValue(root->right);
      root->key = temp->key;
      root->right = deleteNode(root->right,
                   temp->key);
    }
  }

  if (root == NULL)
    return root;

  // Update the balance factor of each node and
  // balance the tree
  root->height = 1 + max(height(root->left),
               height(root->right));
  int balanceFactor = getBalanceFactor(root);
  if (balanceFactor > 1) {
    if (getBalanceFactor(root->left) >= 0) {
      return rightRotate(root);
    } else {
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
  }
  if (balanceFactor < -1) {
    if (getBalanceFactor(root->right) <= 0) {
      return leftRotate(root);
    } else {
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }
  }
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
    Node *root = NULL;


    //INSERT

    clock_t start_time = clock(); // Start TIME

    for (int i = 0; i < n; i++) {
       root = insertNode(root, arr[i]);
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
