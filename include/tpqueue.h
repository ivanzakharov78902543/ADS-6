// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
using namespace std;
template<typename T, int size>
class TPQueue {
  private:
    enum { EMPTY = -1, FULL = 999 };
    SYM q[FULL + 1];
    int first;
  public:
     SYM pop() {
        if (IsEmpty())
            return SYM();
        return q[first--];
    }
    bool IsEmpty() {
        return first == EMPTY;
    }
    bool IsFull() {
        return first == FULL;
    }
    void push(const SYM& value) {
        int i;
        for (i = first; i >= 0; i--)
            if (q[i].prior > value.prior)
                break;
        if (IsFull()) {
            if (i != -1) {
                for (int j = 0; j < i; j++)
                    q[j] = q[j + 1];
                q[i] = value;
            }
        } else {
            for (int j = first; j > i; j--)
                q[j + 1] = q[j];

            q[i + 1] = value;
            first++;
        }
    }
};
};
struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
