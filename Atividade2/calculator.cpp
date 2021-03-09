#include<iostream>
#include <string>	
#include <cmath>	

using namespace std;

class Display {
  protected:
    int digitsInDecimals = 0;

  public:

    void clearDisplay() {
      for(int i = 0; i < 50; i++) cout << endl;
    }

    void showValue(float value) {
      cout << value << endl;
    }
};

class Keyboard {
  public:
    virtual void pressZero() = 0;
    virtual void pressOne() = 0;
    virtual void pressTwo() = 0;
    virtual void pressThree() = 0;
    virtual void pressFour() = 0;
    virtual void pressFive() = 0;
    virtual void pressSix() = 0;
    virtual void pressSeven() = 0;
    virtual void pressEight() = 0;
    virtual void pressNine() = 0;

    virtual void pressDot() = 0;

    virtual void pressAdd() = 0;
    virtual void pressMinus() = 0;
    virtual void pressTimes() = 0;
    virtual void pressSlash() = 0;
    virtual void pressEqual() = 0;
    virtual void pressRoot() = 0;
    virtual void pressPercentage() = 0;

    virtual void pressClearMemory() = 0;
};

class CPU: public Keyboard, public Display {
  private:
    char operationInQueue = '.';
    bool overwritable = false;
    float registers[2] = {0, 0};
    
    void resetFirstRegister() {
      registers[0] = 0;
      digitsInDecimals = 0;
    }

    void updateDisplay(int registerNumber) {
      showValue(registers[registerNumber]);
    }

    void updateDecimals(int registerNumber, int number) {
      if(overwritable && registerNumber == 0) {
        registers[registerNumber] = 0;
        digitsInDecimals = 0;
        overwritable = false;
      }
      registers[registerNumber] += number/pow(10, digitsInDecimals);
      digitsInDecimals++;
    }

    void updateNumber(int registerNumber, int number) {
      if(overwritable && registerNumber == 0) {
        registers[registerNumber] = 0;
        overwritable = false;
      }
      registers[registerNumber] = registers[registerNumber] * 10 + number;
    }

    void solve() {
      switch (operationInQueue) {
        case '+':
          registers[0] = registers[1] + registers[0];
          break;
        
        case '-':
          registers[0] = registers[1] - registers[0];
          break;

        case '*':
          registers[0] = registers[1] * registers[0];
          break;

        case '/':
          if(registers[0] == 0) throw "Cannot divide by zero.";
          registers[0] = registers[1] / registers[0];
          break;

        default:
          break;
      }
      registers[1] = registers[0];
      updateDisplay(0);
      resetFirstRegister();
    }

  public:
    void pressZero() {
      if(digitsInDecimals) digitsInDecimals++;
      else if(registers[0]) registers[0] *= 10;
      updateDisplay(0);
    }
    void pressOne() {
      if(digitsInDecimals) updateDecimals(0, 1);
      else updateNumber(0, 1);
      updateDisplay(0);
    }
    void pressTwo() {
      if(digitsInDecimals) updateDecimals(0, 2);
      else updateNumber(0, 2);
      updateDisplay(0);
    }
    void pressThree() {
      if(digitsInDecimals) updateDecimals(0, 3);
      else updateNumber(0, 3);
      updateDisplay(0);
    }
    void pressFour() {
      if(digitsInDecimals) updateDecimals(0, 4);
      else updateNumber(0, 4);
      updateDisplay(0);
    }
    void pressFive() {
      if(digitsInDecimals) updateDecimals(0, 5);
      else updateNumber(0, 5);
      updateDisplay(0);
    }
    void pressSix() {
      if(digitsInDecimals) updateDecimals(0, 6);
      else updateNumber(0, 6);
      updateDisplay(0);
    }
    void pressSeven() {
      if(digitsInDecimals) updateDecimals(0, 7);
      else updateNumber(0, 7);
      updateDisplay(0);
    }
    void pressEight() {
      if(digitsInDecimals) updateDecimals(0, 8);
      else updateNumber(0, 8);
      updateDisplay(0);
    }
    void pressNine() {
      if(digitsInDecimals) updateDecimals(0, 9);
      else updateNumber(0, 9);
      updateDisplay(0);
    }

    void pressDot() {
      if(!digitsInDecimals) digitsInDecimals++;
    }

    void pressAdd() {
      solve();
      operationInQueue = '+';
    }

    void pressMinus() {
      solve();
      operationInQueue = '-';
    }

    void pressTimes() {
      solve();
      operationInQueue = '*';
    };

    void pressSlash() {
      solve();
      operationInQueue = '/';
    };

    void pressEqual() {
      solve();
      operationInQueue = '.';
    }

    void pressRoot() {
      if(registers[0] < 0) throw "No sqrt of a negative number";
      registers[0] = sqrt(registers[0]);
      updateDisplay(0);
      overwritable = true;
    }

    void pressPercentage() {
      registers[0] /= 100;
      registers[0] *= registers[1];
      solve();
      operationInQueue = '.';
    };

    void pressClearMemory() {
      registers[1] = 0;
      resetFirstRegister();
      updateDisplay(0);
      operationInQueue = '.';
    }
};

class Calculator: private CPU {
  public:
    void getUserInput() {
      char keyPressed;
      cout << "Press a key: ";
      cin >> keyPressed;
      switch (keyPressed) {
        case '0':
          pressZero();
          break;
        case '1':
          pressOne();
          break;
        case '2':
          pressTwo();
          break;
        case '3':
          pressThree();
          break;
        case '4':
          pressFour();
          break;
        case '5':
          pressFive();
          break;
        case '6':
          pressSix();
          break;
        case '7':
          pressSeven();
          break;
        case '8':
          pressEight();
          break;
        case '9':
          pressNine();
          break;

        case '.':
          pressDot();
          break;
        

        case '+':
          pressAdd();
          break;
        case '-':
          pressMinus();
          break;
        case '/':
          pressSlash();
          break;
        case '*':
          pressTimes();
          break;

        case 'S':
        case 's':
          pressRoot();
          break;
        case '%':
          pressPercentage();
          break;
        case '=':
          pressEqual();
          break;

        case 'M':
        case 'm':
          pressClearMemory();
          break;
        
        default:
          break;
      }
    }
};


int main() {
  Calculator* calc = new Calculator();
  while(true) calc->getUserInput();
}