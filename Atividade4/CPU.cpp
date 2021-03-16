#include "Headers.h"
#include<iostream>
#include <string>	
#include <cmath>

// class CPU {
//   protected:
//     float NumberA = NULL; //Last Number
//     float NumberB = 0; //Actual Number
//     char LastOperation;
//     char LastNumeric;
//     char LastOperationKey;
//     bool LastKeyType;
//     bool DotFlag = false;

//     float getDisplayNumber() {
//       return NumberB;
//     };

//   public:
//     virtual void makeOperation(char operation);
//     virtual void getPressedKey(char key, typeKeyboard keyType);
// };

class MyCPU: public CPU {
  protected:
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

        default:
          break;
      }
      NumberA = NumberB;
      operationInQueue = operation;
    }

    void getPressedKey(char key, typeKeyboard keyType) {
      switch(keyType) {
        case NUMBER:
          if(key == '.' && !digitsInDecimals) {
            digitsInDecimals++;
            break;
          }
          int newNumber = atoi(key);
          if(digitsInDecimals) updateDecimals(newNumber);
          else updateNumber(newNumber);
          break;
        case OPERATION:
          makeOperation(key);
          break;
      }
    }
}