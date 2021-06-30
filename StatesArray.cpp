#include "State.h"
#include "StatesArray.h"

namespace proj1 {

  StatesArray::StatesArray(int _length) : length(_length), size(_length) {
    if (this->states) 
      delete[] this->states;

    if (length > 0) {
      this->states = new State[length];
    }
  }

  StatesArray::StatesArray(const StatesArray& other) 
    : StatesArray::StatesArray(sizeof(other.states) / sizeof(State)) 
  {
    for (int i = 0; i < sizeof(other.states) / sizeof(State); i++) {
      this->states[i] = State(other.states[i]);
    }

    this->length = other.length;
    this->size = other.size;
  }
  
  StatesArray::~StatesArray() {
    delete[] states;
  }

  void StatesArray::push(const State& state) {

    if (size == length) {
      size = size > 0 ? size * 2 : 1;
      State * temp = new State[size];

      for (int i = 0; i < length; i++)
        temp[i] = states[i];

      delete[] states;
      states = temp;
    }
    states[length] = state;
    length++;
  }

  void StatesArray::set(int index, const State &state) const {
    states[index] = state;
  }

  const State& StatesArray::get(int index) const {
    return this->states[index];
  }
}