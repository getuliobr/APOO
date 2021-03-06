#pragma once
#include "GetulioCPU.h"

class NumericKeyboard {
  protected:
    CPU* UsedCPU;
  public:
    NumericKeyboard(CPU* UsedCPU) {
      this->UsedCPU = UsedCPU;
    }
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
};

class OperationKeyboard {
  protected:
    CPU* UsedCPU;
  public:
    OperationKeyboard(CPU* UsedCPU) {
      this->UsedCPU = UsedCPU;
    }
    virtual void pressPlus() = 0;
    virtual void pressClear() = 0;
    virtual void pressMinus() = 0;
    virtual void pressEqual() = 0;
    virtual void pressDivide() = 0;
    virtual void pressTimes() = 0;
    virtual void pressPercent() = 0;
    virtual void pressSquare() = 0;
    virtual void pressReset() = 0;
};