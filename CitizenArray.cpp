#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Citizen.h"
#include "CitizenArray.h"

using namespace std;

namespace proj1 {

  CitizenArray::CitizenArray(int _length) : length(_length), size(_length) {
    if (this->arr) 
      delete[] this->arr;

    if (length > 0) {
      this->arr = new Citizen[length];
    }
  }

  CitizenArray::CitizenArray(const CitizenArray& other) 
    : CitizenArray::CitizenArray(sizeof(other.arr) / sizeof(Citizen)) 
  {
    for (int i = 0; i < sizeof(other.arr) / sizeof(Citizen); i++) {
      this->arr[i] = Citizen(other.arr[i]);
    }

    this->length = other.length;
    this->size = other.size;
  }

  const CitizenArray& CitizenArray::operator=(const CitizenArray& other) {
    arr = new Citizen[other.length];
    for (int i = 0; i < other.length; i++)
      arr[i] = other.arr[i];
    return *this;
  }
  
  CitizenArray::~CitizenArray() {
    delete[] arr;
  }

  void CitizenArray::push(const Citizen& citizen) {
    
    if (size == length) {
      size = size > 0 ? size * 2 : 1;
      Citizen * temp = new Citizen[size];

      for (int i = 0; i < length; i++)
        temp[i] = arr[i];

      delete[] arr;
      arr = temp;
    }
    arr[length] = citizen;
    length++;
  }

  void CitizenArray::set(int index, const Citizen &citizen) const {
    arr[index] = citizen;
  }

  void CitizenArray::set(int index, char * name, int id, int birthYear, int stateId, bool isVoted) const {
    arr[index] = Citizen(name, id, birthYear, stateId, isVoted);
  }

  const Citizen& CitizenArray::get(int index) const {
    return this->arr[index];
  }

  ostream& operator<<(ostream& os, const CitizenArray& citizens) {
    for (int i = 0; i < citizens.length; i++)
      os << citizens[i] << endl;
    return os;
  }
}