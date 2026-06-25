#include <iostream>
#include <fstream>
using namespace std;

struct Node {
  char data;
  Node* next;
};

Node* addNode(char value) {
  Node* newNode = new Node;
  newNode->data = value;
  newNode->next = nullptr;

  return newNode;
}

void pushFront(char value, Node*& head) {
  Node* newNode = addNode(value);
  if (head == nullptr) {
    head = newNode;
  }

  else {
    newNode->next = head;
    head = newNode;
  }
}

void clearList(Node*& head) {
  while (head != nullptr) {
    Node* p = head;
    head = head->next;
    delete p;
  }
}

void print(Node*& head) {
  Node* current = head;
  if (current == nullptr) {cout << "List is empty" << endl; return;}
  while (current != nullptr) {
    cout << current->data;
    current = current->next;
  }
}

int main() {

  ifstream file("file.txt");
  if (!file.is_open()) {cerr << "ERROR: file.txt nevozmozhno otkryt!!!" << endl; return 1;}
  if (file.peek() == EOF) {cerr << "ERROR: file.txt is empty!!!" << endl; return 1;}
  Node* head = nullptr;

  char c; 
  while (file.get(c)) {
    pushFront(c, head);
  }

  print(head);

  clearList(head);

  return 0;

}