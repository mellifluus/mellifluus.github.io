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

class Queue {
  public:
    Node* front;
    Node* rear;
    Queue(Node* f = NULL, Node* r = NULL) {
      front = f;
      rear = r;
    }
    void enqueue(int data);
    Node* dequeue();
    Node* peek();
    Node* search(int data);
    int size();
    void print();
};

void Queue::enqueue(int data) {
  if (front == NULL) {
    front = new Node(data);
    rear = front;
    return;
  }
  Node* newNode = new Node(data);
  rear->next = newNode;
  rear = newNode;
}

Node* Queue::dequeue() {
  if (front == NULL) {
    return NULL;
  }
  Node* temp = front;
  front = front->next;
  return temp;
}

Node* Queue::peek() {
  return front;
}

Node* Queue::search(int data) {
  Node* currentNode = front;
  while(currentNode != NULL) {
    if (currentNode->data == data) {
      return currentNode;
    }
    currentNode = currentNode->next;
  }
  return NULL;
}

int Queue::size() {
  int count = 0;
  Node* currentNode = front;
  while(currentNode != NULL) {
    count++;
    currentNode = currentNode->next;
  }
  return count;
}

void Queue::print() {
  Node* currentNode = front;
  while(currentNode != NULL) {
    if (currentNode == front) {
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
  Queue* queue = new Queue();
  while(true) {
    cout << endl << "-------------------------------------------------" << endl << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Peek" << endl;
    cout << "4. Search" << endl;
    cout << "5. Size" << endl;
    cout << "6. Exit" << endl;
    cout << endl << "-------------------------------------------------" << endl;
    queue->print();
    cout << "-------------------------------------------------" << endl << endl;
    int choice;
    cin >> choice;
    if(choice == 1) {
      int data;
      cout << "Enter data: ";
      cin >> data;
      queue->enqueue(data);
    }
    else if(choice == 2) {
      Node* temp = queue->dequeue();
      if (temp == NULL) {
        cout << "Queue is empty" << endl;
      }
      else {
        cout << "Dequeued: " << temp->data << endl;
        delete temp;
      }
    }
    else if(choice == 3) {
      Node* temp = queue->peek();
      if (temp == NULL) {
        cout << "Queue is empty" << endl;
      }
      else {
        cout << "Peeked: " << temp->data << endl;
      }
    }
    else if(choice == 4) {
      int data;
      cout << "Enter data: ";
      cin >> data;
      Node* temp = queue->search(data);
      if (temp == NULL) {
        cout << "Not found" << endl;
      }
      else {
        cout << "Found: " << temp->data << endl;
      }
    }
    else if(choice == 5) {
      cout << "Size: " << queue->size() << endl;
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