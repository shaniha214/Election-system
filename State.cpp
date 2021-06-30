#define _CRT_SECURE_NO_WARNINGS

#include "State.h"
#include "Menu.h"

namespace proj1 {

	State::State() : State(nullptr, 0, 0) {}

	State::State(char * _name, int _id, int _memberCount) : id(_id), memberCount(_memberCount), membersUsed(0), Pvoters(0), voters(CitizenArray()), votesByParty(VotesArray()) {
		if (_name) {
      this->name = new char[strlen(_name) + 1];
		  strcpy(name, _name);
    }
	}
      
  const State& State::operator=(const State& other) {
    id = other.id;
    name = new char[strlen(other.name) + 1];
    name[strlen(other.name)] = '\0';
    strcpy(name, other.name);

    memberCount = other.memberCount;
    membersUsed = other.membersUsed;
    Pvoters = other.Pvoters;
    voters = other.voters;
    votesByParty = other.votesByParty;
    return *this;
  }

	State::~State() {
		delete[] name;
	}

  int State::countAllVotes() const {
    int counter = 0;
    // count all votes in all ballots
    for (int i = 0; i < votesByParty.getLength(); i++) {
      counter += votesByParty[i];
    }
    return counter;
  }

  int State::findPartyWinnerIdx() const {
    int winnerIdx = 0;
    int maxVotes = 0;
    for (int i = 0; i < getVotesByParty().getLength(); i++) {
      if (getVotesByParty()[i] > maxVotes) {
        maxVotes = getVotesByParty()[i];
        winnerIdx = i;
      }
    }
    return winnerIdx;
  }


	ostream& operator<<(ostream& os, const State& state) {
    os << 
      "name: " << state.getName() << endl <<
      "id: " << state.getId() << endl <<
      "Member count: " << state.getMemberCount() << endl <<
      "Percentage of voters: ";
      
    if (state.getVoters().getLength() == 0) {
      os << "N/A\n";
      return os;
    }

    os 
      << state.getPvoters() << "%" << endl <<
      "Resgistered Voters in " << state.getName() << ":\n\n" << 
      state.getVoters();
      
    return os;
  }
}