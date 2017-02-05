
#ifndef RECURSION_H
#define RECURSION_H
int staircase (int steps);
int staircaseTD (int steps);

#include <string>
void subset (const char* set);
void doSubset (const char* set, std::string subset, int idx);

void stringPermutation (const char* s);
void doPermute (const char* s, std::string p);
#endif

