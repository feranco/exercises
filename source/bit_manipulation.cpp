#include "bit_manipulation.h"
#include <iostream>
#include <bitset>

void clearBitsRange (int& N, int i, int size) {
  //create a mask to clear bit i through i+size
  //s = (1 << size)-1): sequence of 0s with size 1s in lsb
  //s1 = s << i: shift 1s after position i
  //s2 =  ~s1: sequence if 1s + sequence of 0s from bit
  //i through i+size + sequence of 1s fro bit i to lsb
  int mask = ~(((1 << size)-1) << i);
  //clear bits with mask
  N &= mask;
}


void putMintoN (int& M, int& N, int i, int j) {
  //clear bits i through j in N
  clearBitsRange(N, i, j-i+1);
  //update cleared bits with M
  N |= (M << i);
}

void testPutMintoN (void) {
  int m, n;;
  std::cout << "Insert two integers: " << std::endl;
  std::cin >> n >> m;
  std::cout << std::bitset<32>(m) << std::endl;
  std::cout << std::bitset<32>(n) << std::endl;
  putMintoN(m, n, 2, 6);
  std::cout << std::bitset<32>(n) << std::endl;
}
