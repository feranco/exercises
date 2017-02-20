
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "arrays.h"

void rotateSquareMatrix (int** m, int size) {
  
  int l = 0;
  int r = size-1;

  //run through layers
  for (int k = size; k >= 2; k = k-2) {
    //run through layers pixels
    for (int i = l; i < (r-1); ++i) {
      //int i = j-l;
     //save ith top px
     int tmp = m[l][i];
     
     m[l][i] = m[r-i][l];

     m[r-i][l] = m[r][r-i];

     m[r][r-i] = m[i][r];

     m[i][r] = tmp;
    }
    ++l;
    --r;
  }
}

void testRotateSquareMatrix (int n) {
  srand(time(0));
  int** m;
  m = new int*[n];
  
  for (int i = 0; i < n; ++i) {
    m[i] = new int[n];
    for (int j = 0; j < n; ++j) m[i][j] = rand()%256;
  }

  dumpMatrix(m, n, n);
  std::cout << " -----  " << std::endl;
  rotateSquareMatrix(m, n);
  dumpMatrix(m, n, n);
}

void dumpMatrix (int** m, int rows, int cols) {

  for (int i = 0; i < cols; ++i) {
    for (int j = 0; j < rows; ++j) {
      std::cout << m[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
