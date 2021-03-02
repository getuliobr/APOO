#include<iostream>

using namespace std;
class Node {
  private:
    int value;
    Node* next;
    Node* previous;

  public:
    Node(int value, Node* previous = NULL, Node* next = NULL) {
      this->value = value;
      this->previous = previous;
      this->next = next;
    }

    void setNext(Node* next) {
      this->next = next;
    }

    Node* getNext() {
      return next;
    }

    void setPrevious(Node* previous) {
      this->previous = previous;
    }

    Node* getPrevious() {
      return previous;
    }

    void setValue(int value) {
      this->value = value;
    }

    int getValue() {
      return value;
    }
};

class Queue {
  private:
    Node* next;
    int count = 0;

  public:
    ~Queue() {
      Node* aux;
      Node* prox = next;
      for(int i = 0; i < count; i++) {
        aux = prox;
        prox = prox->getNext();
        delete aux;
      }
    }

    void add(int value) {
      Node* aux;
      Node* mov; // Used to move inside the queue

      if(count == 0) {
        aux = new Node(value);
        this->next = aux;
        count++;
        return;
      }

      mov = this->next;
      for(int i = 1; i < count; i++) { // Starts at 1 because you already got the first element
        mov = mov->getNext();
      }

      aux = new Node(value, mov);
      mov->setNext(aux);
      count++;
    }

    int remove() {
      if(count == 0) throw "Queue is empty!";
      Node* aux = this->next;
      int out = aux->getValue();
      this->next = aux->getNext();
      delete aux;
      count--;

      return out;
    }

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
  Queue* s1 = new Queue;
  s1->add(1);
  s1->add(2);
  s1->add(3);
  s1->add(4);
	s1->print();
  s1->remove();
	s1->print();
  s1->remove();
	s1->print();
  s1->remove();
	s1->print();
  s1->remove();
	s1->print();
}