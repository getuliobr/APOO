#pragma once
#include "GetulioCPU.h"
#include "GetulioDisplay.h"
#include "GetulioKeyboards.h"

class Calculator {
  protected:
    CPU* CalculatorCPU;
    NumericKeyboard* CalculatorNumericKeyboard;
    OperationKeyboard* CalculatorOperationKeyboard;
    Display* CalculatorDisplay;
  public:
    virtual void CalculatorPress(char key) = 0;
};