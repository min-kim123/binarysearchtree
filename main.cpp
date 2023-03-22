#include <iostream>
#include <string.h>
#include <math.h>
#include <cstring>
using namespace std;

class Node {
public:
  int data;
  Node* left;
  Node* right;
  Node(int num) {
    data = num;
    left = NULL;
    right = NULL;
  }
};

Node* insert(Node* newnode, Node* &head);
void print(Node* head, int numTabs);
void remove(int removeNode, Node* &head);

int main() {
  int nums[80];
  int num = 0;
  char input[80];
  bool cont = true;
  Node* head = NULL;
  while (cont == true) {
    cout << "Add, remove, print, or quit (add, remove, print, quit)?: ";
    cin >> input;
    cin.ignore();
    if (strcmp(input, "add") == 0) {
      while(num != -1) {
        cout << "Enter number, enter -1 to quit adding: ";
        cin >> num;
        if (num == -1) {
          break;
	      }
        Node* newnode = new Node(num);
        insert(newnode, head);
      }
    }
    else if (strcmp(input, "remove") == 0) {
      int r = 0;
      cout << "Number to remove: ";
      cin >> r;
      //remove(r, head);
    }
    else if (strcmp(input, "print") == 0) {
      Node* a = head;
      Node* b = head;
      cout << "lefts: ";
      while (a != NULL) {
        cout << a->data;
        a = a->left;
        }
        cout << endl;
        cout << "rights: ";
      while (b != NULL) {
        cout << b->data;
        b = b->right;
      }
      cout << endl;
      int numTabs = 0;
      print(head, numTabs);
    }
    else if (strcmp(input, "quit") == 0) {
      cont = false;
    }
    else {
      cout << "Invalid input" << endl;
    }
  }
}
//pseudocode for all functions below from https://www.programiz.com/dsa/binary-search-tree
Node* insert(Node* newnode, Node* &n) {
  if (n == NULL) {
    n = newnode;
    return n;
  }
  if (newnode->data < n->data) {
    n->left = insert(newnode, n->left);
  }
  else if (newnode->data > n->data) {
    n->right = insert(newnode, n->right);
  }
  return n;
}

void print(Node* n, int numTabs) {
  if (n == NULL) {
    return;
  }  
  ++numTabs;
  print(n->right, numTabs);
  for (int i = 0; i < numTabs; ++i) {
    cout << "\t";
  }
  cout << n->data << endl;
  print(n->left, numTabs);
}
/*
void remove(int n, Node* &head) {
  if (n->next == NULL) {
    //leaf, remove
  }
}*/