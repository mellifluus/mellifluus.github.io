//@author Massimiliano Ricci
#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node(int d) {
      data = d;
    }
};

class Stack {
  public:
    Node* top;
    Stack(Node* n = NULL) {
      top = n;
    }
    Node* search(int data);
    void push(int data);
    Node* pop();
    Node* peek();
    int size();
    void print();
};

Node* Stack::search(int data) {
  Node* currentNode = top;
  while(currentNode != NULL) {
    if (currentNode->data == data) {
      return currentNode;
    }
    currentNode = currentNode->next;
  }
  return NULL;
}

void Stack::push(int data) {
  if (top == NULL) {
    top = new Node(data);
    return;
  }
  Node* newNode = new Node(data);
  newNode->next = top;
  top = newNode;
}

Node* Stack::pop() {
  if (top == NULL) {
    return NULL;
  }
  Node* temp = top;
  top = top->next;
  return temp;
}

Node* Stack::peek() {
  return top;
}

int Stack::size() {
  int size = 0;
  Node* currentNode = top;
  while(currentNode != NULL) {
    size++;
    currentNode = currentNode->next;
  }
  return size;
}

void Stack::print() {
  Node* currentNode = top;
  while(currentNode != NULL) {
    if (currentNode == top) {
      cout << currentNode->data;
    } 
    else {
      cout << "->" << currentNode->data;
    }
    currentNode = currentNode->next;
  }
  cout << "->NULL" << endl;
}

int main() {
  Stack* stack = new Stack();
  while(true) {
    cout << endl << "-------------------------------------------------" << endl << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Peek" << endl;
    cout << "4. Size" << endl;
    cout << "5. Search" << endl;
    cout << "6. Exit" << endl;
    cout << endl << "-------------------------------------------------" << endl;
    stack->print();
    cout << "-------------------------------------------------" << endl << endl;
    int choice;
    cin >> choice;
    if(choice == 1) {
      int data;
      cout << "Enter data: ";
      cin >> data;
      stack->push(data);
    }
    else if(choice == 2) {
      Node* temp = stack->pop();
      if (temp == NULL) {
        cout << "Stack is empty" << endl;
      }
      else {
        cout << "Popped: " << temp->data << endl;
        delete temp;
      }
    }
    else if(choice == 3) {
      Node* temp = stack->peek();
      if (temp == NULL) {
        cout << "Stack is empty" << endl;
      }
      else {
        cout << "Peeked: " << temp->data << endl;
      }
    }
    else if(choice == 4) {
      cout << "Size: " << stack->size() << endl;
    }
    else if(choice == 5) {
      int data;
      cout << "Enter data: ";
      cin >> data;
      Node* temp = stack->search(data);
      if (temp == NULL) {
        cout << "Not found" << endl;
      }
      else {
        cout << "Found: " << temp->data << endl;
      }
    }
    else if(choice == 6) {
      break;
    }
    else {
      cout << "Invalid choice" << endl;
    }
  }
  return 0;
}