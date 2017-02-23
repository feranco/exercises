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

void setBit (int& num, unsigned int pos) {
  unsigned int mask = 1 << pos;
  num |= mask;
}

void resetBit (int& num, unsigned int pos) {
  unsigned int mask = ~(1 << pos);
  num &= mask;
}

//find the next smallest of num with
//the same numbers of 1s in binary representation
int getNextSmaller (int num) {
  int mask = 1; //mask to find MSb
  int cnt, cnt0 = 0; 
  cnt = cnt0 = 0;

  //skip trailer 1s
  while (((num & mask) == mask) && cnt < 31) {
    mask <<= 1;
    cnt++;
  }

  //flip rightmost non trailer 1 (x) and count how many 0s (c1)
  while (((num & mask) != mask) && (cnt < 31)) {
    mask <<= 1;
    cnt++;
    cnt0++;
  }

  if (cnt < 31) {
    resetBit(num, cnt);
    setBit(num, cnt-cnt0);
    return num;
  }
  else {
    return -1;
  } 
}

//find the next smallest of num with
//the same numbers of 1s in binary representation
int getNextBigger(int num) {
  int mask = 1;//mask to find MSb
  int cnt, cnt1;
  cnt = cnt1 = 0;

  //skip trailer 0s
  while (((num & mask) != mask) && cnt < 31) {
    mask <<= 1;
    cnt++;
  }

  //flip rightmost non trailer 0 (x) and count how many 1s (c1)
  while (((num & mask) == mask) && (cnt < 31)) {
    mask <<= 1;
    cnt++;
    cnt1++;
  }

  if (cnt < 31) {
    setBit(num, cnt);
    //clear bit to the right of x and write c1-1 1s starting from LSb
    int clearMask = ~(mask - 1);
    num &= clearMask;
    int setMask = (1 << (cnt1 - 1)) - 1;
    num |= setMask;
    return num;
  }
  else {
    return -1;
  } 
}


//find the next smallest and the next bigger number of num
//having the same numbers of 1s in binary representation
void findNextMinMax (unsigned int num) {
	
  int next_min, next_max;
	
  next_min =  getNextSmaller(num);   
  next_max =  getNextBigger(num);   
	
  std::cout << "Int: " << num 
	    << " next max " << next_max 
	    << " next min " << next_min 
	    << std::endl;
			  
  std::cout << std::bitset<32>(num) << std::endl;
  std::cout << std::bitset<32>(next_max) << std::endl;
  std::cout << std::bitset<32>(next_min) << std::endl;
	 
}
