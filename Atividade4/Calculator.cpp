#include "Headers.h"
#include "CPU.cpp"
#include "Display.cpp"
#include "Keyboards.cpp"

class MyCalculator: public Calculator {
  public:
    MyCalculator() {
      this->CalculatorCPU = new MyCPU();
      this->CalculatorNumericKeyboard = new MyNumericalKeyboard(this->CalculatorCPU);
      this->CalculatorOperationKeyboard = new MyOperationKeyboard(this->CalculatorCPU);
      this->CalculatorDisplay = new MyDisplay(this->CalculatorCPU);
    }
    virtual void CalculatorPress(char key) = 0;
};