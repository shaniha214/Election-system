#include "PartiesArray.h"
#include "Party.h"

namespace proj1 {

  PartiesArray::PartiesArray(int _length) : length(_length), size(_length) {
    if (this->parties != nullptr) 
      delete[] this->parties;

    if (length > 0) {
      this->parties = new Party[length];
    }
  }

  PartiesArray::PartiesArray(const PartiesArray& other) 
    : PartiesArray::PartiesArray(sizeof(other.parties) / sizeof(Party)) 
  {
    for (int i = 0; i < sizeof(other.parties) / sizeof(Party); i++) {
      this->parties[i] = Party(other.parties[i]);
    }

    this->length = other.length;
    this->size = other.size;
  }
  
  PartiesArray::~PartiesArray() {
    delete[] parties;
  }

  void PartiesArray::push(const Party& party) {
    if (size == length) {
      size = size > 0 ? size * 2 : 1;
      Party * temp = new Party[size];

      for (int i = 0; i < length; i++)
        temp[i] = parties[i];

      delete[] parties;
      parties = temp;
    }
    parties[length] = party;
    length++;
  }

  void PartiesArray::set(int index, const Party &party) const {
    parties[index] = party;
  }

  const Party& PartiesArray::get(int index) const {
    return this->parties[index];
  }
}