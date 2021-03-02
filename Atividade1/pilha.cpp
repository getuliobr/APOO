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

class Stack {
  private:
    Node* next;
    int count = 0;

  public:
    ~Stack() {
      Node* aux;
      Node* prox = next;
      for(int i = 0; i < count; i++) {
        aux = prox;
        prox = prox->getNext();
        delete aux;
      }
    }

    void push(int value) {
      Node* aux;
      Node* mov; // Used to move inside the stack

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

    int pop() {
      if(count == 0) throw "Stack is empty!";
      int out;
      if(count == 1) {
        out = this->next->getValue();
        delete this->next;
        this->next = NULL;
        count--;
        return out;
      }

      Node* mov = this->next;
      for(int i = 1; i < count; i++) {
        mov = mov->getNext();
      }

      out = mov->getValue();

      mov->getPrevious()->setNext(NULL);
      delete mov;
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
  Stack * s1 = new Stack();
  s1->push(1);
  s1->push(2);
  s1->push(3);
  s1->push(4);
	s1->print();
  s1->pop();
  s1->pop();
  s1->pop();
  s1->pop();
	s1->print();
}