#pragma once
#include <iostream>
#include "Party.h"

using namespace std;

namespace proj1 {
  class PartiesArray {
    private:
      Party * parties = nullptr;
      int length = 0;
      int size = 0;
    public:
      explicit PartiesArray(int length = 0);
      PartiesArray(const PartiesArray& other);
      ~PartiesArray();

      int getLength() const { return length; }
      
      void push(const Party &party);
      void set(int index, const Party &party = Party()) const;
      const Party& get(int index) const;

      Party&operator[](int idx) { return parties[idx]; }
      const Party&operator[](int idx) const { return parties[idx]; }
  };
}