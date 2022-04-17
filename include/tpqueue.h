// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T arr[size] = { 0 };
    int last, first;
 public:
    void push(T x) {
    int i = last;
    for (; (i >= first) && arr[i % size].prior < x.prior; --i) {
      arr[(i+1) % size] = arr[i % size];
     }
    arr[(i + 1) % size] = x;
     ++last;
  }
    T pop() {
      return arr[(first++) % size];
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
