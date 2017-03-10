#include <cassert>
#include <iostream>
#include "trial_stack.h"

TrialStack::TrialStack (int n) {
  arr = new int[n];
  size = n;
  left_bound = right_bound = tos[2] = n/2;
  move_right = true;
  tos[0] = 0;
  tos[1] = n-1;
}

TrialStack::~TrialStack () {
  delete[] arr;
}

void TrialStack::checkPush (int stack) {

  switch (stack) {
  case 1://leftmost stack[0]
    if(left_bound != size/2) assert(tos[0]<=left_bound);
    else assert(tos[0]<=tos[1]);
    break;

  case 2://rightmost stack[1]
    if(right_bound != size/2) assert(tos[1]>=right_bound);
    else assert(tos[1]>=tos[0]);
    break;

  case 3://middle stack[2]
    assert(tos[2] >= tos[0] && tos[2] <= tos[1]);
    break;
  }
}

void TrialStack::checkPop(int stack) {
  switch (stack) {
  case 1://leftmost stack[0]
    assert(tos[0]>0);
    break;

  case 2://rightmost stack[1]
    assert(tos[1]<size-1);
    break;

  case 3://middle stack[2]
    assert(tos[2] != size/2);
    break;
  }
}

void TrialStack::insert (int stack, int x) {
  switch (stack) {
  case 1://leftmost stack[0]
    arr[tos[0]++] = x;
    break;

  case 2://rightmost stack[1]
    arr[tos[1]--] = x;
    break;

  case 3://middle stack[2]
    arr[tos[2]] = x;
  
    if (move_right) { 
      tos[2] = ++right_bound;
      move_right = false;
    }
    else {
      tos[2] = --left_bound;
      move_right = true;
    } 
    break;
  }
}

int TrialStack::remove(int stack) {
  int ret = 0;
  switch (stack) {
  case 1://leftmost stack[0]
    ret = arr[--tos[0]];
      break;

  case 2://rightmost stack[1]
    ret = arr[++tos[1]];
    break;

  case 3://middle stack[2]
    if (move_right) {
      tos[2] = --right_bound;
    }
    else {
      tos[2] = ++left_bound;
    }
    ret =  arr[tos[2]];
    break;
  }
  return ret;
}

void TrialStack::push (int stack, int x) {
  checkPush(stack);
  insert(stack, x);
}

int TrialStack::pop (int stack) {
  checkPop(stack);
  return remove(stack);
}

void testTrialStack (int n) {
  TrialStack stack(n);
  stack.push(1,0);
  stack.push(1,1);
  stack.push(2,2);
  stack.push(2,3);
  stack.push(3,4);
  stack.push(3,5);
  stack.push(3,6);
  for (int i =1; i<=3; ++i) std::cout << stack.pop(i) << " ";
  
}
