#define _CRT_SECURE_NO_WARNINGS

#include "Party.h"
#include "Menu.h"

namespace proj1 {
  Party::Party() : Party(0, nullptr, Citizen()) {}

  Party::Party(int _id, char * _name, const Citizen& _nominee) : id(_id), nominee(_nominee), members(MembersArray()), membersWonCount(0), votesCount(0) {
    if (_name) {
      name = new char[strlen(_name) + 1];
      name[strlen(_name)] = '\0';
      strcpy(name, _name);
    }
  }

  const Party& Party::operator=(const Party& other) {
    id = other.id;
    name = new char[strlen(other.name) + 1];
    name[strlen(other.name)] = '\0';
    strcpy(name, other.name);

    nominee = Citizen(other.nominee);
    members = other.members;
    membersWonCount = other.membersWonCount;
    votesCount = other.votesCount;
    return *this;
  }

  Party::~Party() {
    delete[] name;
  }

  void Party::addMember(int stateIndex, const Citizen& member) {
    this->members[stateIndex].push(member);
  }
  
  const Citizen& Party::getMember(int stateIndex, int memeberIndex) {
    return this->members[stateIndex][memeberIndex];
  }

  ostream& operator<<(ostream& os, const Party& party) {
    os << 
      "name: " << party.getName() <<
      ", id: " << party.getId() << endl <<
      "------------------\n\n" <<
      "Party's nominee: \n\n" << party.getNominee() << "\n\n" <<
      "------------------\n\n" <<
      "Members: \n\n" << party.getMembers() << endl;
    return os;
  }
}
  
