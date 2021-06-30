#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Citizen.h"
#include "Menu.h"

using namespace std;

namespace proj1 {
  Citizen::Citizen() : Citizen(nullptr, 0, 0, 0, false) {}

  Citizen::Citizen(char * _name, int _id, int _birthYear, int _stateId, bool _isVoted) : 
    id(_id), 
    birthYear(_birthYear),
    isVoted(_isVoted),
    stateId(_stateId)
  {
    if (_name) {
      name = new char[strlen(_name) + 1]; 
      name[strlen(_name)] = '\0';
      strcpy(name, _name);
    }
  }

  Citizen::Citizen(const Citizen& other) : 
    id(other.getId()), 
    birthYear(other.getBirthYear()), 
    isVoted(other.getIsVoted()),
    stateId(other.getStateId())
  {
    if (other.getName()) {
      name = new char[strlen(other.getName()) + 1], 
      strcpy(name, other.getName());
    }
  }

  Citizen::~Citizen() {
    delete[] this->name;
  }
   
  const Citizen& Citizen::operator=(const Citizen& other) {
    name = new char[strlen(other.getName()) + 1];

    strcpy(name, other.getName());

    this->id = other.getId();
    this->birthYear = other.getBirthYear();
    this->isVoted = other.getIsVoted();
    this->stateId = other.getStateId();

    return *this;
  }

   bool Citizen::setName(char * _name) {
    if (_name == nullptr)
      return false;

    char * temp = new char[strlen(_name) + 1];
    temp[strlen(_name)] = '\0';
    if (!strcpy(temp, _name)) return false;
    delete[] this->name;
    this->name = temp;
    return true;
  }

  ostream& operator<<(ostream& os, const Citizen& citizen) {
    os << 
      BOLDMAGENTA <<
      "==================\n" <<
      "name: " << citizen.getName() << endl <<
      "id: " << citizen.getId() << endl <<
      "state id: " << citizen.getStateId() << endl <<
      "birth year: " << citizen.getBirthYear() << endl <<
      "did vote: " << (citizen.getIsVoted() ? "Yes" : "No") << endl <<
      "==================\n" <<
      endl << RESET;
    return os;
  }
}