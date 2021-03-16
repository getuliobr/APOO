#pragma once
#include "Headers.h"
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

class MyDisplay: public Display{
  public:
    MyDisplay(CPU* UsedCPU): Display(UsedCPU) {}
    
    void updateNumber(){
      cout << this->UsedCPU->getDisplayNumber() << endl;
    }
};
