#include "GetulioCalculator.h"
#include <iostream>
#include <string>	
#include <cmath>	

using namespace std;

class MyCPU: public CPU {
  private:
    void updateDecimals(int number) {
      if(overwritable) {
        NumberB = 0;
        digitsInDecimals = 0;
        overwritable = false;
      }
      NumberB += number/pow(10, digitsInDecimals);
      digitsInDecimals++;
    }

    void updateNumber(int number) {
      if(overwritable) {
        NumberB = 0;
        overwritable = false;
      }
      NumberB = NumberB * 10 + number;
    }

  public:
    void makeOperation(char operation) {
      switch (operationInQueue) {
        case '+':
          NumberB = NumberA + NumberB;
          break;
          
        case '-':
          NumberB = NumberA - NumberB;
          break;

        case '*':
          NumberB = NumberA * NumberB;
          break;

        case '/':
          if(NumberB == 0) throw "Cannot divide by zero.";
          NumberB = NumberA / NumberB;
          break;

        case '%':
          NumberB /= 100;
          NumberB *= NumberA;
          makeOperation(operationInQueue);
          operationInQueue = '.';
          return;
        
        case 'S':
          if(NumberB < 0) throw "No sqrt of a negative number";
          NumberB = sqrt(NumberB);
          overwritable = true;
          return;
        
        case 'R':
          overwritable = displayNumber = digitsInDecimals = NumberA = NumberB = 0;
          operationInQueue = '.';
          return;

        case '=':
          makeOperation(operationInQueue);
          operationInQueue = '.';
          return;

        default:
          break;
      }
      pickDisplayNumberOverNumberB = true;
      NumberA = NumberB;
      displayNumber = NumberA;
      NumberB = 0;
      digitsInDecimals = 0;
      operationInQueue = operation;
    }

    void getPressedKey(char key, typeKeyboard keyType) {
      switch(keyType) {
        case NUMBER: {
          if(key == '.' && !digitsInDecimals) {
            digitsInDecimals++;
            break;
          }
          string toConvert;
          toConvert += key;

          int newNumber = stoi(toConvert);
          if(digitsInDecimals) updateDecimals(newNumber);
          else updateNumber(newNumber);
          break;
        }
        case OPERATION:
          makeOperation(key);
          break;
      }
    }
};

class MyNumericalKeyboard: public NumericKeyboard {
  public:
    MyNumericalKeyboard(CPU* UsedCPU): NumericKeyboard(UsedCPU) {}

    void pressZero(){
      this->UsedCPU->getPressedKey('0', NUMBER);
    }
    void pressOne(){
      this->UsedCPU->getPressedKey('1', NUMBER);
    }
    void pressTwo(){
      this->UsedCPU->getPressedKey('2', NUMBER);
    };
    void pressThree(){
      this->UsedCPU->getPressedKey('3', NUMBER);
    };
    void pressFour(){
      this->UsedCPU->getPressedKey('4', NUMBER);
    };
    void pressFive(){
      this->UsedCPU->getPressedKey('5', NUMBER);
    };
    void pressSix(){
      this->UsedCPU->getPressedKey('6', NUMBER);
    };
    void pressSeven(){
      this->UsedCPU->getPressedKey('7', NUMBER);
    }
    void pressEight(){
      this->UsedCPU->getPressedKey('8', NUMBER);
    }
    void pressNine(){
      this->UsedCPU->getPressedKey('9', NUMBER);
    }
    void pressDot(){
      this->UsedCPU->getPressedKey('.', NUMBER);
    }
};

class MyOperationKeyboard: public OperationKeyboard {
  public:
    MyOperationKeyboard(CPU* UsedCPU): OperationKeyboard(UsedCPU) {}

    void pressPlus(){
      this->UsedCPU->getPressedKey('+', OPERATION);
    }
    void pressClear(){
      this->UsedCPU->getPressedKey('C', OPERATION);
    }
    void pressMinus(){
      this->UsedCPU->getPressedKey('-', OPERATION);
    }
    void pressEqual(){
      this->UsedCPU->getPressedKey('=', OPERATION);
    }
    void pressDivide(){
      this->UsedCPU->getPressedKey('/', OPERATION);
    }
    void pressTimes(){
      this->UsedCPU->getPressedKey('*', OPERATION);
    }
    void pressPercent(){
      this->UsedCPU->getPressedKey('%', OPERATION);
    }
    void pressSquare(){
      this->UsedCPU->getPressedKey('S', OPERATION);
    }
    void pressReset() {
      this->UsedCPU->getPressedKey('R', OPERATION);
    }
};

class MyDisplay: public Display{
  public:
    MyDisplay(CPU* UsedCPU): Display(UsedCPU) {}
    
    void updateNumber(){
      cout << this->UsedCPU->getDisplayNumber() << endl;
    }
};

class MyCalculator: public Calculator {
  public:
    MyCalculator() {
      this->CalculatorCPU = new MyCPU();
      this->CalculatorNumericKeyboard = new MyNumericalKeyboard(this->CalculatorCPU);
      this->CalculatorOperationKeyboard = new MyOperationKeyboard(this->CalculatorCPU);
      this->CalculatorDisplay = new MyDisplay(this->CalculatorCPU);
    }

    void CalculatorPress(char key) {
      switch (key) {
        case '0':
          this->CalculatorNumericKeyboard->pressZero();
          break;
        case '1':
          this->CalculatorNumericKeyboard->pressOne();
          break;
        case '2':
          this->CalculatorNumericKeyboard->pressTwo();
          break;
        case '3':
          this->CalculatorNumericKeyboard->pressThree();
          break;
        case '4':
          this->CalculatorNumericKeyboard->pressFour();
          break;
        case '5':
          this->CalculatorNumericKeyboard->pressFive();
          break;
        case '6':
          this->CalculatorNumericKeyboard->pressSix();
          break;
        case '7':
          this->CalculatorNumericKeyboard->pressSeven();
          break;
        case '8':
          this->CalculatorNumericKeyboard->pressEight();
          break;
        case '9':
          this->CalculatorNumericKeyboard->pressNine();
          break;

        case '.':
          this->CalculatorNumericKeyboard->pressDot();
          break;
        

        case '+':
          this->CalculatorOperationKeyboard->pressPlus();
          break;
        case '-':
          this->CalculatorOperationKeyboard->pressMinus();
          break;
        case '/':
          this->CalculatorOperationKeyboard->pressDivide();
          break;
        case '*':
          this->CalculatorOperationKeyboard->pressTimes();
          break;

        case 'S':
        case 's':
          this->CalculatorOperationKeyboard->pressSquare();
          break;
        case '%':
          this->CalculatorOperationKeyboard->pressPercent();
          break;
        case '=':
          this->CalculatorOperationKeyboard->pressEqual();
          break;

        default:
          break;
      }
      this->CalculatorDisplay->updateNumber();
      return;
    };
};

int main() {
  Calculator* calc = new MyCalculator();
  while(true) {
    char keyPressed;
    cin >> keyPressed;
    calc->CalculatorPress(keyPressed);
  }
}