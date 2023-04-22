// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>
template<typename T, int size>
class TPQueue {
  T* arr;
  int first, last, count;

 public:
  TPQueue(): arr(new T[size]), first(0),last(0),count(0) {}
  void push(const T & value) {
      if (count == size) {
        throw std::string("FULL!");
      }
      ++count;
      int m = last;
      for (int i = first; i < last; i++) {
        if (arr[i].prior < value.prior) {
      m = i;
      break;
    }
      }
      for (int i = last; i > m; i--) {
        arr[i % size] = arr[(i - 1) % size];
      }
      arr[m % size] = value;
      ++last;
    }
    T& pop() {
      if (count == 0) {
        throw std::string("Empty!")
      } else {
         --count;
        return arr[first++ % size];
      }
    }
};
struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
