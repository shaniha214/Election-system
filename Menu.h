#pragma once
#include "Election.h"

// colors codes for console printing
#define RESET       "\033[0m"
#define BOLDRED     "\033[1m\033[31m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDYELLOW  "\033[1m\033[33m"
#define BOLDBLUE    "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"

namespace proj1 {
  class Menu {
    public:
      const static int MAX_LENGTH = 1024;
      void static displayOptions(const Election& election);
      void static displayStates(const Election& election);
      void static displayVoters(const Election& election);
      void static displayParties(const Election& election);

      const Citizen static getCitizen(const Election& election);
      int static getStateIndex(const Election& election);
      int static getPartyIndex(const Election& election);
      
      void static addState(Election& election);
      void static addCitizen(Election& election);
      void static addParty(Election& election);
      void static addMember(Election& election);

      void static vote(Election& election);
      void static showElectionResults(Election& election);
      void static showStatesResults(Election& election);
      void static showPartiesResults(const PartiesArray& parties);

      inline int static percentage(int part, int whole);
      void static sortParties(int * indexes, const PartiesArray& parties);
  };
}