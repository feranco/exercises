
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstring>
#include "arrays.h"

//rotate integer matrix by 90 degrees
//rotation implemented in place
//Complexity O(n2)
void rotateSquareMatrix (int** m, int size) {
  
  int l = 0;
  int r = size-1;

  //run through layers
  for (int k = size; k >= 2; k = k-2) {
    //run through layers pixels
    for (int i = l; i < r; ++i) {
     //offset necessary to manage internal layers
     int offset = i-l;

     //save ith top px
     int tmp = m[l][i];
     
     //move left to top
     m[l][i] = m[r-offset][l];
     //move bottom to left
     m[r-offset][l] = m[r][r-offset];
     //move right to bottom
     m[r][r-offset] = m[i][r];
     //move top to right
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

//if m(i,j) = v, set all elements of i-row and j-column to v
//no extra space required
//Complexity O(n2) 
void transformMatrix (int** m, int rows, int cols, int v) {
  bool first_row = false, first_col = false;

  //check if v is in the first row
  for (int i = 0; i < cols; ++i) {
    if (m[0][i] == v) {
      first_row = true;
      break;
    } 
  }

  //check if v is in the first column	
  for (int i = 0; i < rows; ++i) {
    if (m[i][0] == v) {
      first_col = true;
      break;
    } 
  }
	
  //if m(i,j) = v, set m(i,0) = m(0,j) = v
  for (int i = 1; i < cols; ++i) {
    for (int j = 1; j < rows; ++j) {
      if (m[i][j] == v) {
	m[i][0] = v;
	m[0][j] = v;
      }
    }
  }

  //if m(0,i) = v, set i-column to v
  for (int i = 1; i < cols; ++i) {
    if (m[0][i] == v) {
      for (int j = 1; j < rows; ++j) m[j][i] = v;
    } 
  }

  //if m(i,0) = v, set i-row to v	
  for (int i = 0; i < rows; ++i) {
    if (m[i][0] == v) {
      for (int j = 1; j < cols; ++j) m[i][j] = v;
    } 
  }
  
  //set first row to v if required	
  if (first_row) {
    for (int i = 0; i < cols; ++i) m[0][i] = v;
   }
  //set first column to v if required	
  if (first_col) {
    for (int i = 0; i < rows; ++i) m[i][0] = v;
   }
}

void testTransformMatrix (int n) {
  srand(time(0));
  int** m;
  m = new int*[n];
  
  for (int i = 0; i < n; ++i) {
    m[i] = new int[n];
    for (int j = 0; j < n; ++j) m[i][j] = rand()%100;
  }

  dumpMatrix(m, n, n);
  std::cout << " -----  " << std::endl;
transformMatrix(m, n, n, 0);
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

//convert num to a str and put it into str
//return the number of digits of num
int itoa (int num, char* str) {

  char* tmp = str;
  int digits = 0;

  //write num in str in reverse order
  while (num != 0) {
    int rest = num % 10;
    *tmp++ = rest + '0';
    num = num / 10;
    ++digits;
  }
  
  tmp--;
  
  //reverse the string number
  while (str < tmp) {
    char c = *str;
    *str++ = *tmp;
    *tmp-- = c;
  }
  return digits;
}

int countDigits(int num) {
  int digits = 0;
  while (num != 0) {
    num = num / 10;
    ++digits;
  }
  return digits;
}

int compressSize (const char* str) {
  const char* e = str;
  int block_sz, sz;
  block_sz = sz = 0;
  while (*str != 0) {
     while (*e != 0 && *e == *str) {
      ++e;
      ++block_sz;
    }
    int digits = countDigits(block_sz);
    sz += (1 + digits);
    block_sz = 0;
    str = e;
  }
  return sz;
}

//w: ptr to next char of compressed string
//s: ptr to first char of a block
//e: ptr to first char of the next block
char* compressCString(const char* str, int str_len) {
  const char *s, *e;
  char *w;
  int cpr_len = compressSize(str);
  
  if (cpr_len >= str_len) return const_cast<char*>(str);
  
  char* cpr = new char[cpr_len+1];
  	
  w = cpr;
  s = e = str;
	
  int block_len = 0;
	
  //check if all str characters are examined
  while (*s != 0) {
	
    //increase e untill it point the next block of character
    while (*e != 0 && *e == *s) {
      ++e;
      ++block_len;
    } 
	
    //write the character of the current block in the compressed string
    *w++ = *s;
    //write the occurrences of the current character in the compressed string
    int digits = itoa(block_len, w);

    //update counters
    while (digits-- > 0) ++w;
    block_len = 0;
	
    //update s
    s = e;
  }		   
  *w = '\0';
  return cpr;
}

int compressSize (const std::string& str) {
  
  if (str.empty()) return 0;
  int sz = 0;
  int block_sz = 1;
  char c = str.at(0);
  for (std::string::const_iterator it = str.begin()++, end = str.end(); it != end; ++it) {
    if (*it == c) {
      block_sz++;
    }
    else {
      sz += (1 + countDigits(block_sz));
      block_sz = 1;
      c = *it;
    }
  }
  sz += (1 + countDigits(block_sz));
  return sz;
}

std::string compressString (const std::string& s) {
  
  unsigned int cpr_len = compressSize(s);
  std::cout <<cpr_len;
  if (cpr_len >= s.length()) return s;
  
  char* cpr = new char[cpr_len+1];
  char c = s.at(0);
  int block_sz = 1;
  int idx = 0;
  
  for (std::string::const_iterator it = s.begin()++; it != s.end(); ++it) {
    if (*it == c) {
      block_sz++;
    }
    else {
      cpr[idx++] = c;
      int digits = itoa(block_sz, &cpr[idx]);
      idx += digits;
      block_sz = 1;
      c = *it;
    }
  }
  cpr[idx++] = c;
  itoa(block_sz, &cpr[idx]);
  cpr[++idx] = 0;
  return std::string(cpr);
}

void testCompressString(void) {
  std::string str;
  std::cout << "Insert a string: " << std::endl;
  std::cin >> str;
  //char* cstr = new char[str.length()+1];
  //std::strcpy(cstr,str.c_str());
  //char* cpr = compressString(cstr, strlen(cstr));
  //std::string s(cpr);
  //std::cout << s << std::endl;
  std::cout << compressString(str) << std::endl;
}
