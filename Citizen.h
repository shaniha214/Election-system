#pragma once
#include <iostream>
#include "string.h"

using namespace std;

namespace proj1 {
  class Citizen {
    private:
      char * name = nullptr;
      int id;
      int birthYear;
      int stateId;
      bool isVoted = false;

    public:
      Citizen();
      Citizen(char * name, int id, int birthYear, int stateId, bool isVoted = false);
      Citizen(const Citizen& other);
      ~Citizen();
      
      const Citizen& operator=(const Citizen& other);
      
      char * getName() const { return this->name; }
      int getId() const { return this->id; }
      int getBirthYear() const { return this->birthYear; }
      int getStateId() const { return this->stateId; }
      bool getIsVoted() const { return this->isVoted; }

      bool setName(char * _name);
      bool setId(int _id) { return id = _id; }
      bool setBirthYear(int _birthYear) { return birthYear = _birthYear; }
      bool setIsVoted(int _isVoted) { return isVoted = _isVoted; }
      bool setStateId(int _stateId) { return stateId = _stateId; }

      friend ostream& operator<<(ostream& os, const Citizen& citizen);
  };
}