#include <iostream>
#include "VotesArray.h"

using namespace std;

namespace proj1 {

  VotesArray::VotesArray(int _length) : length(_length), size(_length) {
    if (this->arr) 
      delete[] this->arr;

    if (length > 0) {
      this->arr = new int[length];
    }
  }

  VotesArray::VotesArray(const VotesArray& other) 
    : VotesArray::VotesArray(sizeof(other.arr) / sizeof(int)) 
  {
    for (int i = 0; i < sizeof(other.arr) / sizeof(int); i++) {
      this->arr[i] = other.arr[i];
    }

    this->length = other.length;
    this->size = other.size;
  }
  
  VotesArray::~VotesArray() {
    delete[] arr;
  }

  void VotesArray::push(int val) {
  
    if (size == length) {
      size = size > 0 ? size * 2 : 1;
      int * temp = new int[size];

      for (int i = 0; i < length; i++)
        temp[i] = arr[i];

      delete[] arr;
      arr = temp;
    }
    arr[length] = val;
    length++;
  }

  void VotesArray::set(int index, int val) const {
    arr[index] = val;
  }

  const int& VotesArray::get(int index) const {
    return this->arr[index];
  }
}