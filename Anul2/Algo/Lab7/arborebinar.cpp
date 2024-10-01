#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class BinarySearchTree {
public:
  BinarySearchTree() : root(nullptr) {}

  void insert(T value) {
    if (root == nullptr) {
      root = new Node(value);
      return;
    }

    Node* current = root;
    while (true) {
      if (value < current->data) {
        if (current->left == nullptr) {
          current->left = new Node(value);
          return;
        }
        current = current->left;
      } else if (value > current->data) {
        if (current->right == nullptr) {
          current->right = new Node(value);
          return;
        }
        current = current->right;
      } else {
        return;
      }
    }
  }

  void sort(vector<T>& values) {
    for (T value : values) {
      insert(value);
    }

    Node* current = root;
    vector<T> sortedValues;
    while (current != nullptr) {
      sortedValues.push_back(current->data);
      if (current->left != nullptr) {
        current = current->left;
      } else {
        current = current->right;
      }
    }

    values = sortedValues;
  }

private:
  struct Node {
    T data;
    Node* left;
    Node* right;

    Node(T val) : data(val), left(nullptr), right(nullptr) {}
  };

  Node* root;
};

int main() {
  vector<int> values = {5, 4, 3, 2, 1};

  BinarySearchTree<int> tree;
  tree.sort(values);

  for (int value : values) {
    cout << value << " ";
  }

  cout << endl;

  return 0;
}