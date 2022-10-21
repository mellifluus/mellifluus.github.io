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

class LinkedList {
  public:
    LinkedList(Node* n = NULL) {
      head = n;
    }
    Node* search(int data);
    void prepend(int data);
    void append(int data);
    void insertAt(int data, int ind);
    void remove(int data);
    void removeAt(int ind);
    int size();
    void print();

  private:
    Node* head;
    Node* nodeAtInd(int ind);
};

Node* LinkedList::nodeAtInd(int ind) {
  Node* currentNode = head;
  int i = 0;
  while(i < ind) {
    currentNode = currentNode->next;
    i++;
  }
  return currentNode;
}

Node* LinkedList::search(int data) {
  Node* currentNode = head;
  while(currentNode != NULL) {
    if (currentNode->data == data) {
      return currentNode;
    }
    currentNode = currentNode->next;
  }
  return NULL;
}

void LinkedList::prepend(int data) {
  if (head == NULL) {
    head = new Node(data);
    return;
  }
  Node* newNode = new Node(data);
  newNode->next = head;
  head = newNode;
}

void LinkedList::append(int data) {
  if (head == NULL) {
    head = new Node(data);
    return;
  }
  Node* newNode = new Node(data);
  Node* currentNode = head;
  while(currentNode->next != NULL) {
    currentNode = currentNode->next;
  }
  currentNode->next = newNode;
}

void LinkedList::insertAt(int data, int ind) {
  if (ind == 0) {
    prepend(data);
    return;
  }
  Node* newNode = new Node(data);
  Node* prevNode = nodeAtInd(ind - 1);
  newNode->next = prevNode->next;
  prevNode->next = newNode;
}

void LinkedList::remove(int data) {
  if (head == NULL) {
    return;
  }
  if (head->data == data) {
    Node* temp = head;
    head = head->next;
    delete temp;
    return;
  }
  Node* currentNode = head;
  while(currentNode->next != NULL) {
    if (currentNode->next->data == data) {
      Node* temp = currentNode->next;
      currentNode->next = currentNode->next->next;
      delete temp;
      return;
    }
    currentNode = currentNode->next;
  }
}

void LinkedList::removeAt(int ind) {
  if (ind == 0) {
    Node* temp = head;
    head = head->next;
    delete temp;
    return;
  }
  Node* prevNode = nodeAtInd(ind - 1);
  Node* currentNode = prevNode->next;
  prevNode->next = currentNode->next;
  delete currentNode;
}

int LinkedList::size() {
  int size = 0;
  Node* currentNode = head;
  while(currentNode != NULL) {
    size++;
    currentNode = currentNode->next;
  }
  return size;
}

void LinkedList::print() {
  Node* currentNode = head;
  while(currentNode != NULL) {
    if (currentNode == head) {
      cout << currentNode->data;
    } 
    else {
      cout << "->" << currentNode->data;
    }
    currentNode = currentNode->next;
  }
  cout << "->NULL" << endl;
}

int main()
{
  LinkedList* list = new LinkedList();
  while (true) {
    cout << ::endl << "-------------------------------------------------" << endl << endl;
    cout << "1. Prepend" << endl;
    cout << "2. Append" << endl;
    cout << "3. Insert at" << endl;
    cout << "4. Remove" << endl;
    cout << "5. Remove at" << endl;
    cout << "6. Search" << endl;
    cout << "7. Size" << endl;
    cout << "8. Exit" << endl;
    cout << endl << "-------------------------------------------------" << endl;
    list->print();
    cout << "-------------------------------------------------" << endl << endl;
    int choice;
    cin >> choice;
    if (choice == 1) {
      int data;
      cout << "Enter data: ";
      cin >> data;
      list->prepend(data);
    }
    else if (choice == 2) {
      int data;
      cout << "Enter data: ";
      cin >> data;
      list->append(data);
    }
    else if (choice == 3) {
      int data, ind;
      cout << "Enter data: ";
      cin >> data;
      cout << "Enter index: ";
      cin >> ind;
      list->insertAt(data, ind);
    }
    else if (choice == 4) {
      int data;
      cout << "Enter data: ";
      cin >> data;
      list->remove(data);
    }
    else if (choice == 5) {
      int ind;
      cout << "Enter index: ";
      cin >> ind;
      list->removeAt(ind);
    }
    else if (choice == 6) {
      int data;
      cout << "Enter data: ";
      cin >> data;
      Node* temp = list->search(data);
      if (temp == NULL) {
        cout << "Not found" << endl;
      }
      else {
        cout << "Found: " << temp->data << endl;
      }
    }
    else if (choice == 7) {
      cout << "Size: " << list->size() << endl;
    }
    else if (choice == 8) {
      break;
    }
  }
  return 0;
}
