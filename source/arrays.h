#ifndef ARRAYS_H
#define ARRAYS_H

#include <iostream>
#include <string>

void dumpMatrix (int** m, int rows, int cols);
void rotateSquareMatrix (int** m, int size);
char* compressString (const char* str, int str_len);
std::string compressString (const std::string& s);
void testRotateSquareMatrix (int n);
void testTransformMatrix (int n);
void testCompressString (void);
#endif
