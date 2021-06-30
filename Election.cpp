#include "Election.h"

namespace proj1 {
  Election::Election() : Election(CitizenArray(), PartiesArray(), StatesArray(), 0, 0, 0) {}

  Election::Election(int _day, int _month, int _year) : Election(CitizenArray(), PartiesArray(), StatesArray(), _day, _month, _year) {}

  Election::Election(
    const CitizenArray& _voters,
    const PartiesArray& _parties,
    const StatesArray& _states,
    int _day, int _month, int _year
  ) : 
    day(_day), month(_month), year(_year),
    voters(_voters), parties(_parties), states(_states) {}

  Election::~Election() {
    // Destructor
  }

  void Election::addState(const State& state) {
    // adds a "slot" for each state in the members array
    for (int i = 0; i < parties.getLength(); i++)
      parties[i].getMembers().push(CitizenArray());
    // adds a new state
    states.push(state);
  }

  void Election::addParty(int id, char * name, const Citizen& nominee) {
    Party temp(id, name, nominee);
    
    for (int i = 0; i < states.getLength(); i++) {
      // creates a new slot for members of every exisiting state
      temp.getMembers().push(CitizenArray());
      // creates a new ballot in every state for the new "temp" party
      states[i].getVotesByParty().push(); 
    }

    // adds a new party
    parties.push(temp);
  } 

  void Election::addVoter(const Citizen& voter) {
    // adds the voter
    voters.push(voter); 
    // registers the voter in his state
    states[voter.getStateId()].getVoters().push(voter);
  }

  int Election::findCitizenIdx(int id) {
    for (int i = 0; i < getVoters().getLength(); i++) {
      if (getVoters()[i].getId() == id)
        return i;
    }
    return -1;
  }

  void Election::vote(Election& election, int voterIndex, int partyId) {
    // get ids from the voter
    int stateId = election.getVoters()[voterIndex].getStateId();
    int voterId = election.getVoters()[voterIndex].getId();
    
    // set a flag that the citizen has voted
    election.getVoters()[voterIndex].setIsVoted(true);

    // find the voter in the state array and set his voting status to true
    CitizenArray& votersInState = election.getStates()[stateId].getVoters();
    for (int i = 0; i < votersInState.getLength(); i++) {
      if (votersInState[i].getId() == voterId)
        votersInState[i].setIsVoted(true);
    }

    // cast the vote in the party ballot
    states[stateId].getVotesByParty()[partyId]++;

    // calculate and update the new voter percentage
    states[stateId].setPvoters(
      100 * 
      (static_cast<float>(states[stateId].countAllVotes()) /
      states[stateId].getVoters().getLength())
    );
  }

  void Election::addMember(int partyId, int stateId, const Citizen& member) {
    // increment the number of members registered in parties
    states[stateId].incMembersUsed();
    // adds the member to the party
    parties[partyId].addMember(stateId, member);
  }
}