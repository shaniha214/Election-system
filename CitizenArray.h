#pragma once
#include <iostream>
#include "Citizen.h"

using namespace std;

namespace proj1 {
  class CitizenArray {
    private:
      Citizen * arr = nullptr;
      int length = 0;
      int size = 0;
    public:
      explicit CitizenArray(int length = 0);
      CitizenArray(const CitizenArray& other);
      ~CitizenArray();

      const CitizenArray& operator=(const CitizenArray& other);

      int getSize() const { return size; }
      int getLength() const { return length; }
      
      void push(const Citizen &citizen);
      void set(int index, const Citizen &citizen = Citizen()) const;
      void set(int index, char * name, int id, int birthYear, int stateId, bool isVoted) const;
      const Citizen& get(int index) const;

      Citizen&operator[](int idx) { return arr[idx]; }
      const Citizen&operator[](int idx) const { return arr[idx]; }

      friend ostream& operator<<(ostream& os, const CitizenArray& citizens);
  };
}