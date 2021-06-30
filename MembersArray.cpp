#include "MembersArray.h"
#include "CitizenArray.h"

namespace proj1 {

  MembersArray::MembersArray(int _length) : length(_length), size(_length) {
    if (this->membersByState != nullptr) 
      delete[] this->membersByState;

    if (length > 0) {
      this->membersByState = new CitizenArray[length];
    }
  }

  MembersArray::MembersArray(const MembersArray& other) 
    : MembersArray::MembersArray(sizeof(other.membersByState) / sizeof(CitizenArray)) 
  {
    for (int i = 0; i < sizeof(other.membersByState) / sizeof(CitizenArray); i++) {
      this->membersByState[i] = CitizenArray(other.membersByState[i]);
    }

    this->length = other.length;
    this->size = other.size;
  }

  MembersArray::~MembersArray() {
    // delete[] membersByState;
  }

  void MembersArray::push(const CitizenArray& members) {
    if (size == length) {
      size = size > 0 ? size * 2 : 1;
      CitizenArray * temp = new CitizenArray[size];

      for (int i = 0; i < length; i++)
        temp[i] = membersByState[i];

      delete[] membersByState;
      membersByState = temp;
    }
    membersByState[length] = members;
    length++;
  }

  void MembersArray::set(int index, const CitizenArray &members) const {
    membersByState[index] = members;
  }

  void MembersArray::set(int index, int length) const {
    membersByState[index] = CitizenArray(length);
  }

  const CitizenArray& MembersArray::get(int index) const {
    return this->membersByState[index];
  }
	int& operator[](int index)
	{
		if (index >= size) {
			cout << "Array index out of bound, exiting";
			exit(0);
		}
		return ptr[index];
	}
};
  ostream& operator<<(ostream& os, const MembersArray& members) {
    for (int i = 0; i < members.length; i++)
      if (members[i].getLength() > 0)
        os << "State #" << i + 1 << "\n\n" << members[i] << endl;
    return os;
  }
}