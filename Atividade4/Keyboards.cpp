#pragma once
#include "Headers.h"
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

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
};