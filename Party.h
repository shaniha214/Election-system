#pragma once
#include "Citizen.h"
#include "CitizenArray.h"
#include "MembersArray.h"

namespace proj1 {
  class Party {
    private:
      int id;
      char * name = nullptr;
      Citizen nominee;
      MembersArray members;
      int membersWonCount;
      int votesCount;
    public:
      Party();
      Party(int _id, char * _name, const Citizen& _nominee);
      ~Party();
      const Party& operator=(const Party& other);

      void addMember(int stateIndex, const Citizen& member);
      const Citizen& getMember(int stateIndex, int memeberIndex);

      int getId() const { return id; }
      char * getName() const { return name; }
      Citizen& getNominee() { return nominee; }
      const Citizen& getNominee() const { return nominee; }
      MembersArray& getMembers() { return members; }
      const MembersArray& getMembers() const { return members; }

      int getMembersWonCount() const { return membersWonCount; }
      int getVotesCount() const { return votesCount; }
      bool setMembersWonCount(int _membersWonCount) { return membersWonCount = _membersWonCount; }
      bool setVotesCount(int _votesCount) { return votesCount = _votesCount; }

      friend ostream& operator<<(ostream& os, const Party& party);
  };
}