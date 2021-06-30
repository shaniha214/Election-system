#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"

namespace proj1 {
  void Menu::displayOptions(const Election& election) {
    cout
      << BOLDBLUE
      << "---------------------------------" << endl <<
      "       ELECTION " << election.getDay() << "/" <<
      election.getMonth() << "/" << election.getYear() << endl
      << "---------------------------------\n\n" << RESET;

    cout 
      << "1. Add a state" << endl
      << "2. Add a citizen" << endl
      << "3. Add a party" << endl
      << "4. Add a member to a party" << endl
      << "5. Display all states" << endl
      << "6. Display all citizens" << endl
      << "7. Display all parties" << endl
      << "8. Vote by ID" << endl
      << "9. Display election results" << endl
      << "10. Exit menu" << endl << endl;

    cout << "Press on the option # for input to be taken." << endl;
  }

  void Menu::displayStates(const Election& election) {
    for (int i = 0; i < election.getStates().getLength(); i++)
      cout << election.getStates()[i] << endl;
  }

  void Menu::displayVoters(const Election& election) {
    for (int i = 0; i < election.getVoters().getLength(); i++)
      cout << election.getVoters()[i] << endl;
  }

  void Menu::displayParties(const Election& election) {
    for (int i = 0; i < election.getParties().getLength(); i++)
      cout << election.getParties()[i] << endl;
  }

  // -----------------------
  //      Menu Options
  // -----------------------

  void Menu::addState(Election& election) {
    char temp[Menu::MAX_LENGTH], *name;
    int memberCount, id;
    // input from user
    cout << "\nEnter the name and number of members in the state" << endl;
    cout << "Name: ";
    cin >> temp;
    cout << "Number of members: ";
    cin >> memberCount;

    // allocate the name
    name = new char[strlen(temp)];
    strcpy(name, temp);

    // adds the state
    id = election.getStates().getLength();
    election.addState(State(name, id, memberCount));

    // confimation message with the newly created ID (which equal its index)
    cout
      << BOLDGREEN 
      << "\n\nState " << name << " was added with ID: " 
      << election.getStates().getLength() - 1 
      << RESET << "\n\n";
  }
  
  void Menu::addCitizen(Election& election){
    election.addVoter(Menu::getCitizen(election));
  }

  void Menu::addMember(Election& election) {
    int memberId, partyId, stateId;
    // input from user
    cout << "\nEnter the member ID: ";
    cin >> memberId;

    // validates that the voter exist
    int memberIndex = election.findCitizenIdx(memberId);
    while (memberIndex == -1) {
      cout 
        << BOLDRED << 
        "\nNo citizen with the member's id was found" 
        << RESET << "\n\n";

      cout << "Enter the member's ID: ";
      cin >> memberId;
      memberIndex = election.findCitizenIdx(memberId);
    }

    // input from user
    partyId = Menu::getPartyIndex(election);
    stateId = Menu::getStateIndex(election);

    int memberCount = election.getStates()[stateId].getMemberCount();
    int membersUsed = election.getStates()[stateId].getMembersUsed();

    // validates that space remain for more members
    if (memberCount == membersUsed) {
      cout 
        << BOLDRED << 
        "\nAll of the state members were already assigned." 
        << RESET << "\n\n";
      return;
    }

    // adds the member
    election.addMember(partyId, stateId, election.getVoters()[memberIndex]);
  }

  void Menu::addParty(Election& election) {
    char temp[Menu::MAX_LENGTH], *name;
    int nomineeId, nomineeIndex, partyId;
    // input from user
    cout << "\nEnter the name: ";
    cin >> temp;
    cout << "Enter the nominee's ID: ";
    cin >> nomineeId;

    // allocate the name
    name = new char[strlen(temp)];
    strcpy(name, temp);

    // validates that the voter exist
    nomineeIndex = election.findCitizenIdx(nomineeId);
    while (nomineeIndex == -1) {
      cout 
        << BOLDRED << 
        "\nNo citizen with the nominee's id was found" 
        << RESET << "\n\n";

      cout << "Enter the nominee's ID: ";
      cin >> nomineeId;
      nomineeIndex = election.findCitizenIdx(nomineeId);
    }

    // adds the party
    partyId = election.getParties().getLength();
    election.addParty(partyId, name, election.getVoters()[nomineeIndex]);

    // confimation message with the newly created ID (which equal its index)
    cout 
      << BOLDGREEN 
      << "\nParty " << name << " was added with ID: " 
      << partyId
      << RESET << "\n\n";
  } 

  void Menu::vote(Election& election) {
    int voterId, partyId;
    // input from user
    cout << "\nEnter the voter's ID: ";
    cin >> voterId;

    // validates that the voter exist
    int voterIndex = election.findCitizenIdx(voterId);
    while (voterIndex == -1) {
      cout 
        << BOLDRED << 
        "\nThe ID did not match any citizen." 
        << RESET << "\n\n";

      cout << "Enter the member's ID: ";
      cin >> voterId;
      voterIndex = election.findCitizenIdx(voterId);
    }
    // validate that the voter did not vote already
    if (election.getVoters()[voterIndex].getIsVoted()) {
      cout 
        << BOLDRED << 
        "\nThis citizen has already voted before. " 
        << RESET << "\n\n";
      return;
    } 
    // input from user
    partyId = Menu::getPartyIndex(election);
    // cast the vote
    election.vote(election, voterIndex, partyId);
  }

  void Menu::showElectionResults(Election& election) {
    cout 
      << BOLDYELLOW << 
      "-------------------------\n" <<
      "     ELECTION RESULTS    \n" <<
      "-------------------------\n\n";

    Menu::showStatesResults(election);
    Menu::showPartiesResults(election.getParties());
  }

  void Menu::showStatesResults(Election& election) {
    for (int i = 0; i < election.getStates().getLength(); i++) {
      const State& state = election.getStates()[i];
      int winningPartyIdx = state.findPartyWinnerIdx();
      int totalVotesCast = election.getStates()[i].countAllVotes();

      Party& winningParty = election.getParties()[winningPartyIdx];
      // statement on the winner party's nominee of the state
      cout <<
        state.getName() << " gives " <<
        state.getMemberCount() << " members to " <<
        winningParty.getNominee().getName() <<
        "." << endl;

      // update the winning party members won counter
      winningParty.setMembersWonCount(
        winningParty.getMembersWonCount() + state.getMemberCount()
      );
    
      // displays members chosen from all parties
      for (int j = 0; j < election.getParties().getLength(); j++) {
        Party& party = election.getParties()[j];
        int votesCastFromState = state.getVotesByParty()[j];
        // calculate the ratio of votes to determinate how many members were won
        int membersWon = (state.getMemberCount() * (static_cast<float>(votesCastFromState) / totalVotesCast));
        
        // update the party member and voting counters
        party.setVotesCount(party.getVotesCount() + votesCastFromState);

        // print statement about the party voting results in the state
        cout
          << "The " << party.getName() << " got " <<
          votesCastFromState << " votes which are " <<
          Menu::percentage(votesCastFromState, totalVotesCast) <<
          "% of the votes." << endl;
        
        // prints the members that the party won
        if (membersWon > 0) {
          cout << "The members chosen from " << party.getName() << ":\n\n";
          for (int k = 0; k < membersWon && k < party.getMembers()[i].getLength(); k++) {
            cout << party.getMembers()[i][k];
          }
        }
        cout << BOLDYELLOW;
      }
      cout << endl;
    }
  }

  void Menu::showPartiesResults(const PartiesArray& parties) {
    // create an array of the parties indexes sorted by members won
    int * sortedIndexes = new int[parties.getLength()];
    for (int i = 0; i < parties.getLength(); i++) sortedIndexes[i] = i;
    sortParties(sortedIndexes, parties);

    cout 
      << "President elect is " << 
      parties[sortedIndexes[0]].getNominee().getName() 
      << ".\n\n";

    for (int i = 0; i < parties.getLength(); i++) {
      int idx = sortedIndexes[i];

      cout <<
        parties[idx].getName() << " nominee was " <<
        parties[idx].getNominee().getName() << ".\n" <<
        "The " << parties[idx].getName() << " won " <<
        parties[idx].getMembersWonCount() << " members and " <<
        parties[idx].getVotesCount() << " votes.\n\n";
    }
  }

  // -----------------------
  //      helper functions
  // -----------------------

  int Menu::getStateIndex(const Election& election) {
    int stateId;

    cout << "Enter the state ID: ";
    cin >> stateId;

    int statesLength = election.getStates().getLength();
    while ( stateId < 0 || stateId >= statesLength) {
      cout 
        << BOLDRED << 
        "\nInvalid state ID." 
        << RESET << "\n\n";
      
      cout << "Enter the state's id: ";
      cin >> stateId;
    }

    return stateId;
  }

  int Menu::getPartyIndex(const Election& election) {
    int partyId;

    cout << "Enter the party ID: ";
    cin >> partyId;

    int partiesLength = election.getParties().getLength();
    while (partyId < 0 || partyId >= partiesLength) {
      cout 
        << BOLDRED << 
        "\nInvalid party ID." 
        << RESET << "\n\n";
      
      cout << "Enter the party ID: ";
      cin >> partyId;
    }

    return partyId;
  }

  const Citizen Menu::getCitizen(const Election& election) {
    char temp[Menu::MAX_LENGTH], *name;
    int id, birthYear, stateId;

    cout << "\nEnter the name: ";
    cin >> temp;
    cout << "Enter the ID: ";
    cin >> id;
    cout << "Enter year of birth: ";
    cin >> birthYear;

    stateId = Menu::getStateIndex(election);
    
    name = new char[strlen(temp)];
    strcpy(name, temp);

    return Citizen(name, id, birthYear, stateId);
  }

  inline int  Menu::percentage(int part, int whole) {
    return 100 * (static_cast<float>(part) / whole);
  }

  void Menu::sortParties(int * indexes, const PartiesArray& parties) {
    int n = parties.getLength(); 
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n - (1+i); j++) {
        int A = parties[indexes[j]].getMembersWonCount();
        int B = parties[indexes[j+1]].getMembersWonCount();
        if (A < B) { 
          // swap indexes
          int temp = indexes[j]; 
          indexes[j] = indexes[j+1]; 
          indexes[j+1] = temp; 
        } 
      }
    }
  }
}