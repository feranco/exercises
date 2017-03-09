#include "trial_stack.h"
#include <cassert>

TrialStack::TrialStack (int n) {
  arr = new int[n];
  size = n;
  left_bound = right_bound = n/2;
  move_right = true;
}

~TrialStack::TrialStack () {
  delete[] arr;
}

void TrialStack::push3 (int x) {

  assert(tos3 >= tos1 && tos3 <= tos2);
  arr[tos3] = x;
  
  if (move_right) { 
    tos3 = ++right_bound;
    move_right = false;
  }
  else {
    tos3 = --left_bound;
    move_right = true;
  } 

}

int TrialStack::pop3 (void) {

  assert(tos3 != size/2);
  
  if (move_right) {
    tos = --right_bound;
  }
  else {
    tos = ++left_bound;
  }
  return arr[tos];
}
