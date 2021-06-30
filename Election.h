#pragma once
#include "CitizenArray.h"
#include "PartiesArray.h"
#include "StatesArray.h"

namespace proj1 {
  class Election {
    private:
      CitizenArray voters;
      PartiesArray parties; 
      /* [{"GOP", [{"NY", ["Trump"]}, {"AZ", ["Kamala", "Biden"]}, {}] }] */
      StatesArray states; 
      int day, month, year;
    public:
      Election();
      Election(int _day, int _month, int _year);
      Election(const CitizenArray& voters, const PartiesArray& parties, const StatesArray& states, int _day, int _month, int _year);
      ~Election();

      void vote(Election& election, int voterIndex, int partyId);
      void addState(const State& state); 
      void addParty(int id, char * name, const Citizen& nominee);
      void addMember(int partyId, int stateId, const Citizen& member);
      void addVoter(const Citizen& voter);
      int findCitizenIdx(int id);

      int getDay() const { return day; }
      int getMonth() const { return month; }
      int getYear() const { return year; }
      bool setDay(int _day) { return day = _day; }
      bool setMonth(int _month) { return month = _month; }
      bool setYear(int _year) { return year = _year; }

      const CitizenArray& getVoters() const { return voters; };
      CitizenArray& getVoters() { return voters; };
      void setVoters(const CitizenArray& voters) { this->voters = voters; }

      const PartiesArray& getParties() const { return parties; }
      PartiesArray& getParties() { return parties; }
      void setParties(const PartiesArray& parties) { this->parties = parties; }

      const StatesArray& getStates() const { return states; }
      StatesArray& getStates() { return states; }
      void setStates(const StatesArray& states) { this->states = states; }
  };
}