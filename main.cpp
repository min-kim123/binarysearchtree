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
Node* remove(int removeNode, Node* &head);
void search(Node* head, int searchnum);

int main() {
  int nums[80];
  char input[80];
  bool cont = true;
  Node* head = NULL;
  while (cont == true) {
    cout << "Add, remove, print, search, or quit (add, remove, print, seach, quit)?: ";
    cin >> input;
    cin.ignore();
    if (strcmp(input, "add") == 0) {
      int num = 0;
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
      remove(r, head);
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
    else if (strcmp(input, "search") == 0) {
      int num = 0;
      cout << "Number: ";
      cin >> num;
      search(head, num);
    }
    else if (strcmp(input, "quit") == 0) {
      cont = false;
    }
    else {
      cout << "Invalid input" << endl;
    }
  }
}
//pseudocode for insert and print and code for remove from https://www.programiz.com/dsa/binary-search-tree
Node* insert(Node* newnode, Node* &n) {
  if (n == NULL) {
    n = newnode;
    return n;
  }
  if (newnode->data <= n->data) {
    n->left = insert(newnode, n->left);
  }
  else if (newnode->data >= n->data) {
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

Node* remove(int num, Node* &n) {
  /*
  find the node that matches the num
  1. node is leaf: simply delete the node
  2. node has one child: replace node, remove child
  3. node has two children: find node to replace, replace, remove successor
  */
 cout << "remove" << endl;
  if (n == NULL) {
    return n;
  }
  else if (n->data > num) {
    cout << "1" << endl;
    n->left = remove(num, n->left);
  }
  else if (n->data < num) {
    cout << "2" << endl;
    n->right = remove(num, n->right);
  }
  else {//node has only one child or no child
  cout << "3" << endl;
    if (n->left == NULL) {
      cout << "4" << endl;
      Node* temp = n->right;
      delete n;
      return temp;
    }
    else if (n->right == NULL) {
      cout << "5" << endl;
      Node* temp = n->left;
      delete n;
      return temp;
    }
    Node* current = n->right;
  while(current && current->left != NULL) {
    current = current->left;
  }
  Node* temp = current;

  n->data = temp->data;
  n->right = remove(temp->data, n->right);

  }
  return n;
}

void search (Node* n, int searchnum) {
  if (n->data == searchnum) {
    cout << "Number exists." << endl;
    return;
  }
  else if (n->data > searchnum && n->left != NULL) {
    search(n->left, searchnum);
  }
  else if (n->data < searchnum && n->right != NULL) {
    search(n->right, searchnum);
  }
  else if (n->left == NULL || n->right == NULL) {//number doesn't exist
    cout << "Number doesn't exist." << endl;
    return;
  }

}