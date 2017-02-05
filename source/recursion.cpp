#include "recursion.h"

#define MAX_STEPS 100
int count[MAX_STEPS] = {0};

int staircase (int steps) {
  int* count = new int[steps+1];
  for (int i = 0; i <= steps; ++i) {
    count[i] = 0;
    for (int j = 1; j <= 3; ++j) {
      if ((i-j)>0) {
	count[i] += count[i-j];
      }
      else if ((i-j)==0) {
	count[i]++;
      }
    }
  }
  int res =  count[steps];
  delete[] count;
  return res;
}

int staircaseTD (int steps) {
  if (steps == 3) return 4;
  if (steps == 2) return 2;
  if (steps == 1) return 1;
  if (count[steps] != 0) return count[steps];
  count[steps] = staircaseTD (steps-1) +  staircaseTD (steps-2) +  staircaseTD (steps-3);
  return count[steps];
}

#include <iostream>
#include <cstring>

//generate all possible subsets of the set in input
//assumption: the set is represented as array of char
void subset (const char* set) {
  std::string subset = "";
  doSubset(set, subset, 0);
}

//generate subsets adding recursively an element
//assumption: each subset is represented as a string
//idx is the index of the element added in the current step
void doSubset (const char* set, std::string subset, int idx) {
  for (int i = idx; set[i] != 0; i++) {
    std::cout << subset + set[i] << std::endl;
    doSubset(set, subset + set[i], i+1);
  }
}

//generate all permutation of s
//assumption: s composed of not repeated characters
void stringPermutation(const char* s) {
    std::string p = "";
    for (int i = 0; s[i] != 0; ++i) doPermute(s, p + s[i]);
}

//recursively build a permutation of s
//p is a permuted string of s
//each step add a character of s to p if this was not already in p
void doPermute(const char* s, std::string p) {
    bool neverFound = true;
    for (int i = 0; s[i] != 0; ++i) {
        bool found = false;
        //check if the current character of s is already in p
        if (p.find(s[i])!=std::string::npos) {
            found = true;
        }
        else {
            neverFound = false;
        }
        //if the current character is not in p; add it recursively to p
        if (!found) doPermute(s, p + s[i]);
    }
    //stop condition: all s characters were already in p
    if (neverFound) std::cout << p << std::endl;
}
