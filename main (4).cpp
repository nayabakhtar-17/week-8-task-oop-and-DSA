/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

// Class for tree node
class TreeNode {
private:
    int marks;
    string gender;
    TreeNode* left;
    TreeNode* right;

public:
    // Constructor to initialize the tree node
    TreeNode(int m, string g) {
        marks = m;
        gender = g;
        left = right = nullptr;
    }

    // Setters and Getters
    void setMarks(int m) { marks = m; }
    int getMarks() { return marks; }

    void setGender(string g) { gender = g; }
    string getGender() { return gender; }

    void setLeft(TreeNode* l) { left = l; }
    TreeNode* getLeft() { return left; }

    void setRight(TreeNode* r) { right = r; }
    TreeNode* getRight() { return right; }

    // Check if the node is a leaf node
    bool isLeaf() {
        return (left == nullptr && right == nullptr);
    }
};

// Class for Binary Search Tree (BST)
class BST {
private:
    TreeNode* root;

    // Helper function to insert a node into the BST
    TreeNode* insert(TreeNode* node, int marks, string gender) {
        if (node == nullptr) {
            return new TreeNode(marks, gender);  // Create a new node if current is null
        }

        if (marks < node->getMarks()) {
            node->setLeft(insert(node->getLeft(), marks, gender));  // Insert into left subtree
        } else {
            node->setRight(insert(node->getRight(), marks, gender));  // Insert into right subtree
        }

        return node;  // Return the unchanged node pointer
    }

    // Helper function to perform in-order traversal
    void inOrder(TreeNode* node) {
        if (node == nullptr) return;

        inOrder(node->getLeft());  // Traverse the left subtree
        cout << node->getMarks() << " " << node->getGender() << endl;  // Visit the node
        inOrder(node->getRight());  // Traverse the right subtree
    }

public:
    // Constructor
    BST() { root = nullptr; }

    // Insert function
    void insert(int marks, string gender) {
        root = insert(root, marks, gender);
    }

    // In-order traversal
    void inOrder() {
        inOrder(root);
    }
};

// Main function
int main() {
    // Data for marks and gender
    int marks[] = {10, 5, 14, 3, 7, 9, 18, 15, 13, 17, 100};
    string gender[] = {"male", "female", "male", "male", "male", "male", "female", "female", "female", "male", "male"};
    int size = sizeof(marks) / sizeof(marks[0]);

    // Display the given data
    cout << "Given Data: " << endl;
    cout << "Marks: ";
    for (int i = 0; i < size; i++) {
        cout << marks[i] << " ";
    }
    cout << "\nGender: ";
    for (int i = 0; i < size; i++) {
        cout << gender[i] << " ";
    }
    cout << endl << endl;

    // Create two BST objects, one for male and one for female students
    BST maleBST, femaleBST;

    // Variable to store user choice
    int choice;

    do {
        cout << "\nEnter your choice:\n";
        cout << "1: Create BSTs\n";
        cout << "2: See Male Students' BST\n";
        cout << "3: See Female Students' BST\n";
        cout << "0: Terminate Program\n";
        cin >> choice;

        switch (choice) {
            case 1:
                // Insert data into the respective BSTs based on gender
                for (int i = 0; i < size; i++) {
                    if (gender[i] == "male") {
                        maleBST.insert(marks[i], gender[i]);
                    } else if (gender[i] == "female") {
                        femaleBST.insert(marks[i], gender[i]);
                    }
                }
                cout << "BST of male students created successfully.\nDone." << endl;
                cout << "BST of female students created successfully.\nDone." << endl;
                break;

            case 2:
                // Display male students' BST using in-order traversal
                cout << "\nIn-order traversal of Male Students' BST:" << endl;
                maleBST.inOrder();
                break;

            case 3:
                // Display female students' BST using in-order traversal
                cout << "\nIn-order traversal of Female Students' BST:" << endl;
                femaleBST.inOrder();
                break;

            case 0:
                cout << "Program terminated." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}