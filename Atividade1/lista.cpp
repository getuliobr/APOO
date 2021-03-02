#include<iostream>

using namespace std;
class Node {
  private:
    int value;
    Node* next;

  public:
    Node(int value, Node* next = NULL) {
      this->value = value;
      this->next = next;
    }

    void setNext(Node* next) {
      this->next = next;
    }

    Node* getNext() {
      return next;
    }

    void setValue(int value) {
      this->value = value;
    }

    int getValue() {
      return value;
    }
};

class List {
  private:
    int count = 0;
    Node* next;

    bool inRange(int index) {
      return !(index < 0 || index > count);
    }
  
  public:
    ~List() {
      Node* aux;
      Node* prox = next;
      for(int i = 0; i < count; i++) {
        aux = prox;
        prox = prox->getNext();
        delete aux;
      }
    }

    void insert(int value, int index = 0) {
      if (!inRange(index)) throw "Index out of range while inserting!";
      Node* aux;
      Node* mov; // Used to move inside the list

      count++;

      if(index == 0) {
        aux = new Node(value, this->next);
        this->next = aux;
        return;
      }

      mov = this->next;
      for(int i = 1; i < index; i++) { // Starts at 1 because you already got the first element
        mov = mov->getNext();
      }

      aux = new Node(value, mov->getNext());
      mov->setNext(aux);
    }

    void replace(int value, int index = 0) {
      if (!inRange(index)) throw "Index out of range while replacing!";

      if(index == count) {
        insert(value, index);
        return;
      }

      Node* mov;

      mov = this->next;
      for(int i = 0; i < index; i++) {
        mov = mov->getNext();
      }

      mov->setValue(value);
    };

    int remove(int index = 0) {
      if (count == 0) throw "Empty list!";
      if (!inRange(index) || index == count) throw "Index out of range while removing!";

      count--;

      int out;
      Node* aux;
      Node* mov;

      if(index == 0) {
        aux = this->next;
        out = aux->getValue();
        this->next = aux->getNext();
        delete aux;
        return out;
      }

      mov = this->next;
      aux = mov->getNext(); // Always one forward

      for(int i = 1; i < index; i++) { // Starts at 1 because you already got the first element
        mov = mov->getNext();
        aux = mov->getNext(); 
      }

      out = aux->getValue();
      mov->setNext(aux->getNext());

      return out;
    };
    
    int getCount() {
      return count;
    }

    void print() {
      cout << "[";
      Node* mov = this->next;
      for(int i = 0; i < count; i++) {
        cout << mov->getValue();
        if (i != count - 1) cout << ", ";
        mov = mov->getNext();
      }
      cout << "]" << endl;
    }

};


int main() {
  List * s1 = new List();

  s1->insert(1);
  s1->insert(2, 1);
  s1->insert(3, 1);
  s1->print();

  s1->replace(0,0);
  s1->replace(2,2);
  s1->replace(1,1);
  s1->print();

  cout << s1->remove(2) << endl;
  cout << s1->remove(1) << endl;
  cout << s1->remove(0) << endl;
  s1->print();

  delete s1;
}