#pragma once
#include "GetulioCPU.h"

class Display {
  protected:
    float DisplayNumber;
    CPU* UsedCPU;
  public:
    Display(CPU* UsedCPU){
        this->UsedCPU = UsedCPU;
    }
    virtual void updateNumber() = 0;
};