#pragma once
#include <iostream>

using namespace std;

namespace proj1 {
  class VotesArray {
    private:
      int * arr = nullptr;
      int length = 0;
      int size = 0;
    public:
      explicit VotesArray(int length = 0);
      VotesArray(const VotesArray& other);
      ~VotesArray();

      int getSize() const { return size; }
      int getLength() const { return length; }
      
      void push(int val = 0);
      void set(int index, int val = 0) const;
      const int& get(int index) const;

      int&operator[](int idx) { return arr[idx]; }
      const int&operator[](int idx) const { return arr[idx]; }
  };
}