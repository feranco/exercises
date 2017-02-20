
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

//if m(i,j) = v, set all elements of i-rpw and j-column to v 
void transformMatrix (int** m, int rows, int cols, int v) {
  bool first_row = false, first_col = false;
	
  for (int i = 0; i < cols; ++i) {
    if (m[0][i] == v) {
      first_row = true;
      break;
    } 
  }
	
  for (int i = 0; i < rows; ++i) {
    if (m[i][0] == v) {
      first_col = true;
      break;
    } 
  }
	
  for (int i = 1; i < cols; ++i) {
    for (int j = 1; j < rows; ++j) {
      if (m[i][j] == v) {
	m[i][0] = v;
	m[0][j] = v;
      }
    }
  }
	
  for (int i = 0; i < cols; ++i) {}
  if (m[0][i] == v) {
    for (int j = 1; j < rows; ++j) m[j][i] = v;
  } 
}
	
for (int i = 0; i < rows; ++i) {
  if (m[i][0] == v) {
    for (int j = 1; j < rows; ++j) m[i][j] = v;
  } 
 }
	
if (first_row) {
  for (int i = 0; i < cols; ++i) m[0][i] == v;
 }
	
if (first_col) {
  for (int i = 0; i < rows; ++i) m[i][0] == v;
 }
}

void testTransformMatrix (int n) {
  srand(time(0));
  int** m;
  m = new int*[n];
  
  for (int i = 0; i < n; ++i) {
    m[i] = new int[n];
    for (int j = 0; j < n; ++j) m[i][j] = rand()%256;
  }

  dumpMatrix(m, n, n);
  std::cout << " -----  " << std::endl;
  transformMatrix(m, n);
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
