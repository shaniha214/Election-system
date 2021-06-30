#pragma once
#include <iostream>
#include "State.h"

using namespace std;

namespace proj1 {
  class StatesArray {
    private:
      State * states = nullptr;
      int length = 0;
      int size = 0;
    public:
      explicit StatesArray(int length = 0);
      StatesArray(const StatesArray& other);
      ~StatesArray();

      int getLength() const { return length; }
      
      void push(const State &state);
      void set(int index, const State &state = State()) const;
      const State& get(int index) const;

      State&operator[](int idx) { return states[idx]; }
      const State&operator[](int idx) const { return states[idx]; }
  };
}