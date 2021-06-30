#pragma once
#include <iostream>
#include "CitizenArray.h"

using namespace std;

namespace proj1 {
  class MembersArray {
    private:
      CitizenArray * membersByState = nullptr;
      int length = 0;
      int size = 0;
    public:
      explicit MembersArray(int length = 0);
      MembersArray(const MembersArray& other);
      ~MembersArray();

      int getLength() const { return length; }
      
      bool setMembersByState(CitizenArray * _membersByState) { return _membersByState = membersByState; }
      CitizenArray * getMembersByState() const { return membersByState; }

      void push(const CitizenArray &members);
      void set(int index, const CitizenArray &membersByState = CitizenArray()) const;
      void set(int index, int length) const;
      const CitizenArray& get(int index) const;

      CitizenArray&operator[](int idx) { return membersByState[idx]; }
      const CitizenArray&operator[](int idx) const { return membersByState[idx]; }

      friend ostream& operator<<(ostream& os, const MembersArray& members);
  };
}