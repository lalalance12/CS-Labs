#include <iostream>
#include <vector>
#include <time.h>
#include <bits/stdc++.h>
#include <stdlib.h>


using namespace std;

class Node {
public:
    std::vector<int> keys;
    std::vector<Node*> children;

    Node() {}

    bool isLeaf() {
        return children.empty();
    }
};

class TwoFourTree {
private:
    Node* root;

    Node* insertNode(Node* root, int key) {
        if (root == nullptr) {
            Node* newNode = new Node();
            newNode->keys.push_back(key);
            return newNode;
        }

        if (root->isLeaf()) {
            root->keys.push_back(key);
            sort(root->keys.begin(), root->keys.end());
            return splitNode(root);
        }

        int childIndex = 0;
        while (childIndex < root->keys.size() && key > root->keys[childIndex])
            childIndex++;

        root->children[childIndex] = insertNode(root->children[childIndex], key);

        if (root->children[childIndex] == nullptr)
            return nullptr;

        if (root->children[childIndex]->keys.size() == 3) {
            root->keys.insert(root->keys.begin() + childIndex, root->children[childIndex]->keys[1]);

            Node* leftChild = new Node();
            leftChild->keys.push_back(root->children[childIndex]->keys[0]);
            leftChild->keys.push_back(root->children[childIndex]->keys[1]);

            Node* rightChild = new Node();
            rightChild->keys.push_back(root->children[childIndex]->keys[2]);

            root->children[childIndex]->keys.clear();
            root->children[childIndex]->keys.push_back(root->children[childIndex]->keys[1]);

            if (!root->children[childIndex]->isLeaf()) {
                leftChild->children.push_back(root->children[childIndex]->children[0]);
                leftChild->children.push_back(root->children[childIndex]->children[1]);

                rightChild->children.push_back(root->children[childIndex]->children[2]);
                rightChild->children.push_back(root->children[childIndex]->children[3]);

                root->children[childIndex]->children.clear();
                root->children[childIndex]->children.push_back(leftChild);
                root->children[childIndex]->children.push_back(rightChild);
            } else {
                root->children[childIndex]->children.push_back(leftChild);
                root->children[childIndex]->children.push_back(rightChild);
            }
        }

        return root;
    }

    Node* splitNode(Node* node) {
        if (node->keys.size() <= 2)
            return node;

        Node* leftChild = new Node();
        leftChild->keys.push_back(node->keys[0]);

        Node* rightChild = new Node();
        rightChild->keys.push_back(node->keys[2]);

        Node* parent = new Node();
        parent->keys.push_back(node->keys[1]);

        if (!node->isLeaf()) {
            leftChild->children.push_back(node->children[0]);
            leftChild->children.push_back(node->children[1]);

            rightChild->children.push_back(node->children[2]);
            rightChild->children.push_back(node->children[3]);

            parent->children.push_back(leftChild);
            parent->children.push_back(rightChild);
        } else {
            parent->children.push_back(leftChild);
            parent->children.push_back(rightChild);
        }

        return parent;
    }

    bool searchNode(Node* root, int key) {
        if (root == nullptr)
            return false;

        if (std::find(root->keys.begin(), root->keys.end(), key) != root->keys.end())
            return true;

        if (root->isLeaf())
            return false;

        int childIndex = 0;
        while (childIndex < root->keys.size() && key > root->keys[childIndex])
            childIndex++;

        return searchNode(root->children[childIndex], key);
    }

    void inorderTraversal(Node* root) {
        if (root != nullptr) {
            if (!root->isLeaf()) {
                for (int i = 0; i < root->keys.size(); i++) {
                    inorderTraversal(root->children[i]);
                    std::cout << root->keys[i] << " ";
                }
                inorderTraversal(root->children[root->keys.size()]);
            } else {
                for (int i = 0; i < root->keys.size(); i++) {
                    std::cout << root->keys[i] << " ";
                }
            }
        }
    }

    Node* findMinNode(Node* root) {
        if (root->isLeaf())
            return root;
        return findMinNode(root->children[0]);
    }

    Node* deleteNode(Node* root, int key) {
        if (root == nullptr)
            return nullptr;

        int keyIndex = std::find(root->keys.begin(), root->keys.end(), key) - root->keys.begin();
        if (keyIndex < root->keys.size() && root->keys[keyIndex] == key) {
            if (root->isLeaf()) {
                root->keys.erase(root->keys.begin() + keyIndex);
                return root;
            }

            Node* predecessor = findMinNode(root->children[keyIndex + 1]);
            root->keys[keyIndex] = predecessor->keys[0];
            root->children[keyIndex + 1] = deleteNode(root->children[keyIndex + 1], predecessor->keys[0]);
        } else {
            int childIndex = 0;
            while (childIndex < root->keys.size() && key > root->keys[childIndex])
                childIndex++;

            root->children[childIndex] = deleteNode(root->children[childIndex], key);
        }

        if (root->children.empty())
            return nullptr;

        if (root->children.size() == 1) {
            if (root->children[0]->keys.empty())
                return nullptr;
            return root->children[0];
        }

        return root;
    }

public:
    TwoFourTree() {
        root = nullptr;
    }

    void insert(int key) {
        root = insertNode(root, key);
        if (root != nullptr && root->keys.size() == 3) {
            Node* newRoot = new Node();
            newRoot->keys.push_back(root->keys[1]);

            Node* leftChild = new Node();
            leftChild->keys.push_back(root->keys[0]);
            leftChild->keys.push_back(root->keys[1]);

            Node* rightChild = new Node();
            rightChild->keys.push_back(root->keys[2]);

            if (!root->isLeaf()) {
                leftChild->children.push_back(root->children[0]);
                leftChild->children.push_back(root->children[1]);

                rightChild->children.push_back(root->children[2]);
                rightChild->children.push_back(root->children[3]);

                newRoot->children.push_back(leftChild);
                newRoot->children.push_back(rightChild);
            } else {
                newRoot->children.push_back(leftChild);
                newRoot->children.push_back(rightChild);
            }

            root = newRoot;
        }
    }

    bool search(int key) {
        return searchNode(root, key);
    }

    void inorder() {
        inorderTraversal(root);
    }

    void remove(int key) {
        root = deleteNode(root, key);
    }
};

int main() {



    //Initialize random values
    const int SIZE = 1000; // Change this to adjust the size of the array

    //Initiazlize variables
    int arr[SIZE];
    int n = sizeof(arr)/sizeof(arr[0]);

    srand(time(nullptr)); // Seed the random number generator with the current time

    int randomNum = rand() % (SIZE + 1); // Generate a random number given from the size

    // Generate random numbers and fill the array
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand();
    }

    TwoFourTree tree;
    //INSERT

    clock_t start_time = clock(); // Start TIME


    for(int i = 0; i < SIZE; i++){
        tree.insert(arr[i]);
    }

    clock_t end_time = clock(); // End TIME

    double elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;
    cout << "Execution time: " << elapsed_time*1000 << " milliseconds" << endl; // Print the execution time



    // SEARCH

    clock_t start_time = clock(); // Start TIME

    if (tree.search(randomNum))
        cout << randomNum << " is found in the 2-4 tree." << std::endl;
    else
        cout << randomNum << " is not found in the 2-4 tree." << std::endl;

    clock_t end_time = clock(); // End TIME

    double elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;
    cout << "Execution time: " << elapsed_time*1000 << " milliseconds" << endl; // Print the execution time



    // DELETE

    clock_t start_time = clock(); // Start TIME

    tree.remove(randomNum);

    clock_t end_time = clock(); // End TIME

    double elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;
    cout << "Execution time: " << elapsed_time*1000 << " milliseconds" << endl; // Print the execution time



    return 0;


}
