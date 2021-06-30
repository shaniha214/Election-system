#pragma once
#include "Party.h"
#include "VotesArray.h"

namespace proj1 {
	class State {
    private:
      char * name;
      int id;
      int memberCount;
      int membersUsed;
      int Pvoters;
      CitizenArray voters;
      VotesArray votesByParty;

    public:	
      State();
      State(char * _name, int _id, int _memberCount);
      ~State();
      const State& operator=(const State& other);

      bool setPvoters(int _Pvoters) { return Pvoters = _Pvoters; }

      char * getName() const { return this->name; };
      int getId() const { return this->id; };
      int getPvoters() const { return this->Pvoters; };
      int getMemberCount() const { return this->memberCount; }
      int getMembersUsed() const { return this->membersUsed; }
      CitizenArray& getVoters() { return voters; };
      const CitizenArray& getVoters() const { return this->voters; }
      VotesArray& getVotesByParty() { return votesByParty; };
      const VotesArray& getVotesByParty() const { return votesByParty; }

      void incMembersUsed() { membersUsed++; }
      int countAllVotes() const;
      int findPartyWinnerIdx() const;

      friend ostream& operator<<(ostream& os, const State& state);
  };
}
