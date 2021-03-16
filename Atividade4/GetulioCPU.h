#pragma once
#include <iostream>
#include<string> 
enum typeKeyboard {NUMBER, OPERATION};

class CPU {
  protected:
    bool pickDisplayNumberOverNumberB;
    float NumberA = 0; //Last Number
    float NumberB = 0; //Actual Number
    float displayNumber = 0;
    bool overwritable = false;
    char operationInQueue = '.';

    int digitsInDecimals = 0;


  public:
    float getDisplayNumber() {
      float output = (pickDisplayNumberOverNumberB ? displayNumber : NumberB);
      pickDisplayNumberOverNumberB = false;
      return output;
    };
    virtual void makeOperation(char operation) = 0;
    virtual void getPressedKey(char key, typeKeyboard keyType) = 0;
};