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

int main() {
  int nums[80];
  int num = 0;
  char input[80];
  bool cont = true;
  Node* head = NULL;
  while (cont == true) {
    cout << "Add, remove, print, or quit?: ";
    cin >> input;
    cin.ignore();
    if (strcmp(input, "add") == 0) {
      while(num != -1) {
	if (num == -1) {
	  break;
	}
	cout << "Enter number, enter -1 to quit adding: ";
        cin >> num;
        Node* newnode = new Node(num);
        insert(newnode, head);
      }
    }
    else if (strcmp(input, "remove") == 0) {

    }
    else if (strcmp(input, "print") == 0) {
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

Node* insert(Node* newnode, Node* &n) {
  if (n == NULL) {
    n = newnode;
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
  print(n->left, numTabs);
  ++numTabs;
  while (floor(numTabs) > 1) {
    numTabs = floor(numTabs)/2;
    cout << "\t";
  }
  cout << n->data << endl;
  print(n->right, numTabs);
}
